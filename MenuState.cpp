#include <string>
#include <iostream>

#include "MenuState.h"
#include "PlayState.h"
#include "MenuButton.h"
#include "TextureManager.h"
#include "Game.h"

const std::string MenuState::s_menuID = "MENU";

void MenuState::update()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

void MenuState::render()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
}

bool MenuState::onEnter()
{
    if(!TextureManager::Instance()->load("res/play_button.png", "playbutton", Game::Instance()->getRenderer()))
    {
        return false;
    }

    if(!TextureManager::Instance()->load("res/exit_button.png", "exitbutton", Game::Instance()->getRenderer()))
    {
        return false;
    }
    if(!TextureManager::Instance()->load("res/help_button1.png", "helpbutton", Game::Instance()->getRenderer()))
    {
        return false;
    }
    GameObject* button1 = new MenuButton(new LoaderParams(300, 100, 400, 100, "playbutton"), s_menuToPlay);
    GameObject* button2 = new MenuButton(new LoaderParams(300, 300, 400, 100, "exitbutton"),  s_exitFromMenu);
    GameObject* button3 = new MenuButton(new LoaderParams(300, 200, 400, 100, "helpbutton"),  s_help);

    m_gameObjects.push_back(button1);
    m_gameObjects.push_back(button2);
    m_gameObjects.push_back(button3);
    std::cout << "entering MenuState\n";
    return true;
}

bool MenuState::onExit()
{
    for(int i = 0; i < m_gameObjects.size(); i++)
    {
        m_gameObjects[i]-> clean();
    }
    m_gameObjects.clear();
    TextureManager::Instance()->clearFromTextureMap("playbutton");
    TextureManager::Instance()->clearFromTextureMap("exitbutton");
    TextureManager::Instance()->clearFromTextureMap("helpbutton");
    std::cout << "exiting MenuState\n";
    return true;
}

void MenuState::s_menuToPlay()
{
    Game::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
        Game::Instance()->quit();
}
void MenuState::s_help()
{
    std::cout << "Help button clicked\n";
    SDL_RenderClear(Game::Instance()->getRenderer());
    SDL_RenderCopy(Game::Instance()->getRenderer(),TextureManager::Instance()->m_textureMap["help"],nullptr, nullptr);
    SDL_RenderPresent(Game::Instance()->getRenderer());
    SDL_Event event;

    bool done = false;
    while (!done)
    {
        while (SDL_PollEvent(&event)) // ѕока есть хоть одно необработанное событие
        {
            switch(event.type)
            {
                case SDL_MOUSEBUTTONDOWN:
                    done = true;
                    break;
            }
        }
    }
}