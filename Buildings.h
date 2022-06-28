#ifndef TEST_BUILDINGS_H
#define TEST_BUILDINGS_H
#include "SDLGameObject.h"

class Buildings : public SDLGameObject {
    Buildings(const LoaderParams* pParams);
    virtual void draw();
    virtual void update();
    virtual void clean();
};


#endif //TEST_BUILDINGS_H
