#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <iostream>

// Kích thước cửa sổ
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Tốc độ khung hình
const int FRAME_RATE = 5;

// Số lượng frame trong ảnh động
const int FRAME_COUNT = 6;

int main(int argc, char* args[])
{
    // Khởi tạo SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL không thể khởi tạo! Lỗi: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Tạo cửa sổ
    SDL_Window* window = SDL_CreateWindow("SDL Animation",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        std::cout << "Cửa sổ không thể tạo! Lỗi: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Tạo renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        std::cout << "Renderer không thể tạo! Lỗi: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Tải hình ảnh cho ảnh động
    SDL_Surface* spriteSheet = SDL_LoadBMP("anh.bmp");
    if (spriteSheet == NULL) {
        std::cout << "Không thể tải hình ảnh! Lỗi: " << SDL_GetError() << std::endl;
        return -1;
    }

    // Tạo texture từ surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, spriteSheet);
    SDL_FreeSurface(spriteSheet);

    // Kích thước của một frame
    int frameWidth = 500; // Giả sử kích thước mỗi frame là 100x100
    int frameHeight = 500;

    // Biến thời gian
    int frame = 0;
    Uint32 start_time = SDL_GetTicks();
    bool quit = false;
    SDL_Event e;

    // Vòng lặp chính
    while (!quit) {
        // Xử lý sự kiện
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Cập nhật frame
        Uint32 elapsed_time = SDL_GetTicks() - start_time;
        frame = (elapsed_time / (1000 / FRAME_RATE)) % FRAME_COUNT;

        // Xóa màn hình
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Thiết lập source rect cho frame hiện tại
        SDL_Rect srcRect = { frame * frameWidth, 0, frameWidth, frameHeight };

        // Thiết lập đích để vẽ ảnh động
        SDL_Rect destRect = { (SCREEN_WIDTH - frameWidth) / 2, (SCREEN_HEIGHT - frameHeight) / 2, frameWidth, frameHeight };

        // Vẽ frame hiện tại
        SDL_RenderCopy(renderer, texture, &srcRect, &destRect);

        // Cập nhật màn hình
        SDL_RenderPresent(renderer);

        // Giới hạn tốc độ khung hình
        SDL_Delay(1000 / FRAME_RATE);
    }

    // Giải phóng tài nguyên
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}
