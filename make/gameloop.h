#pragma once

#include <iostream>
#include "player.h"
#include "background.h"
#include "banhxe.h"
#include "sky.h"
#include "road.h"


using namespace std;

class gameloop
{
private:
    Road road;
    Sun sun;
    Sky sky;
    Banhxe2 banh2;
    Banhxe1 banh1;
    Player p;
    Background b;
    const int HEIGHT = 600;
    const int WIDTH = 1200;
    const int SUN_RADIUS = 50;
    int sunMinY = 500;  // Mặt trời mọc
    int sunMaxY = HEIGHT/ 3;  // Mặt trời đạt đỉnh
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
