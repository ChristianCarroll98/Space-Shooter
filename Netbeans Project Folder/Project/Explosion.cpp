#include <Explosion.h>
#include <FL/fl_draw.H>
#include <FL/Fl.H>

Explosion::Explosion(int X, int Y, int W, int H, int xF, int yF, const char *l) : Fl_Widget(X,Y,W,H,l) {
    curFrameX = 0;
    curFrameY = 0;
    xFrames = xF;
    yFrames = yF;
    lastFrame = xF*yF;
    done = false;
    initWaitTime = 50;
    waitTime = 0;
    fl_push_clip(curFrameX*x(), curFrameY*y(), w(), h());
}

void Explosion::draw(){
    draw_box();
    draw_label();
    if(waitTime == initWaitTime){
        if(curFrameX * curFrameY != lastFrame){
            if(curFrameX==xFrames){
                fl_pop_clip();
                curFrameX=0;
                curFrameY++;
                fl_push_clip(curFrameX*x(), curFrameY*y(), w(), h());
            }else{
                fl_pop_clip();
                curFrameX++;
                fl_push_clip(curFrameX*x(), curFrameY*y(), w(), h());
            }
        }else{
            Fl::delete_widget(this);
        }
    }else{
        waitTime++;
    }
}

//void Explosion::incFrame(){}

//bool Explosion::isDone(){
//    return done;
//}