#include <FL/Fl_Group.H>

class EntityGroup : public Fl_Group {
public:
    
    EntityGroup::EntityGroup(int X,int Y,int W, int H, const char *l) : Fl_Group(X, Y, W, H, l) {}

};