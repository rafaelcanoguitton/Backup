#include "Direction.h"

Direction::Direction(){
    dx=0;
    dy=0;
}

Direction::Direction(int d):dx(d),dy(d){
}

Direction::Direction(int cx,int cy):dx(cx),dy(cy){
}

