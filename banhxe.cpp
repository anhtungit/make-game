#include "make/banhxe.h"

void Banhxe1::RenderCopyEx(SDL_Renderer *ren)
{
    SDL_RenderCopyEx(ren, gettexture(), &getsrc(), &getdest(), angle, NULL, SDL_FLIP_NONE);
}

void Banhxe1::Updatebanh1()
{
    setsrc(0, 0, 139, 138);
    setdest(80, 484, 69, 69);
    angle += 90;
    
}

void Banhxe2::Updatebanh2()
{
    setsrc(0, 0, 139, 138);
    setdest(342, 484, 69, 69);
    angle += 90;
   
}