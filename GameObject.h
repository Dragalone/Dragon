#ifndef TEST_GAMEOBJECT_H
#define TEST_GAMEOBJECT_H

#include "LoaderParams.h"


class GameObject {
public:
    virtual void draw()=0;
    virtual void update()=0;
    virtual void clean()=0;
protected:
    GameObject(const LoaderParams* pParams) {}
    virtual ~GameObject() {}
};


#endif //TEST_GAMEOBJECT_H
