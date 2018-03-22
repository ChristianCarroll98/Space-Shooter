#include <Bullet.h>

class FastBullet : public Bullet {
private:
    int damage;
    bool isPlayer;
    
protected:
    void draw();
    
public:
    FastBullet(int X, int Y, int W, int H, bool isplayer, const char *l=0);
    
    int getDamage();
    
    void move();
};