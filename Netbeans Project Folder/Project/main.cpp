#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_PNG_Image.H>
#include <FL/Fl_Group.H>
#include <iostream>
#include <Enemy.h>
#include <Player.h>
#include <Bullet.h>
#include <cmath>
#include <time.h>
#include <cstdlib>
#include <Pickup.h>
#include <vector>
#include <Level.h>
#include <FL/Fl_Button.H>

//global vars
enum GameState { MENU, HELP, PLAY, POPUP, PAUSE, WIN, GAMEOVER, QUIT, };
GameState GAMESTATE;

int buttonWidth = 200;
int buttonHeight = 50;

std::vector<std::vector<Level>> level;

int curWorld;
int curLevel;

std::vector<Fl_PNG_Image*> worldImgs;

//various counting variables
unsigned int moveStars;
unsigned int shootTimer;
unsigned int spawnEnemy;

unsigned int winTimer;
int winTime;

Fl_Double_Window *window; // create double-buffered window

//background image
Fl_Box *backgroundImg;
Fl_PNG_Image *img;

//back layer of stars image
Fl_Box *bgS;
Fl_PNG_Image *img2;

//front layer of stars image
Fl_Box *fgS;
Fl_PNG_Image *img3;

//PLAY WIDGETS
Fl_Group *playGroup;
    Fl_Group *bulletGroup;
    Fl_Group *explosionGroup;
    Fl_Group *pickupGroup;
    Fl_Group *entityGroup;
    Player *player;
    Fl_PNG_Image *shipImg;
    Fl_Box *line;
    Fl_Box *shipIcon;
    Fl_PNG_Image *img4;
    Fl_Button* playPauseButton;

//MAIN MENU WIDGETS
Fl_Group *mainMenuGroup;
    Fl_Button* menuPlayButton;
    Fl_Button* menuQuitButton;
    
//GAMEOVER WIDGETS
Fl_Group *gameoverGroup;
    Fl_Button* gameoverMenuButton;

Fl_Group *pauseGroup;
    Fl_Button* pauseMenuButton;
    Fl_Button* pauseResumeButton;
    
Fl_Group *winGroup;
    Fl_Button* winMenuButton;
    Fl_Button* winNextButton;

void resetGame(){
    for(int i = 0; i<pickupGroup->children(); i++){
        Fl::delete_widget(pickupGroup->child(i));
    }
    for(int i = 1; i<entityGroup->children(); i++){
        Fl::delete_widget(entityGroup->child(i));
    }
    for(int i = 0; i<bulletGroup->children(); i++){
        Fl::delete_widget(bulletGroup->child(i));
    }
    player->position(300,400);
    winTimer = 0;
    moveStars = 0;
    shootTimer = 0;
    spawnEnemy = 0;
    std::srand(time(NULL));
    player->setHealth(player->getMaxHealth());
    player->setPowerlevel(1);
    backgroundImg->image(worldImgs.at(curWorld));
}
    
void changeState(GameState STATE){
    switch(STATE) {
        case MENU :{
            curWorld = 0;
            curLevel = 0;
            resetGame();
            GAMESTATE = MENU;
            playGroup->hide();
            gameoverGroup->hide();
            mainMenuGroup->show();
            pauseGroup->hide();
            winGroup->hide();
        }break;
        case HELP :{
            GAMESTATE = HELP;
            playGroup->hide();
            gameoverGroup->hide();
            mainMenuGroup->hide();
            pauseGroup->hide();
            winGroup->hide();
        }break;
        case PLAY :{
            GAMESTATE = PLAY;
            playGroup->show();
            pauseGroup->hide();
            gameoverGroup->hide();
            mainMenuGroup->hide();
            winGroup->hide();
        }break;
        case PAUSE :{
            GAMESTATE = PAUSE;
            playGroup->hide();
            gameoverGroup->hide();
            mainMenuGroup->hide();
            pauseGroup->show();
            winGroup->hide();
        }break;
        case WIN :{
            curLevel++;
            GAMESTATE = WIN;
            playGroup->hide();
            gameoverGroup->hide();
            mainMenuGroup->hide();
            pauseGroup->hide();
            winGroup->show();
        }break;
        case GAMEOVER :{
            GAMESTATE = GAMEOVER;
            playGroup->hide();
            gameoverGroup->show();
            mainMenuGroup->hide();
            pauseGroup->hide();
            winGroup->hide();
        }break;
        case QUIT :{
            GAMESTATE = QUIT;
            playGroup->hide();
            gameoverGroup->hide();
            mainMenuGroup->hide();
            pauseGroup->hide();
            winGroup->hide();
        }break;
        default:
            break;
    }
}
    
