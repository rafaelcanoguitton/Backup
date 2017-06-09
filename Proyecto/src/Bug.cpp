#include "Bug.h"
#include <Screen.h>

Bug::Bug():Character(),dir(Direction(1,1))
{

}

Bug::Bug(char c):Character(c),dir(Direction(1,1))
{

}

Bug::Bug(Position p,char c, Direction d): Character(p,c),dir(d)
{

}

void Bug::Draw()
{
    DeletePixel(pos);
    Move(pos.x+dir.dx,pos.y+dir.dy);
    Character::Draw();
}
