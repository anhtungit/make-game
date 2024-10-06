#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

class texturemanager
{
    public:
    static SDL_Texture* Texture(const char* filelocation,SDL_Renderer* ren);

};