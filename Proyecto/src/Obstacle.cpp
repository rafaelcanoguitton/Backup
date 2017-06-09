#include "Obstacle.h"


Obstacle::Obstacle():Character(),state(1)
{

}

Obstacle::Obstacle(char c):Character(c),state(1)
{

}

Obstacle::Obstacle(Position p,char c): Character(p,c), state(1)
{

}

void Obstacle::Draw()
{
    shape = (char)(rand()*10 + 64);
    Character::Draw();
}

bool Obstacle::Impacted(Character b)
{
    if(pos.x==b.GetPos().x && pos.y==b.GetPos().y ){
        state=0;
        return true;
    }
    return false;
}
