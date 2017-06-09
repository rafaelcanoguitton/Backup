#ifndef ONEGAME_H
#define ONEGAME_H
#include <MyWindow.h>
#include <Character.h>
#include<Obstacle.h>
#include<time.h>
#include <sstream>

const char UP = 72;
const char LEFT = 75;
const char RIGHT = 77;
const char DOWN = 80;
const char ESC = 27;
const char SPACE = 32;

class OneGame
{
    protected:

        MyWindow *windowGame;
        Character *myCharacter;
        Character *myEnemy;
        Character *myNpc;
    public:

        OneGame();
        void Start();
        void Refresh();
        void ReachLimit(Character*,Character*,Position);
        void GR(Character*,Character*,Position);
        ~OneGame();
};


#endif // ONEGAME_H
