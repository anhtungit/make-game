// Road.cpp
#include "make/road.h"

// Constructor khởi tạo đường với vị trí ban đầu và các thông số cần thiết
void Road::setroad(int startX, int width, int speed, int spacing)
{
    lineX = startX;
    lineWidth  = width; 
    lineSpeed = speed; 
    lineSpacing = spacing;

}

// Cập nhật vị trí của vạch kẻ đường theo trục X
void Road::update()
{
    // Di chuyển vạch kẻ đường từ trái sang phải
    lineX -= lineSpeed;

    // Nếu vạch kẻ vượt ra ngoài màn hình bên trái, đặt lại vị trí
    if (lineX < -lineSpacing)
    {
        lineX = 0;
    }
}

// Vẽ mặt đường với các vạch kẻ
void Road::draw(SDL_Renderer* renderer, int screenWidth, int screenHeight)
{
    // Màu nền của mặt đường
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);  // Màu xám
    SDL_Rect roadRect = {0, screenHeight / 4 * 3, screenWidth, screenHeight / 4};
    SDL_RenderFillRect(renderer, &roadRect);

    // Vẽ các vạch kẻ đường
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Màu trắng
    int midY = screenHeight / 4 * 3 + screenHeight / 8 - 5;  // Vị trí giữa đường
    for (int i = 0; i < screenWidth; i += lineSpacing)
    {
        SDL_Rect line = {lineX + i, midY, lineWidth, 10};
        SDL_RenderFillRect(renderer, &line);
    }
}
