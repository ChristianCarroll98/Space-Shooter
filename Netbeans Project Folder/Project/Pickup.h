#ifndef PICKUP_H
#define PICKUP_H

#include <FL/Fl_Widget.H>
#include <string>
#include <functional>
#include <Player.h>

class Pickup : public Fl_Widget {
private:
    int weight;
    std::string type;
    std::function<void(Player*)> efct;
    
protected:
    void draw();
    
    const std::function<void(Player*)> healthUp = [](Player *player){ player->heal(50); };
    
    const std::function<void(Player*)> powerUp = [](Player *player){ player->incPowerLevel(); };
    
public:
    Pickup(int X, int Y, int W, int H, std::string lbl = "pickup", const char *l=0);
    
    void effect(Player *player);
    
    int getWeight();
    
    void setWeight(int w);
};

#endif