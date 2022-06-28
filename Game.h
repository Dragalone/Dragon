#ifndef TEST_GAME_H
#define TEST_GAME_H
#include <vector>

#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "GameStateMachine.h"

class Game
{
public:
    static Game* Instance()
    {
        if(s_pInstance == nullptr)
        {
            s_pInstance = new Game();
            return s_pInstance;
        }
        return s_pInstance;
    }
    SDL_Renderer* getRenderer() const { return m_pRenderer; }
    ~Game();
    // simply set the running variable to true
    bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void render();
    void update();
    void handleEvents();
    void clean();
    // a function to access the private running variable
    bool running();
    void quit() { m_bRunning = false; }
    GameStateMachine* getStateMachine(){ return m_pGameStateMachine; }
private:

    Game();
    static Game* s_pInstance;
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;
    GameStateMachine* m_pGameStateMachine;
};


#endif //TEST_GAME_H
