#pragma once
#include "object.h"

class Background : public Object
{
private:
public:
    void Render(SDL_Renderer *ren);
};