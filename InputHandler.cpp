#include "InputHandler.h"
#include "Game.h"

#include <vector>
InputHandler* InputHandler::s_pInstance = nullptr;


InputHandler::InputHandler() : m_keystates(0), m_mousePosition(new Vector2D(0, 0))
{
    for(int i = 0; i < 3; i++)
    {
        m_mouseButtonStates[i] = false;
    }
}

void InputHandler::update()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                Game::Instance()->quit();
                break;
            case SDL_MOUSEMOTION:
                onMouseMove(event);
                break;
            case SDL_MOUSEBUTTONDOWN:
                onMouseButtonDown(event);
                break;

            case SDL_MOUSEBUTTONUP:
                onMouseButtonUp(event);
                break;

            case SDL_KEYDOWN:
                onKeyDown();
                break;
            case SDL_KEYUP:
                onKeyUp();
                break;

            default:
                break;
        }
    }
}

void InputHandler::onMouseButtonDown(SDL_Event& event)
{
    if(event.button.button == SDL_BUTTON_LEFT)
    {
        m_mouseButtonStates[LEFT] = true;
    }

    if(event.button.button == SDL_BUTTON_MIDDLE)
    {
        m_mouseButtonStates[MIDDLE] = true;
    }

    if(event.button.button == SDL_BUTTON_RIGHT)
    {
        m_mouseButtonStates[RIGHT] = true;
    }
}

void InputHandler::onMouseButtonUp(SDL_Event& event)
{
    if(event.button.button == SDL_BUTTON_LEFT)
    {
        m_mouseButtonStates[LEFT] = false;
    }

    if(event.button.button == SDL_BUTTON_MIDDLE)
    {
        m_mouseButtonStates[MIDDLE] = false;
    }

    if(event.button.button == SDL_BUTTON_RIGHT)
    {
        m_mouseButtonStates[RIGHT] = false;
    }
}

void InputHandler::onMouseMove(SDL_Event& event)
{
    m_mousePosition->setX(event.motion.x);
    m_mousePosition->setY(event.motion.y);
}

void InputHandler::onKeyDown()
{
    m_keystates = SDL_GetKeyboardState(nullptr);
    std::cout << "KeyDown ";
}

void InputHandler::onKeyUp()
{
    m_keystates = SDL_GetKeyboardState(nullptr);
    std::cout << "KeyUp ";
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if(m_keystates != nullptr)
    {
        if(m_keystates[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

bool InputHandler::isKeyUp(SDL_Scancode key)
{
    if(m_keystates != nullptr)
    {
        if(m_keystates[key] == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

void InputHandler::reset()
{
    for(int i = 0; i < 3; i++)
    {
        m_mouseButtonStates[i] = false;
    }
}