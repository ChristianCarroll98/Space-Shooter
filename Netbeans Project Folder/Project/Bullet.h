#ifndef BULLET_H
#define BULLET_H

#include <FL/Fl_Widget.H>
#include <functional>

class Bullet : public Fl_Widget {
private:
    int damage;
    bool player;
    std::string type;
    std::function<void()> mv;
    
protected:
    void draw();
    
    const std::function<void()> FastBulletMove = [&](){this->position(this->x()+10, this->y()+0);};
    
    const std::function<void()> HeavyBulletMove = [&](){this->position(this->x()+6, this->y()+0);};
    
    const std::function<void()> StraightBulletMove = [&](){this->position(this->x()+12, this->y()+0);};
    
    const std::function<void()> AngleUpBulletMove = [&](){this->position(this->x()+12, this->y()-1);};
    
    const std::function<void()> AngleDownBulletMove = [&](){this->position(this->x()+12, this->y()+1);};
    
    const std::function<void()> EnemyBulletMove = [&](){this->position(this->x()-5, this->y()+0);};
    
public:
    Bullet(int X, int Y, int W, int H, bool isplayer, std::string tp, const char *l=0);
    
    int getDamage();
    
    void move();
    
    bool isPlayer();
};

#endif