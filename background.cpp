
#include "make/background.h"

void Background::Render(SDL_Renderer* ren)
{
    SDL_RenderCopy(ren, gettexture(), NULL, NULL);
}
