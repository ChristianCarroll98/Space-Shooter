#include <Player.h>
#include <FL/fl_draw.H>

Player::Player(int X, int Y, int W, int H, int h, std::string lbl, const char *l) : Entity(X,Y,W,H,h,lbl,l) {
    powerLevel = 1;
}

void Player::incPowerLevel(){
    if(powerLevel<6){
        powerLevel++;
    }
}

int Player::getPowerLevel(){
    return powerLevel;
}

void Player::setPowerlevel(int p){
    powerLevel = p;
}

void Player::draw() {
    draw_box();
    draw_label();
    fl_color(FL_GREEN);
    fl_rectf(this->x()+this->w()/2-(this->w()*this->getHealth()/this->getMaxHealth())/2, this->y()+this->h()+10, this->w()*this->getHealth()/this->getMaxHealth(), 5);
}