#include "make/tuyet.h"
std::vector<Snowflake> snowflakes;
void initSnowflakes(int count, int SCREEN_WIDTH, int SCREEN_HEIGHT) {
    for (int i = 0; i < count; ++i) {
        Snowflake snowflake;
        snowflake.x = rand() % SCREEN_WIDTH; // Vị trí ngẫu nhiên theo chiều ngang
        snowflake.y = rand() % SCREEN_HEIGHT; // Vị trí ngẫu nhiên theo chiều dọc
        snowflake.speed = rand() % 3 + 1; // Tốc độ rơi
        snowflakes.push_back(snowflake);
    }
}

// Hàm cập nhật vị trí bông tuyết
void updateSnowflakes(  int SCREEN_WIDTH, int SCREEN_HEIGHT) {
    for (auto& snowflake : snowflakes) {
        snowflake.y += snowflake.speed; // Cập nhật vị trí rơi
        if (snowflake.y > SCREEN_HEIGHT) {
            snowflake.y = 0; // Đưa tuyết lên đầu màn hình khi xuống dưới
            snowflake.x = rand() % SCREEN_WIDTH; // Vị trí ngẫu nhiên mới
        }
    }
}

// Hàm vẽ bông tuyết
void drawSnowflakes(SDL_Renderer* renderer) {
    for (const auto& snowflake : snowflakes) {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Màu trắng cho tuyết
        SDL_Rect snowRect = {snowflake.x, snowflake.y, 5, 5};
        SDL_RenderFillRect(renderer, &snowRect);
    }
}