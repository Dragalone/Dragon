#include "Buildings.h"

Buildings::Buildings(const LoaderParams *pParams) : SDLGameObject(pParams){
    m_currentFrame = 0;
}

void Buildings::draw() {
    SDLGameObject::draw();
}

void Buildings::update()
{
    m_velocity.setX(-3);
    SDLGameObject::update();
}

void Buildings::clean() {

}