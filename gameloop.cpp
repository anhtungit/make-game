#include "make/gameloop.h"


gameloop::gameloop()
{
    window = NULL;
    renderer = NULL;
    GameState = false;
    
    
}

bool gameloop::getGameState()
{
    return GameState;
}

void gameloop::Init()
{
    
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("anh dong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window)
    {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer)
        {
            cout << "khoi tao thanh cong\n";
            GameState = true;
            p.createtexture("image/xe.png", renderer);
            banh1.createtexture("image/banhxe.png", renderer);
            banh2.createtexture("image/banhxe.png", renderer);
            sun.setsun(WIDTH / 2, 500 + SUN_RADIUS, sunMinY, sunMaxY);
            road.setroad(WIDTH,60, 30, 1, 100);
            fence.setfence(WIDTH, 10, 30, 30, 100);
            initSnowflakes(100, WIDTH, HEIGHT);
        }
        else
            cout << "khong the tao render\n";
    }
    else
        cout << "khong the khoi tao window\n";
}

void gameloop::Event()
{
    SDL_PollEvent(&event1);
    if (event1.type == SDL_QUIT)
    {
        GameState = false;
    }
}

void gameloop::update()
{
    sun.update();
    p.Update();
    banh1.Updatebanh1();
    banh2.Updatebanh2();
    fence.update();
    road.update();
     updateSnowflakes(WIDTH, HEIGHT);
}

void gameloop::Render()
{
    SDL_RenderClear(renderer);
    sky.drawDynamicSky(renderer, WIDTH, HEIGHT, sun.getY(), sunMinY, sunMaxY);
    sun.drawGradientSun(renderer, sun.getX(), sun.getY(), SUN_RADIUS);
    drawMountains(renderer,WIDTH, HEIGHT);
    road.draw(renderer, HEIGHT, WIDTH);
    fence.draw(renderer, WIDTH, HEIGHT);
    p.Render(renderer);
    banh1.RenderCopyEx(renderer);
    banh2.RenderCopyEx(renderer);
    drawSnowflakes(renderer);
    SDL_RenderPresent(renderer);
    
}

void gameloop::Clear()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
