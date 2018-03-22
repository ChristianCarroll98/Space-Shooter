#include <Bullet.h>

class HeavyBullet : public Bullet {
private:
    int damage;
    bool isPlayer;
    
protected:
    void draw();
    
public:
    HeavyBullet(int X, int Y, int W, int H, bool isplayer, const char *l=0);
    
    int getDamage();
    
    void move();
};