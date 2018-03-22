#include <Bullet.h>
#include <iostream>

Bullet::Bullet(int X, int Y, int W, int H, bool isplayer, std::string tp, const char *l) : Fl_Widget(X,Y,W,H,l) {
    player = isplayer;
    type = tp;
    if(type == "FastBullet"){
        damage = 4;
        mv = FastBulletMove;
    }else if(type == "HeavyBullet"){
        damage = 20;
        mv = HeavyBulletMove;
    }
    if(type == "StraightBullet"){
        damage = 4;
        mv = StraightBulletMove;
    }else if(type == "AngleUpBullet"){
        damage = 4;
        mv = AngleUpBulletMove;
    }else if(type == "AngleDownBullet"){
        damage = 4;
        mv = AngleDownBulletMove;
    }else if(type == "EnemyBullet"){
        damage = 10;
        mv = EnemyBulletMove;
    }else{
        std::cout<<"ERROR! INVALID BULLET LABEL\n";
    }
}

int Bullet::getDamage(){
    return damage;
}

void Bullet::move(){
    mv();
}

bool Bullet::isPlayer(){
    return player;
}

void Bullet::draw() {
    draw_box();
    draw_label();
}