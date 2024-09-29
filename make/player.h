#pragma once
#include "object.h"

class Player: public Object
{
    private:
    public:
    void Render(SDL_Renderer* ren, SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
};
