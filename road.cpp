// Road.cpp
#include "make/road.h"

// Constructor khởi tạo đường với vị trí ban đầu và các thông số cần thiết
void Road::setroad(int Width, int width, int speed, int lineHeight, int gap)
{
    screenWidth =  Width;
    lineWidth  = width; 
    lineSpeed = speed; 
    lineHeight = lineHeight;
     gap = gap;
    for (int i = 0; i < Width + gap; i += gap) {
        lineX.push_back(i);  // Thêm vị trí ngang cho mỗi vạch kẻ
    }

}

// Cập nhật vị trí của vạch kẻ đường theo trục X
void Road::update() {
    for (int i = 0; i < lineX.size(); ++i) {
        lineX[i] -= lineSpeed;  // Di chuyển vạch kẻ từ phải sang trái

        // Nếu vạch kẻ đi hết ra khỏi màn hình bên trái, đưa nó trở lại bên phải
        if (lineX[i] < -lineWidth) {
            lineX[i] = screenWidth;  // Đưa vạch kẻ trở lại bên phải
        }
    }
}

// Vẽ mặt đường với các vạch kẻ
void Road::draw(SDL_Renderer* renderer, int screenHeight, int screenWidth) {
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);  // Màu xám
    SDL_Rect roadRect = {0, screenHeight / 4 * 3, screenWidth, screenHeight / 4};
    SDL_RenderFillRect(renderer, &roadRect);
    int midY = screenHeight / 4 * 3 + screenHeight / 8 - 5;  // Vị trí giữa đường
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Màu trắng cho vạch kẻ
 
    // Vẽ các vạch kẻ dọc theo làn đường
    for (int i = 0; i < lineX.size(); ++i) {
        SDL_Rect roadLine = {lineX[i], midY, lineWidth, 10};  // Vị trí và kích thước của vạch kẻ
        SDL_RenderFillRect(renderer, &roadLine);
    }
}