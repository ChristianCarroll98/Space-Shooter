#include <FastBullet.h>

FastBullet::FastBullet(int X, int Y, int W, int H, bool isplayer, const char *l) : Bullet(X,Y,W,H,isplayer,l) {
    damage = 4;
}

int FastBullet::getDamage(){
    return damage;
}

void FastBullet::move(){
    FastBulletMove();
}

void FastBullet::draw() {
  draw_box();
  draw_label();
}