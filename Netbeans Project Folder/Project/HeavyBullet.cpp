#include <HeavyBullet.h>

HeavyBullet::HeavyBullet(int X, int Y, int W, int H, bool isplayer, const char *l) : Bullet(X,Y,W,H,isplayer,l) {
    damage = 20;
}

int HeavyBullet::getDamage(){
    return damage;
}

void HeavyBullet::move(){
    HeavyBulletMove();
}

void HeavyBullet::draw() {
  draw_box();
  draw_label();
}