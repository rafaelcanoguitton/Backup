#include "Character.h"
#include <Screen.h>
#include <Position.h>
Character::Character()
{
    pos.x=0;
    pos.y=0;
    shape='è';
    health=3;
}

Character::Character(char c)
{
    pos.x=0;
    pos.y=0;
    shape=c;
    health=3;
}

Character::Character(Position p,char c)
{
    pos.x=p.x;
    pos.y=p.y;
    shape=c;
    health=3;
}
Character::Character(Position p,char c,string a)
{
    pos.x=p.x;
    pos.y=p.y;
    shape=c;
    health=3;
    dialogue=a;
}
void Character::Draw()
{
    DrawPixel(pos,shape);
}

void Character::SetShape(char s)
{
    shape= s;
}

void Character::Move(int a, int b)
{
    Position j(pos.x+a,pos.y+b);
    DeletePixel(pos);
    pos=j;
}

Position Character::GetPos()
{
    return pos;
}
void Character::ChangePos(Position h)
{
    pos=h;
}
int Character::GetHealth()
{
    return health;
}
void Character::hit()
{
    health+=-1;
}
string Character::getDialogue()
{
    return dialogue;
}
