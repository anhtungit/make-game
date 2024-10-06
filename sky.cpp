// Sky.cpp
#include "make/sky.h"

// Constructor của Sky
Sky::Sky()
{
}

// Hàm làm bầu trời thay đổi màu sắc dựa theo vị trí mặt trời
void Sky::drawDynamicSky(SDL_Renderer* renderer, int screenWidth, int screenHeight, int sunY, int sunMinY, int sunMaxY) const {
    // Màu xanh đậm ban đầu (khi mặt trời ở vị trí thấp nhất)
    Uint8 startRed = 0;
    Uint8 startGreen = 0;
    Uint8 startBlue = 50;  // Dark blue

    // Màu xanh nhạt khi mặt trời ở vị trí cao nhất (noon)
    Uint8 endRed = 135;
    Uint8 endGreen = 206;
    Uint8 endBlue = 235;  // Light blue

    // Tính toán tỷ lệ dựa trên vị trí hiện tại của mặt trời
    float t = (float)(sunY - sunMinY) / (float)(sunMaxY - sunMinY);  
    if (t < 0) t = 0;
    if (t > 1) t = 1;

    // Tính màu nền dựa trên vị trí mặt trời
    Uint8 r = startRed + static_cast<Uint8>(t * (endRed - startRed));
    Uint8 g = startGreen + static_cast<Uint8>(t * (endGreen - startGreen));
    Uint8 b = startBlue + static_cast<Uint8>(t * (endBlue - startBlue));

    // Vẽ bầu trời với màu đã tính toán
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderClear(renderer);
}
