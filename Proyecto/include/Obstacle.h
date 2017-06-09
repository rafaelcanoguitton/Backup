#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <Character.h>
#include <Position.h>
#include <Bug.h>

class Obstacle:public Character
{
    protected:
        int state;

    public:
        Obstacle();
        Obstacle(char);
        Obstacle(Position,char);
        void Draw();
        inline void SetState(int s){state=s;}
        inline int GetState(){return state;}
        bool Impacted(Character b);
};


#endif // OBSTACLE_H
