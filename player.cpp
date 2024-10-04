#include"make/player.h"

void Player::Render(SDL_Renderer* ren)
{
    SDL_RenderCopy(ren, gettexture(), &getsrc(), &getdest());
}


void Player::Update()
{
    setsrc(0, 0, 821, 313);
    setdest(50, 400, 410, 155);
}