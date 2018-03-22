#ifndef ENTITY_H
#define ENTITY_H

#include <FL/Fl_Widget.H>
#include <string>

class Entity : public Fl_Widget {
private:
    int health;
    int maxHealth;
    bool dead;
    std::string label;
    
protected:
    void draw();
    
public:    
    Entity(int X, int Y, int W, int H, int Health=100, std::string lbl = "entity", const char *l=0);
    
    void setMaxHealth(int h);
    
    int getMaxHealth();
    
    int getHealth();
    
    void setHealth(int h);
    
    void hurt(int d);
    
    void heal(int h);
    
    std::string getLabel();
    
    bool isDead();
};

#endif