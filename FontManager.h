#ifndef DRAGONGAME_FONTMANAGER_H
#define DRAGONGAME_FONTMANAGER_H

#include <SDL_ttf.h>
#include <iostream>

class FontManager {
private:
    static FontManager *s_pInstance;
    FontManager(){}

public:
    SDL_Texture* renderText(const std::string &message, const std::string &fontFile,
                            SDL_Color color, int fontSize, SDL_Renderer *renderer);
    void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y,
                       SDL_Rect *clip = nullptr);
    static FontManager* Instance()
    {
        if(s_pInstance == nullptr)
        {
            s_pInstance = new FontManager();
            return s_pInstance;
        }
        return s_pInstance;
    }
};


#endif //DRAGONGAME_FONTMANAGER_H
