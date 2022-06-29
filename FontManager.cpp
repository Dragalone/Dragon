//
// Created by user on 30.06.2022.
//

#include "FontManager.h"

FontManager* FontManager::s_pInstance = nullptr;

SDL_Texture* FontManager::renderText(const std::string &message, const std::string &fontFile,
                        SDL_Color color, int fontSize, SDL_Renderer *renderer)
{
    //Открываем шрифт
    TTF_Font *font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == nullptr){
        std::cout<< "TTF_OpenFont error";
        return nullptr;
    }
    //Сначала нужно отобразить на поверхность с помощью TTF_RenderText,
    //затем загрузить поверхность в текстуру
    SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
    if (surf == nullptr){
        TTF_CloseFont(font);
        std::cout<<"TTF_RenderText error";
        return nullptr;
    }
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
    if (texture == nullptr){
        std::cout<< "CreateTexture error";
    }
    //Очистка поверхности и шрифта
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    return texture;
}

void FontManager::renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y,
                   SDL_Rect *clip)
{
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    if (clip != nullptr){
        dst.w = clip->w;
        dst.h = clip->h;
    }
    else {
        SDL_QueryTexture(tex, NULL, NULL, &dst.w, &dst.h);
    }
    SDL_RenderCopy(ren, tex, clip, &dst);
}