#pragma once
#include "object.h"

class Banhxe1 : public Object{
    private:
         
    public:
         void Updatebanh1();
         double angle = 0;
         void RenderCopyEx(SDL_Renderer* ren);
};


class Banhxe2 : public Banhxe1{
    private:
         
    public:
    void Updatebanh2();
};