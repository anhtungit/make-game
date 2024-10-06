#include "make/fence.h"

void Fence::setfence(int Width, int width, int height, int speed, int gap)
{
    screenWidth = Width;
    fenceWidth = width;
    fenceHeight = height;
    speedfence = speed;
    Gap = gap;

    for (int i = 0; i < screenWidth + gap; i += gap)
    {
        fenceX.push_back(i); // Thêm vị trí ngang cho mỗi hàng rào
    }
}

void Fence::update()
{
    for (int i = 0; i < fenceX.size(); ++i)
    {
        fenceX[i] -= speedfence; // Di chuyển hàng rào từ phải sang trái

        // Nếu hàng rào đi hết ra khỏi màn hình bên trái, đưa nó trở lại bên phải
        if (fenceX[i] < -fenceWidth)
        {
            fenceX[i] = screenWidth; // Đưa hàng rào trở lại bên phải
        }
    }
}

// Vẽ lan can
void Fence::draw(SDL_Renderer *renderer, int screenWidth, int screenHeight)
{
    // Màu của lan can
    SDL_SetRenderDrawColor(renderer, 139, 69, 19, 255); // Màu nâu

    SDL_Rect fillRect = {0, 410, 1200, 10};
    SDL_RenderFillRect(renderer, &fillRect);
    // Vẽ các lan can theo khoảng cách
    for (int i = 0; i < fenceX.size(); ++i)
    {
        SDL_Rect fence = {fenceX[i], 420, fenceWidth, fenceHeight}; // Vị trí và kích thước của hàng rào
        SDL_RenderFillRect(renderer, &fence);
    }
}
