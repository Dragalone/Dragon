#ifndef TEST_PLAYSTATE_H
#define TEST_PLAYSTATE_H

#include <vector>
#include "SDL.h"
#include "GameState.h"

class GameObject;
class SDLGameObject;

class PlayState : public GameState
{
public:

    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return s_playID; }

private:

    static const std::string s_playID;
    std::vector<GameObject*> m_gameObjects;
    SDL_Texture *score, *time;
};

#endif //TEST_PLAYSTATE_H
