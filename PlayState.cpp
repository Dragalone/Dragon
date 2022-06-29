#include <string>
#include <iostream>

#include "PlayState.h"
#include "TextureManager.h"
#include "Game.h"
#include "GameObject.h"
#include "PauseState.h"
#include "Buildings.h"
#include "FontManager.h"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
    {
        Game::Instance()->getStateMachine()->pushState(new PauseState());
    }
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void PlayState::render()
{
    for(std::vector<GameObject*>::size_type i = m_gameObjects.size()-1; i != -1; i--)
    {
        m_gameObjects[i]->draw();
    }
    FontManager::Instance()->renderTexture(time,Game::Instance()->getRenderer(),1550,50);
    FontManager::Instance()->renderTexture(score,Game::Instance()->getRenderer(),60,50);
}

bool PlayState::onEnter()
{
    if(!TextureManager::Instance()->load("res/Dragon.png", "animate", Game::Instance()->getRenderer()))
    {
        return false;
    }
    if(!TextureManager::Instance()->load("res/building.png", "building", Game::Instance()->getRenderer()))
    {
        return false;
    }
    GameObject* player = new Player(new LoaderParams(100, 400, 500, 150, "animate"));
    GameObject* building = new Buildings(new LoaderParams(1920, 320, 430, 718, "building"));
    m_gameObjects.push_back(player);
    m_gameObjects.push_back(building);
    SDL_Color color = { 255, 255, 255, 255 };
    time = FontManager::Instance()->renderText("Time: 1:00", "res/ComicSansMS.ttf",
                      color, 60, Game::Instance()->getRenderer());
    score = FontManager::Instance()->renderText("Score: 1000", "res/ComicSansMS.ttf",
                                               color, 60, Game::Instance()->getRenderer());
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
    TextureManager::Instance()->clearFromTextureMap("building");
    return true;
}