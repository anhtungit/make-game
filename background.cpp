
#include "make/background.h"

void Background::Render(SDL_Renderer* ren, SDL_Texture* tex, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(ren, tex, NULL, NULL);
}
