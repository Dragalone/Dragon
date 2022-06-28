#ifndef TEST_PLAYER_H
#define TEST_PLAYER_H
#include "SDLGameObject.h"
#include "InputHandler.h"

class Player : public SDLGameObject {
public:
    Player(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
    virtual void handleInput();
};


#endif //TEST_PLAYER_H
