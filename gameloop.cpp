#include "make/gameloop.h"

gameloop::gameloop()
{
    window = NULL;
    renderer = NULL;
    GameState = false;
    p.setsrc(0,0,1200,600);
    p.setdest(10,20,1200,600);
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
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            cout << "khoi tao thanh cong\n";
            GameState = true;
            p.createtexture("image/ronaldo.png", renderer);
            b.createtexture("imagenenchuan.png", renderer);
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
   
}


void gameloop::Render()
{
    SDL_RenderClear(renderer);
    p.Render(renderer, p.gettexture(), p.getsrc(), p.getdest());
    b.Render(renderer, b.gettexture(),b.getsrc(), b.getdest());
    SDL_RenderPresent(renderer);
} 

void gameloop::Clear()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}
