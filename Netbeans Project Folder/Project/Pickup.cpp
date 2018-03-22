#include <Pickup.h>
#include <Player.h>

Pickup::Pickup(int X, int Y, int W, int H, std::string lbl, const char *l) : Fl_Widget(X,Y,W,H,l){
    type = lbl;
    if(lbl == "healthUp"){
        efct = healthUp;
        weight = 3;
    }else if(lbl == "powerUp"){
        efct = powerUp;
        weight = 2;
    }
}
    
void Pickup::effect(Player *player){
    Fl::delete_widget(this);
    efct(player);
}

int Pickup::getWeight(){
    return weight;
}
    
void Pickup::setWeight(int w){
    weight = w;
}

void Pickup::draw(){
    draw_box();
    draw_label();
}