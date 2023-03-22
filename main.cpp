#include<SDL.h>
#include"Game.h"
int main(int argc, char* argv[])
{
<<<<<<< HEAD
    TheGame::Instance()->init("The Box", 100, 50, 1280, 720, 0);
=======
    TheGame::Instance()->init("The Box", 100, 100, 1280, 720, 0);
>>>>>>> f0f3dc4db31df5307efa3b4a539809abafe70438

while(TheGame::Instance()->running())
{
    TheGame::Instance()->handleEvents();
    TheGame::Instance()->update();
    TheGame::Instance()->render();
}
TheGame::Instance()->clean();
return 0;
}

