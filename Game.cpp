#include "Game.h"
#include <iostream>
#include <vector>
#include "TextureManager.h"
#include "InputHandler.h"
#include "MenuState.h"
#include "PlayState.h"

Game* Game::s_pInstance = nullptr;

Game::Game (){

}

Game::~Game (){

}

bool Game::init(const char* title, int xpos, int ypos, int width,
                int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    // attempt to initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos,
                                     width, height, flags);
        if(m_pWindow != nullptr) // window init success
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if(m_pRenderer != nullptr) // renderer init success
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer,
                                       255,255,255,255);
            }
            else
            {
                std::cout << "renderer init fail\n";
                return false; // renderer init fail
            }
        }
        else
        {
            std::cout << "window init fail\n";
            return false; // window init fail
        }
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false; // SDL init fail
    }
    std::cout << "init success\n";
    m_bRunning = true; // everything inited successfully, start the main loop
    TextureManager::Instance()->load("res/Screen.png", "screen", m_pRenderer);
    SDL_RenderCopy(m_pRenderer,TextureManager::Instance()->m_textureMap["screen"],nullptr, nullptr);
    SDL_RenderPresent(m_pRenderer);
    SDL_Delay(5000);
    TextureManager::Instance()->clearFromTextureMap("screen");
    TextureManager::Instance()->load("res/orig.gif", "background", m_pRenderer);
    TextureManager::Instance()->load("res/Help.png", "help", m_pRenderer);
    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MenuState());
    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer); // clear the renderer to the draw color
    // loop through our objects and draw them
    SDL_RenderCopy(m_pRenderer,TextureManager::Instance()->m_textureMap["background"],nullptr, nullptr);
    m_pGameStateMachine->render();
    SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::update(){
    m_pGameStateMachine->update();
}

void Game::handleEvents()
{
    InputHandler::Instance()->update();
}

void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

bool Game::running() { return m_bRunning; }