
#include "make/object.h"


Object::Object()
{
    tex = NULL;
}


SDL_Texture* Object::gettexture()
{
    return tex;
}


SDL_Rect &Object::getsrc()
{
    return src;
}


SDL_Rect &Object::getdest()
{
    return dest;
}


void Object::setsrc(int x, int y, int w, int h)
{
    src.x = x;
    src.y = y;
    src.w = w;
    src.h = h;
}


void Object::setdest(int x, int y, int w, int h)
{
    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;
}


void Object::createtexture(const char* address, SDL_Renderer* ren)
{
    tex = texturemanager::Texture(address, ren);
}


