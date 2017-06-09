#include "Screen.h"
#include <iostream>
using namespace std;
void Screen::GotoXY(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void Screen::DrawPixel(int x, int y, char pixel)
{
    GotoXY(x,y);
    cout<<pixel;
}

void Screen::DrawPixel(Position p, char pixel)
{
    DrawPixel(p.x,p.y,pixel);
}


void Screen::DeletePixel(int x, int y)
{
    GotoXY(x,y);
    cout<<" ";
}

void Screen::DeletePixel(Position p)
{
    DeletePixel(p.x,p.y);
}
