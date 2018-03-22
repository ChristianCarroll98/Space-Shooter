#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <FL/Fl_Widget.H>
#include <string>

class Explosion : public Fl_Widget {
private:
    bool done;
    int xFrames;
    int yFrames; //w and h are assumed to be the width and heighth of each frame
    int curFrameX;
    int curFrameY;
    int lastFrame;
    int initWaitTime;
    int waitTime;
protected:
    void draw();
    
public:    
    Explosion(int X, int Y, int W, int H, int xF, int yF, const char *l=0);
    
    void incFrame();
    
    bool isDone();
};

#endif