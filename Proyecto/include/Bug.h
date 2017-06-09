#ifndef BUG_H
#define BUG_H
#include <Character.h>
#include <Direction.h>
#include <Screen.h>
class Bug:public Character
{
    protected:
        Direction dir;
    public:
        Bug();
        Bug(char);
        Bug(Position,char, Direction d=Direction(1,1));
        inline void SetDirection(Direction d){dir=d;}
        inline Direction GetDirection(){return dir;}
        void Draw();
};
#endif // BUG_H
