#ifndef TEST_GAMESTATEMACHINE_H
#define TEST_GAMESTATEMACHINE_H



#include <vector>

#include "GameState.h"

class GameStateMachine
{
public:

    void pushState(GameState* pState);
    void changeState(GameState* pState);
    void popState();

    void update();
    void render();

private:
    std::vector<GameState*> m_gameStates;
};

#endif //TEST_GAMESTATEMACHINE_H
