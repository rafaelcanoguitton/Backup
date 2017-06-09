#ifndef MYWINDOW_H
#define MYWINDOW_H
#include <Screen.h>
#include <iostream>
#include <Position.h>
#include <MySize.h>
using namespace std;
class MyWindow: public Screen
{
    protected:
        Position pos;
        MySize mwSize;
        void DrawHorizontalLine(int,int,int, char);
        void DrawVerticalLine(int,int,int, char);
    public:
        MyWindow();
        MyWindow(string);
        MyWindow(MySize);
        MyWindow(MySize, string, Position p=Position(0,0));
        void ShowMessage(Position,string);
        void Draw();
        inline Position GetPosition(){return pos;}
        inline MySize GetMySize(){return mwSize;}
        ~MyWindow();
};


#endif // MYWINDOW_H
