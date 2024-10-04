#include "sun.h"

class Sky
{
public:
    Sky();

    void drawDynamicSky(SDL_Renderer* renderer, int screenWidth, int screenHeight, int sunY, int sunMinY, int sunMaxY) const;
};