//callbacks
void menuPlayButton_cb( Fl_Widget* obj , void* ){
    if(!Fl::get_key(32))
        changeState(PLAY);
}

void gameoverMenuButton_cb( Fl_Widget* obj , void* ){
    if(!Fl::get_key(32))
        changeState(MENU);
}

void playPauseButton_cb( Fl_Widget* obj , void* ){
    if(!Fl::get_key(32))
        changeState(PAUSE);
}

void pauseMenuButton_cb( Fl_Widget* obj , void* ){
    if(!Fl::get_key(32))
        changeState(MENU);
}

void pauseResumeButton_cb( Fl_Widget* obj , void* ){
    if(!Fl::get_key(32))
        changeState(PLAY);
}

void menuQuitButton_cb( Fl_Widget* obj , void* ){
    if(!Fl::get_key(32))
        changeState(QUIT);
}

void winMenuButton_cb( Fl_Widget* obj , void* ){
    if(!Fl::get_key(32))
        changeState(MENU);
}

void winNextButton_cb( Fl_Widget* obj , void* ){
    if(!Fl::get_key(32)){
        changeState(PLAY);
        resetGame();
    }
}

void init(){
    
    moveStars = 0;
    shootTimer = 0;
    spawnEnemy = 0;
    
    winTimer = 0;
    winTime = 2000;//10000
    
    std::srand(time(NULL));
    
    curWorld = 0;
    curLevel = 0;
    
    {std::vector<Level> world0;
    level.push_back(world0);}//world 0
    {std::vector<Level> world1;
    level.push_back(world1);}//world 1
    
    level.at(0).push_back(Level(10, {"basicEnemy", "smallEnemy"}));//world 1 level 1
    level.at(0).push_back(Level(10, {"basicEnemy", "advancedEnemy", "smallEnemy"}));//world 1 level 2
    level.at(1).push_back(Level(10, {"basicEnemy", "advancedEnemy", "mine"}));//world 2 level 1
    
    worldImgs.push_back(new Fl_PNG_Image{"world00.png"});
    worldImgs.push_back(new Fl_PNG_Image{"world01.png"});
    
    window = new Fl_Double_Window(1080,1920); // create double-buffered window
        
        //background image
        backgroundImg = new Fl_Box(0, 0, 1920, 1080);
        img = worldImgs.at(curWorld);
        backgroundImg->image(img);
        
        //back layer of stars image
        bgS = new Fl_Box(0, 0, 3840, 1080);
        img2 = new Fl_PNG_Image{"backStars.png"};
        bgS->image(img2);
        
        //front layer of stars image
        fgS = new Fl_Box(0, 0, 3840, 1080);
        img3 = new Fl_PNG_Image{"frontStars.png"};
        fgS->image(img3);
        
    window->end();
    window->fullscreen();
    
    playGroup = new Fl_Group(0,0,1080,1920);
        
        Fl_Box *line = new Fl_Box(100, 1030, 1720, 4);
        line->box(FL_UP_BOX);
        
        shipIcon = new Fl_Box(100, 1017, 46, 26);
        img4 = new Fl_PNG_Image{"shipIcon.png"};
        shipIcon->image(img4);
    
        bulletGroup = new Fl_Group(0, 0, 1920, 1080);
        bulletGroup->end();
        //explosionGroup = new Fl_Group(0, 0, 1920, 1080);
        pickupGroup = new Fl_Group(0, 0, 1920, 1080);
        pickupGroup->end();
        
        playPauseButton = new Fl_Button( 10, 10, buttonWidth/2, buttonHeight/2, "PAUSE" );
        playPauseButton->callback((Fl_Callback*) playPauseButton_cb );
    
    playGroup->end();
    window->add(playGroup);
    
    entityGroup = new Fl_Group(0,0,1080,1920);
        player = new Player(300, 400, 228, 130);
        shipImg = new Fl_PNG_Image{"ship.png"};
        player->image(shipImg);
    entityGroup->end();
    playGroup->add(entityGroup);
    
    mainMenuGroup = new Fl_Group(0,0,1080,1920);
        menuPlayButton = new Fl_Button( window->h()/2-buttonWidth/2, window->w()/2-buttonHeight/2-buttonHeight/2-10, buttonWidth, buttonHeight, "PLAY" );
        menuPlayButton->callback((Fl_Callback*) menuPlayButton_cb );
        menuQuitButton = new Fl_Button( window->h()/2-buttonWidth/2, window->w()/2-buttonHeight/2+buttonHeight/2+10, buttonWidth, buttonHeight, "QUIT" );
        menuQuitButton->callback((Fl_Callback*) menuQuitButton_cb );
    mainMenuGroup->end();
    window->add(mainMenuGroup);
    
    gameoverGroup = new Fl_Group(0,0,1080,1920);
        gameoverMenuButton = new Fl_Button( window->h()/2-buttonWidth/2, window->w()/2-buttonHeight/2, buttonWidth, buttonHeight, "GAME OVER\nRETURN TO MENU" );
        gameoverMenuButton->callback((Fl_Callback*) gameoverMenuButton_cb );
    gameoverGroup->end();
    window->add(gameoverGroup);
    
    pauseGroup = new Fl_Group(0,0,1080,1920);
        pauseMenuButton = new Fl_Button( window->h()/2-buttonWidth/2, window->w()/2-buttonHeight/2-buttonHeight/2-10, buttonWidth, buttonHeight, "MENU" );
        pauseMenuButton->callback((Fl_Callback*) pauseMenuButton_cb );
        pauseResumeButton = new Fl_Button( window->h()/2-buttonWidth/2, window->w()/2-buttonHeight/2+buttonHeight/2+10, buttonWidth, buttonHeight, "RESUME" );
        pauseResumeButton->callback((Fl_Callback*) pauseResumeButton_cb );
    pauseGroup->end();
    window->add(pauseGroup);
    
    winGroup = new Fl_Group(0,0,1080,1920);
        winMenuButton = new Fl_Button( window->h()/2-buttonWidth/2, window->w()/2-buttonHeight/2-buttonHeight/2-10, buttonWidth, buttonHeight, "MENU" );
        winMenuButton->callback((Fl_Callback*) winMenuButton_cb );
        winNextButton = new Fl_Button( window->h()/2-buttonWidth/2, window->w()/2-buttonHeight/2+buttonHeight/2+10, buttonWidth, buttonHeight, "NEXT LEVEL" );
        winNextButton->callback((Fl_Callback*) winNextButton_cb );
    winGroup->end();
    window->add(winGroup);
    
    changeState(MENU);
    
    window->show();
}

