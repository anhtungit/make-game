#pragma once

#include <iostream>
#include "player.h"
#include "background.h"
#include "banhxe.h"
#include "sky.h"
#include "road.h"
#include "fence.h"
#include "tuyet.h"

using namespace std;

class gameloop
{
private:
    Snowflake tuyet;
    Fence fence; 
    Road road;
    Sun sun;
    Sky sky;
    Banhxe2 banh2;
    Banhxe1 banh1;
    Player p;
    
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
