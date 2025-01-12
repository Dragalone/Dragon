#ifndef TEST_TEXTUREMANAGER_H
#define TEST_TEXTUREMANAGER_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string.h>
#include <SDL_audio.h>
#include <SDL_image.h>
#include <map>
#include <Windows.h>

class TextureManager {
private:
    static TextureManager *s_pInstance;
    TextureManager(){}
public:
    bool load(std::string fileName,std::string id,SDL_Renderer* pRenderer);
    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void CustomDrawFrame(std::string id, int x, int y, int width, int height, int dst_width,int dst_height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
    void clearFromTextureMap(std::string id);
    std::map<std::string, SDL_Texture*> m_textureMap;
    static TextureManager* Instance()
    {
        if(s_pInstance == nullptr)
        {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        return s_pInstance;
    }
};


#endif //TEST_TEXTUREMANAGER_H
