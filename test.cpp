#include <SDL2/SDL.h>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SUN_RADIUS = 50;

float x, y;
    float speedY;
     // Vị trí hiện tại của mặt trời
int sunMinY = 500;  // Mặt trời mọc
int sunMaxY = SCREEN_HEIGHT / 3;
// Mặt trời với vị trí và tốc độ đi lên

struct Sun
{
    

    Sun(float startX, float startY)
    {
        x = startX;
        y = startY;
        speedY = -5; // Tốc độ đi lên của mặt trời
    }

    void update()
    {
        y += speedY;

        // Dừng lại khi mặt trời đạt đỉnh (khoảng 1/3 màn hình từ trên xuống)
        if (y < sunMaxY)
        {
            speedY = 0;
        }
    }
};

// Hàm vẽ mặt trời với hiệu ứng gradient (từ cam sang vàng)
void drawGradientSun(SDL_Renderer* renderer, int x, int y, int radius) {
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


void drawDynamicSky(SDL_Renderer* renderer, int screenWidth, int screenHeight, int y, int sunMinY, int sunMaxY) {
    // Màu xanh đậm ban đầu (khi mặt trời ở vị trí thấp nhất)
    Uint8 startRed = 0;
    Uint8 startGreen = 0;
    Uint8 startBlue = 139;  // Dark blue

    // Màu xanh nhạt khi mặt trời ở vị trí cao nhất (noon)
    Uint8 endRed = 135;
    Uint8 endGreen = 206;
    Uint8 endBlue = 235;  // Light blue

    // Tính toán tỷ lệ dựa trên vị trí hiện tại của mặt trời
    float t = (float)(y - sunMinY) / (float)(sunMaxY - sunMinY);  
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



int main(int argc, char *argv[])
{
    // Khởi tạo SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {

        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("Mặt trời mọc với Gradient", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {

        return -1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
    {

        return -1;
    }

    srand(static_cast<unsigned int>(time(0)));

    Sun sun(SCREEN_WIDTH / 2, 500 + SUN_RADIUS); // Khởi tạo mặt trời ở dưới màn hình

    bool quit = false;
    SDL_Event e;

    // Vòng lặp chính
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        // Cập nhật vị trí của mặt trời
        sun.update();

        // Lấy màu bầu trời theo vị trí của mặt trời
        
        

        SDL_RenderClear(renderer);
        drawDynamicSky(renderer, SCREEN_WIDTH, SCREEN_HEIGHT, y, sunMinY, sunMaxY);
        
        // Vẽ mặt trời với hiệu ứng gradient
        drawGradientSun(renderer, x, static_cast<int>(y), SUN_RADIUS);
        // Vẽ mặt đất
        SDL_SetRenderDrawColor(renderer, 34, 139, 34, 255);                            // Màu xanh lá cây
        SDL_Rect ground = {0, SCREEN_HEIGHT / 3 * 2, SCREEN_WIDTH, SCREEN_HEIGHT / 3}; // Chiếm 1/3 màn hình dưới cùng
        SDL_RenderFillRect(renderer, &ground);

        

        // Cập nhật màn hình
        SDL_RenderPresent(renderer);

        // Giới hạn FPS
        SDL_Delay(16); // Khoảng 60 FPS
    }

    // Giải phóng tài nguyên
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}