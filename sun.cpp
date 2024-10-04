// Sun.cpp
#include "make/sun.h"

// Constructor khởi tạo mặt trời với vị trí bắt đầu và giới hạn
void Sun::setsun(float startX, float startY, int minY, int maxY)
{
     x = startX; 
     y = startY; 
     speedY = -5; 
     sunMinY = minY; 
     sunMaxY = maxY;

}

// Cập nhật vị trí của mặt trời
void Sun::update()
{
    y += speedY;

    // Dừng lại khi mặt trời đạt đỉnh (khoảng 1/3 màn hình từ trên xuống)
    if (y < sunMaxY)
    {
        speedY = 0;
    }
}

// Lấy vị trí X của mặt trời
float Sun::getX() const
{
    return x;
}

// Lấy vị trí Y của mặt trời
float Sun::getY() const
{
    return y;
}

// Hàm vẽ mặt trời với hiệu ứng gradient (từ cam sang vàng)
void Sun::drawGradientSun(SDL_Renderer* renderer, int x, int y, int radius) {
    for (int r = radius; r > 0; r--) {
        int red = 255;
        int green = 223 + (radius - r) * (255 - 223) / radius; // Chuyển từ màu cam sang vàng
        int blue = 0;
        SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
        for (int w = 0; w < r * 2; w++) {
            for (int h = 0; h < r * 2; h++) {
                int dx = r - w;  // Khoảng cách từ tâm theo chiều ngang
                int dy = r - h;  // Khoảng cách từ tâm theo chiều dọc
                if ((dx*dx + dy*dy) <= (r * r)) {
                    SDL_RenderDrawPoint(renderer, x + dx, y + dy);
                }
            }
        }
    }
}


