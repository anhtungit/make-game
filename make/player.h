#pragma once
#include "object.h"

class Player: public Object
{
    private:
    public:
    void Update();
    void Render(SDL_Renderer* ren);
};
