#include <Entity.h>

Entity::Entity(int X, int Y, int W, int H, int h, std::string lbl, const char *l) : Fl_Widget(X,Y,W,H,l) {
    health = h;
    maxHealth = h;
    dead = false;
    label = lbl;
}

void Entity::setMaxHealth(int h){
    maxHealth = h;
}

int Entity::getMaxHealth(){
   return maxHealth; 
}

int Entity::getHealth(){
    return health;
}
    
void Entity::setHealth(int h){
    health = h;
    if(h>0)
        dead = false;
}

void Entity::hurt(int d){
    if(health>d){
        health-=d;
    }else{
        dead = true;
    }
}
    
void Entity::heal(int h){
    if(health+h < maxHealth){
        health+=h;
    }else{
        health = maxHealth;
    }
}

bool Entity::isDead(){
    return dead;
}

std::string Entity::getLabel(){
    return label;
}

void Entity::draw() {
  draw_box();
  draw_label();
}