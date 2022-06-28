#include <string>
#include <iostream>

#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameObject.h"
#include "PauseState.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        Game::Instance()->getStateMachine()->pushState(new PauseState());
    }
    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void PlayState::render()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}

bool PlayState::onEnter()
{
    if(!TextureManager::Instance()->load("res/Dragon.png", "animate", Game::Instance()->getRenderer()))
    {
        return false;
    }
    GameObject* player = new Player(new LoaderParams(100, 100, 500, 150, "animate"));
    m_gameObjects.push_back(player);
    return true;
}

bool PlayState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->clean();
    }
    m_gameObjects.clear();
    TextureManager::Instance()->clearFromTextureMap("animate");

    return true;
}