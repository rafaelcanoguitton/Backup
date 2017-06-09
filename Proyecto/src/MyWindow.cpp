#include "MyWindow.h"
#include <Screen.h>
MyWindow::MyWindow()
{
    pos = Position(5,5);
    mwSize=MySize(80,20);
}

MyWindow::MyWindow(string t)
{
    pos = Position(0,0);
    mwSize=MySize(80,20);
}

MyWindow::MyWindow(MySize s)
{
    pos = Position(5,5);
    mwSize = s;
}


MyWindow::MyWindow(MySize s, string t, Position p): mwSize(s), pos(p)
{

}

void MyWindow::ShowMessage(Position p,string message)
{
    GotoXY(p.x,p.y);
    cout<<message;
}

void MyWindow::DrawHorizontalLine(int xi,int xf,int y, char c)
{
    int i=xi;
    while(i<xf)
        DrawPixel(i++,y,c);
}

void MyWindow::DrawVerticalLine(int yi,int yf,int x, char c)
{
    int i=yi;
    while(i<yf)
        DrawPixel(x,i++,c);
}

void MyWindow::Draw()
{
    char c='|';
    char d='-';
    DrawHorizontalLine(pos.x, pos.x + mwSize.width, pos.y, d);
    DrawHorizontalLine(pos.x, pos.x + mwSize.width, pos.y + mwSize.height - 1, d);
    DrawVerticalLine(pos.y ,pos.y + mwSize.height - 1, pos.x, c);
    DrawVerticalLine(pos.y, pos.y + mwSize.height-1, pos.x + mwSize.width - 1, c);
}

MyWindow::~MyWindow()
{
}
