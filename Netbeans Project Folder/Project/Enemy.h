#include <Entity.h>
#include <functional>
#include <FL/Fl_Group.H>
#include <cmath>
#include <iostream>

class Enemy : public Entity {
private:
    std::function<void()> mv;
    int dx;
    int dy;
    int hitDamage;
    int initShootTime;
    int shootTime;
    std::string bulletType;
    
protected:
    
    void draw();
    
    const std::function<void()> enemyMove = [&](){
        this->position(this->x()-2, this->y()+0);
    };
    
    const std::function<void()> advEnemyMove = [&](){
        if(!(this->getDy()<0 && this->y() >= 0) && !(this->getDy()>0 && this->y() <= 1080-this->h())) {
            this->setDy(this->getDy()*-1);
        }
        this->position(this->x()+this->getDx(), this->y()+this->getDy());
    };
    
    const std::function<void()> mineMove = [&](){
        /*Entity *target;
        for(int i = 0; i<this->parent()->children()-1; i++){
            if(((Entity*)this->parent()->child(i))->getLabel() == "player"){
                target = (Entity*)this->parent()->child(i);
                break;
            }
        }*/
        
        Entity *target = (Entity*)this->parent()->child(0);
        double dX = target->x()+(target->w()/2) - this->x()-(this->w()/2);
        double dY = target->y()+(target->h()/2) - this->y()-(this->h()/2);
        double hyp = sqrt(dX*dX + dY*dY);
        dY = dY/hyp;
        this->setDy(dY*5);
        this->position(/*this->x()+this->getDx()*/this->x()-3, this->y()+this->getDy());
    };
    
    const std::function<void()> smallEnemyMove = [&](){
        this->position(this->x()-10, this->y()+0);
    };
    
public:
    
    Enemy(int X, int Y, int W, int H, int Health = 100, std::string lbl = "basicEnemy", const char *l=0);
    
    int getDx();
    
    int getDy();
    
    void setDx(int x);
    
    void setDy(int y);
    
    int getHitDmg();
    
    int getInitShootTime();
    
    int getShootTime();
    
    void resetShootTime();
    
    void decShootTime();
    
    std::string getBulletType();
    
    void move();
};