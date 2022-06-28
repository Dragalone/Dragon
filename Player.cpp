#include "Player.h"
#include "SDL.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams){}

void Player::draw()
{
    SDLGameObject::draw(); // we now use SDLGameObject
}
void Player::update()
{
    handleInput();

    m_currentFrame = int((SDL_GetTicks() / 100 % 6));


    SDLGameObject::update();
}
void Player::clean()
{
}
void Player::handleInput()
{

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_D))
    {
        m_velocity.setX(3);
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
    {
        m_velocity.setX(-3);

    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
    {
        m_velocity.setY(-3);
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_S))
    {
        m_velocity.setY(3);
    }

    if(InputHandler::Instance()->isKeyUp(SDL_SCANCODE_D))
    {
        if (m_velocity.getX()>0)
        m_velocity.setX(0);
    }
    if(InputHandler::Instance()->isKeyUp(SDL_SCANCODE_A))
    {
        if (m_velocity.getX()<0)
        m_velocity.setX(0);
    }
    if(InputHandler::Instance()->isKeyUp(SDL_SCANCODE_W))
    {
        if (m_velocity.getY()<0)
        m_velocity.setY(0);
    }
    if(InputHandler::Instance()->isKeyUp(SDL_SCANCODE_S))
    {
        if (m_velocity.getY()>0)
        m_velocity.setY(0);
    }
}