int rand(int min, int max){
    max++;
    return (int)(min+(std::rand() % (max-min)));
}

void move(Fl_Widget *obj, int x, int y){
    obj->position(obj->x()+x, obj->y()+y);
}

bool collisionCheck(Fl_Widget *obj1, Fl_Widget *obj2){
    if((obj1->x()+obj1->w() > obj2->x()) &&
       (obj1->x() < obj2->x()+obj2->w()) &&
       (obj1->y()+obj1->h() > obj2->y()) &&
       (obj1->y() < obj2->y()+obj2->h())){
        return true;
    }
    return false;
}

void popUp(int x, int y, std::string text){
    //message("hello!");
}

int main(int argc, char **argv) {
    
    init();
    
    while(Fl::wait()){
        
        moveStars++;
        if(moveStars%2 == 0){ //moves front stars every 2 loops
            fgS->position(fgS->x()-1,fgS->y());
        }
        if(moveStars%5 == 0){ //moves back stars every 5 loops
            bgS->position(bgS->x()-1,bgS->y());
        }
        
        //reset position of star images for seamless infinite scrolling
        if(fgS->x()<=-1920){
            fgS->position(0,fgS->y());
        }
        if(bgS->x()<=-1920){
            bgS->position(0,bgS->y());
        }
        
        if(GAMESTATE == MENU){
            
            //quit, play, help
            
        }
        
        else if(GAMESTATE == HELP){
            
            //menu
            
        }
        
        else if(GAMESTATE == PLAY){
            
            winTimer++;
        
            if(winTimer<winTime){
                shipIcon->position(100+((1720-shipIcon->w())*winTimer/winTime), shipIcon->y());
            }else{
                changeState(WIN);
            }
            
            //move player (WASD)
            if(Fl::get_key(87)){
                if(player->y() > 0)
                    move(player, 0, -5);
            }
            if(Fl::get_key(83)){
                if(player->y()+player->h() < 1080)
                    move(player, 0, 5);
            }
            if(Fl::get_key(65)){
                if(player->x() > 0)
                    move(player, -5, 0);
            }
            if(Fl::get_key(68)){
                if(player->x()+player->w() < 1920)
                    move(player, 5, 0);
            }
            
            if(Fl::event_key(32)){ //checks for space bar, shoots. shootTimer creates delay of 10 loops
                if(shootTimer >= 10){

                    if(player->getPowerLevel()==1){
                        {Bullet *bullet = new Bullet(player->x()+player->w(),player->y()+player->h()/2-5, 30, 10, true, "StraightBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                    }else if(player->getPowerLevel()==2){
                        {Bullet *bullet = new Bullet(player->x()+player->w(),player->y()+player->h()/2-15, 30, 10, true, "StraightBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                        {Bullet *bullet = new Bullet(player->x()+player->w(),player->y()+player->h()/2+5, 30, 10, true, "StraightBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                    }else if(player->getPowerLevel()==3){
                        {Bullet *bullet = new Bullet(player->x()+player->w()-10,player->y()+player->h()/2-25, 30, 10, true, "StraightBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                        {Bullet *bullet = new Bullet(player->x()+player->w(),player->y()+player->h()/2-5, 30, 10, true, "StraightBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                        {Bullet *bullet = new Bullet(player->x()+player->w()-10,player->y()+player->h()/2+15, 30, 10, true, "StraightBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                    }else if(player->getPowerLevel()==4){
                        {Bullet *bullet = new Bullet(player->x()+player->w()-10,player->y()+player->h()/2-35, 30, 10, true, "StraightBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                        {Bullet *bullet = new Bullet(player->x()+player->w(),player->y()+player->h()/2-15, 30, 10, true, "StraightBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                        {Bullet *bullet = new Bullet(player->x()+player->w(),player->y()+player->h()/2+5, 30, 10, true, "StraightBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                        {Bullet *bullet = new Bullet(player->x()+player->w()-10,player->y()+player->h()/2+25, 30, 10, true, "StraightBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                    }else if(player->getPowerLevel()==5){
                        {Bullet *bullet = new Bullet(player->x()+player->w()-10,player->y()+player->h()/2-25, 30, 10, true, "AngleUpBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                        {Bullet *bullet = new Bullet(player->x()+player->w()-10,player->y()+player->h()/2-25, 30, 10, true, "StraightBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                        {Bullet *bullet = new Bullet(player->x()+player->w(),player->y()+player->h()/2-5, 30, 10, true, "StraightBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                        {Bullet *bullet = new Bullet(player->x()+player->w()-10,player->y()+player->h()/2+15, 30, 10, true, "StraightBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                        {Bullet *bullet = new Bullet(player->x()+player->w()-10,player->y()+player->h()/2+15, 30, 10, true, "AngleDownBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                    }else if(player->getPowerLevel()==6){
                        {Bullet *bullet = new Bullet(player->x()+player->w()-10,player->y()+player->h()/2-35, 30, 10, true, "AngleUpBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                        {Bullet *bullet = new Bullet(player->x()+player->w()-10,player->y()+player->h()/2-35, 30, 10, true, "StraightBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                        {Bullet *bullet = new Bullet(player->x()+player->w(),player->y()+player->h()/2-15, 30, 10, true, "StraightBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                        {Bullet *bullet = new Bullet(player->x()+player->w(),player->y()+player->h()/2+5, 30, 10, true, "StraightBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                        {Bullet *bullet = new Bullet(player->x()+player->w()-10,player->y()+player->h()/2+25, 30, 10, true, "StraightBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                        {Bullet *bullet = new Bullet(player->x()+player->w()-10,player->y()+player->h()/2+25, 30, 10, true, "AngleDownBullet");
                        Fl_PNG_Image *blt = new Fl_PNG_Image{"testbullet.png"};
                        bullet->image(blt);
                        bulletGroup->add(bullet);}
                    }

                    shootTimer = 0;
                }
            }
            shootTimer++;
            
            if(spawnEnemy == 200){
                
                std::string enemyString = level[curWorld][curLevel].getRandomEnemy();
                
                Enemy *enemy;
                Fl_PNG_Image *enemyImg;

                if(enemyString == "advancedEnemy"){
                    enemy = new Enemy(2000,rand(0, 940),230,120, 200, "advancedEnemy");
                    enemyImg = new Fl_PNG_Image{"advancedAlien.png"};
                }else if(enemyString == "mine"){
                    enemy = new Enemy(2000,rand(0, 1000), 80, 80, 100, "mine");
                    enemyImg = new Fl_PNG_Image{"mine.png"};
                }else if(enemyString == "smallEnemy"){
                    enemy = new Enemy(2000,rand(0, 994), 150, 86, 50, "smallEnemy");
                    enemyImg = new Fl_PNG_Image{"smallAlien.png"};
                }else if(enemyString == "basicEnemy"){
                    enemy = new Enemy(2000,rand(0, 940), 200, 120, 100, "basicEnemy");
                    enemyImg = new Fl_PNG_Image{"basicAlien.png"};
                }else{
                    std::cout<<"ERROR! NO ENEMY SPAWNED\n";
                }
                
                enemy->image(enemyImg);
                entityGroup->add(enemy);
                
                spawnEnemy = 0;
            }
            spawnEnemy++;
            
            for(int i = 0; i<entityGroup->children(); i++){
                Entity *entity = (Entity*)entityGroup->child(i);

                if(entity->getLabel() == "enemy"){
                    Enemy *enemy = (Enemy*)entity;

                    enemy->move();

                    if(enemy->getInitShootTime()!=0){
                        if(enemy->getShootTime()<=0){
                            if(enemy->getBulletType() == "EnemyBullet"){
                                {Bullet *bullet = new Bullet(enemy->x(),enemy->y()+enemy->h()/2, 21, 9, false, enemy->getBulletType());
                                Fl_PNG_Image *blt = new Fl_PNG_Image{"EnemyBullet2.png"};
                                bullet->image(blt);
                                bulletGroup->add(bullet);}
                                {Bullet *bullet = new Bullet(enemy->x()+30,enemy->y()+enemy->h()/2, 21, 9, false, enemy->getBulletType());
                                Fl_PNG_Image *blt = new Fl_PNG_Image{"EnemyBullet2.png"};
                                bullet->image(blt);
                                bulletGroup->add(bullet);}
                                {Bullet *bullet = new Bullet(enemy->x()+60,enemy->y()+enemy->h()/2, 21, 9, false, enemy->getBulletType());
                                Fl_PNG_Image *blt = new Fl_PNG_Image{"EnemyBullet2.png"};
                                bullet->image(blt);
                                bulletGroup->add(bullet);}
                                {Bullet *bullet = new Bullet(enemy->x()+90,enemy->y()+enemy->h()/2, 21, 9, false, enemy->getBulletType());
                                Fl_PNG_Image *blt = new Fl_PNG_Image{"EnemyBullet2.png"};
                                bullet->image(blt);
                                bulletGroup->add(bullet);}
                                {Bullet *bullet = new Bullet(enemy->x()+120,enemy->y()+enemy->h()/2, 21, 9, false, enemy->getBulletType());
                                Fl_PNG_Image *blt = new Fl_PNG_Image{"EnemyBullet2.png"};
                                bullet->image(blt);
                                bulletGroup->add(bullet);}
                                enemy->resetShootTime();
                            }
                        }else{
                            enemy->decShootTime();
                        }
                    }

                    if(collisionCheck(player, enemy)){
                        player->hurt(enemy->getHitDmg());
                        Fl::delete_widget(enemy);
                    }

                    if(enemy->x()+enemy->w() < 0){
                        Fl::delete_widget(enemy);
                    }

                    else if(player->isDead()){
                        changeState(GAMEOVER);
                    }
                }
            }
            
            for(int i = 0; i<pickupGroup->children(); i++){
                Pickup *pickup = (Pickup*)pickupGroup->child(i);
                if(collisionCheck(player, pickup)){
                    pickup->effect(player);
                }else{
                    if(pickup->x()+pickup->w() < 0){
                        Fl::delete_widget(pickup);
                    }else
                        move(pickup, -1, 0);
                }
            }
            
            for(int i = 0; i<bulletGroup->children(); i++){ //iterate through bullets
            
                Bullet *bullet = (Bullet*)bulletGroup->child(i); //create pointer to the current bullet for ease of access

                bullet->move(); //handle bullet movement

                if(bullet->x()>window->w() || bullet->x()+bullet->w()<0)    //if bullets leave screen,
                    Fl::delete_widget(bullet); //delete them.

                else{
                    for(int j = 0; j<entityGroup->children(); j++){

                        Entity *entity = (Entity*)entityGroup->child(j); //create pointer to the current entity for ease of access

                        if(collisionCheck(bullet, entity)){ //check collisions between bullets and enemies

                            if(bullet->isPlayer()){ //if the player shot this bullet

                                if(entity->getLabel() == "enemy"){ // if colliding with an enemy
                                    Enemy *enemy = (Enemy*)entity; // cast entity pointer as enemy

                                    enemy->hurt(bullet->getDamage()); //damage an enemy if hit
                                    //move(enemy, bullet->getDamage(), 0); //(show damage)

                                    if(enemy->isDead()){ //"kill" the enemy if it runs out of health.
                                        Fl::delete_widget(enemy);   // removes it from group.
                                        
                                        //popUp(20,20,"");
                                        
                                        
                                        /*if(((int)rand())%2 == 0){
                                            dy = -2;
                                        }else{
                                            dy = 2;
                                        }*/
                                        
                                        int random = rand(0, 100);
                                        //if(level[curWorld][curLevel].)
                                        if(random >= 0 && random <= 50){
                                            {Pickup *healthUp = new Pickup(enemy->x()+enemy->w()/2-32,enemy->y()+enemy->h()/2-32, 64, 64, "healthUp");
                                            Fl_PNG_Image *img = new Fl_PNG_Image{"HealthUp.png"};
                                            healthUp->image(img);
                                            pickupGroup->add(healthUp);}
                                        }else if(random > 50 && random <= 100){
                                            {Pickup *healthUp = new Pickup(enemy->x()+enemy->w()/2-32,enemy->y()+enemy->h()/2-32, 64, 64, "powerUp");
                                            Fl_PNG_Image *img = new Fl_PNG_Image{"PowerUp.png"};
                                            healthUp->image(img);
                                            pickupGroup->add(healthUp);}
                                        }
                                        
                                    }

                                    Fl::delete_widget(bullet); //deletes the bullet when it collides with an object
                                }

                            }else{ // if enemy bullet

                                if(entity->getLabel() == "player"){ // if colliding with player
                                    Player *player = (Player*)entity; // cast entity pointer as player

                                    player->hurt(bullet->getDamage()); //damage player if hit by enemy

                                    if(player->isDead()){
                                        changeState(GAMEOVER);
                                    }

                                    Fl::delete_widget(bullet); //deletes the bullet when it collides with an object
                                }
                            }
                        }
                    }
                }
            }
            
            //pause
        }
        
        else if(GAMESTATE == POPUP){
            
            //menu or resume
            
        }
        
        else if(GAMESTATE == PAUSE){
            
            //menu or resume
            
        }
        
        else if(GAMESTATE == WIN){
            
            if(level.at(curWorld).size() == curLevel){
                curWorld++;
                curLevel = 0;
            }
            
            if(level.size() == curWorld){
                changeState(GAMEOVER);
            }
            
        }
        
        else if(GAMESTATE == GAMEOVER){
            
            
            
            //menu or quit
            
        }
        
        else if(GAMESTATE == QUIT){
            
            window->hide();
            
        }
        window->redraw();
    }
    //close files and stuff, end of program
}