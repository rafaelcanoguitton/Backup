#ifndef CHARACTER_H
#define CHARACTER_H
#include <Screen.h>
#include <Position.h>
#include <iostream>
using namespace std;
class Character:public Screen
{
    protected:
        Position pos;
        char shape;
        int health;
        string dialogue;
    public:
        Character();
        Character(char);
        Character(Position,char);
        Character(Position,char,string);
        virtual void Draw();
        void SetShape(char);
        void Move(int a,int b);
        void ChangePos(Position h);
        int GetHealth();
        Position GetPos();
        void hit();
        string getDialogue();
};

#endif // CHARACTER_H
