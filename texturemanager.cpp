#include "make/texturemanager.h"

SDL_Texture* texturemanager::Texture(const char* filelocation,SDL_Renderer* ren)
{
    SDL_Surface* surface;
    surface = IMG_Load(filelocation);
    SDL_Texture* tex;
    tex = SDL_CreateTextureFromSurface(ren, surface);
    return tex;
}
