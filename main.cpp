#include "Game.h"

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char* argv[])
{
    Uint32 frameStart, frameTime;
    AllocConsole();
    freopen("CON","w", stdout);
    if(Game::Instance()->init("DragonGame", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,  1920, 1080, 1)){
        while(Game::Instance()->running())
        {
            frameStart = SDL_GetTicks();

             Game::Instance()->handleEvents();
             Game::Instance()->update();
             Game::Instance()->render();

             frameTime = SDL_GetTicks() - frameStart;
            if(frameTime< DELAY_TIME)
            {
                SDL_Delay((int)(DELAY_TIME - frameTime));
            }
        }
     } else {
        std::cout << "game init failure - " << SDL_GetError() << "\n";
        return -1;
    }
    Game::Instance()->clean();
    return 0;
}



