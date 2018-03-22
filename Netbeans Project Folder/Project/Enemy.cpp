#include <Enemy.h>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <FL/fl_draw.H>

Enemy::Enemy(int X, int Y, int W, int H, int h, std::string lbl, const char *l) : Entity(X,Y,W,H,h,"enemy",l) {
    
    dx = 0;
    dy = 0;
    
    if(lbl == "basicEnemy"){
        mv = enemyMove;
        hitDamage = 100;
        initShootTime = 0;
        
    }else if(lbl == "advancedEnemy"){
        dx = -1;
        std::srand(time(NULL));
        if(((int)rand())%2 == 0){
            dy = -2;
        }else{
            dy = 2;
        }
        mv = advEnemyMove;
        hitDamage = 100;
        initShootTime = 300;
        bulletType = "EnemyBullet";
        
    }else if(lbl == "smallEnemy"){
        mv = smallEnemyMove;
        hitDamage = 100;
        initShootTime = 0;
    }else if(lbl == "mine"){
        mv = mineMove;
        hitDamage = 150;
        initShootTime = 0;
    }else{
        std::cout<<"ERROR! INVALID ENEMY LABEL\n";
    }
    
    shootTime = initShootTime;
}

void Enemy::move(){
    mv();
}

int Enemy::getDx(){
    return dx;
}
    
int Enemy::getDy(){
    return dy;
}

void Enemy::setDx(int x){
    dx = x;
}
    
void Enemy::setDy(int y){
    dy = y;
}

int Enemy::getHitDmg(){
    return hitDamage;
}

int Enemy::getInitShootTime(){
    return initShootTime;
}

int Enemy::getShootTime(){
    return shootTime;
}
    
void Enemy::resetShootTime(){
    shootTime = initShootTime;
}

void Enemy::decShootTime(){
    shootTime--;
}

std::string Enemy::getBulletType(){
    return bulletType;
}

void Enemy::draw() {
  draw_box();
  draw_label();
  fl_color(FL_RED);
  fl_rectf(this->x()+this->w()/2-(this->w()*this->getHealth()/this->getMaxHealth())/2, this->y()+this->h()+10, this->w()*this->getHealth()/this->getMaxHealth(), 5);
}