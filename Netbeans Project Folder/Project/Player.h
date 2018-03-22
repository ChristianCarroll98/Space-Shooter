#ifndef PLAYER_H
#define PLAYER_H

#include <Entity.h>
#include <FL/Fl.H>

class Player : public Entity {
private:
    int powerLevel;
protected:
    void draw();    
public:
    Player(int X, int Y, int W, int H, int Health = 300, std::string lbl = "player", const char *l=0);
    
    void incPowerLevel();
    int getPowerLevel();
    void setPowerlevel(int p);
};

#endif