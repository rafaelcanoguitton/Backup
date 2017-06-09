#include "OneGame.h"
#include <Character.h>

OneGame::OneGame()
{
    windowGame = new MyWindow(MySize(40,15));
    Position t=windowGame->GetPosition();
    t.x+=5;
    t.y+=4;
    myCharacter = new Character(t,'#');
    t.x+=5;
    myEnemy = new Character(t,'&');
    t.y+=5;
    myNpc = new Character (t,'*',"Yo antes era un aventurero como tu, pero un dia me hirieron con una flecha en la rodilla");
    MySize st=windowGame->GetMySize();

    t=windowGame->GetPosition();
    t.x++;
    t.y++;

    srand (time(NULL));
}

void OneGame::Refresh()
{
    myCharacter->Draw();
    myEnemy->Draw();
    myNpc->Draw();
    string xd="La leyenda de Kublay";
    stringstream hb;
    hb<<myCharacter->GetHealth();
    windowGame->ShowMessage(Position(windowGame->GetMySize().width-xd.size()*1.5,1),xd);
    windowGame->ShowMessage(Position(0,3),string("Salud: ")+hb.str());
}

void OneGame::ReachLimit(Character *b,Character *c,Position op)
{
    int g=0;
    Position i=c->GetPos();
    Position pb=b->GetPos();
    Position pw=windowGame->GetPosition();
    MySize sw=windowGame->GetMySize();
    if(pb.x==i.x&pb.y==i.y)
    {
        b->ChangePos(op);
    }
    if(pb.x > pw.x && pb.x < pw.x +sw.width-1 && pb.y > pw.y && pb.y < pw.y +sw.height-1)
        g=g+1;
    else
        b->ChangePos(op);

}
void OneGame::GR(Character *Kub,Character *Enemy,Position retr)
{
    Position a,b;
    a=Kub->GetPos();
    b=Enemy->GetPos();
    if(a.x==b.x&a.y==b.y)
    {
        Kub->hit();
        Kub->ChangePos(retr);
        windowGame->ShowMessage(Position(0,22),"Ouch!");
    }
}
void OneGame::Start()
{
    char c;
    bool endGame=false;
    windowGame->Draw();


    do
    {
        Position pb=myCharacter->GetPos();
        if(kbhit())
        {
            c = getch();


            switch (c)
            {
                case ESC:               // press ESC to exit
                    myCharacter->hit() ;
                    break;
                case SPACE:               // press SPACE to clear screen
                    windowGame->ShowMessage(Position(0,21),myNpc->getDialogue());
                    break;
                case UP:
                    myCharacter->Move(0,-1);
                    break;
                case DOWN:
                    myCharacter->Move(0,1);
                    break;
                case LEFT:
                    myCharacter->Move(-1,0);
                    break;
                case RIGHT:
                    myCharacter->Move(1,0);
                    break;;
            }
        }
        ReachLimit(myCharacter,myNpc,pb);
        GR(myCharacter,myEnemy,pb);
        Refresh();
        if(0==myCharacter->GetHealth())
        {
            endGame=true;
            windowGame->ShowMessage(Position(0,21),string("Perdiste crrano color ianta"));
        }
        Sleep(30);

    }while(!endGame);

    windowGame->ShowMessage(Position(0,22),"The End...");
}

OneGame::~OneGame()
{
    delete windowGame;
}
