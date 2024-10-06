#include "texturemanager.h"



struct Snowflake {
    int x, y, speed;
};

// Hàm khởi tạo bông tuyết
void initSnowflakes( int count,int SCREEN_WIDTH, int SCREEN_HEIGHT);

// Hàm cập nhật vị trí bông tuyết
void updateSnowflakes(int SCREEN_WIDTH, int SCREEN_HEIGHT);

// Hàm vẽ bông tuyết
void drawSnowflakes(SDL_Renderer* renderer);

