#pragma once

#include <iostream>
#include "player.h"
#include "background.h"

using namespace std;

class gameloop
{
private:
    Player p;
    Background b;
    const int HEIGHT = 600;
    const int WIDTH = 1200;
    bool GameState;
    
    SDL_Event event1;
    SDL_Window *window;
    SDL_Renderer *renderer;
    
    

public:
    gameloop();
    bool getGameState();
    void update();
    void Init();
    void Event();
    void Render();
    void Clear();
};
