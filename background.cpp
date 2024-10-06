
#include "make/background.h"

void drawMountains(SDL_Renderer* renderer,int width, int height ) {
        int previousX = 0;
    int previousY = 300 + 20 * sin(0);  // Điểm bắt đầu của núi

    for (int x = 0; x <= width; x += 10) {  // Vẽ các đỉnh núi với bước nhảy x = 10
        // Sử dụng hàm sin để tính chiều cao của đỉnh núi
        int y = 300 + 20 * sin(x * PI / 180);  // Hàm sin thay đổi theo x để tạo hình núi

        // Vẽ đường nối từ điểm trước đến điểm mới
        SDL_RenderDrawLine(renderer, previousX, previousY, x, y);

        // Tô màu bằng cách vẽ tam giác từ điểm (x,y) đến chân màn hình
        SDL_SetRenderDrawColor(renderer, 0, 0, 150, 255);  // Màu xanh lá cây cho đồi
        for (int i = previousX; i < x; i++) {
            SDL_RenderDrawLine(renderer, i, height, i, previousY + (y - previousY) * (i - previousX) / (x - previousX));
        }

        // Cập nhật điểm trước
        previousX = x;
        previousY = y;
    }

    // Vẽ đường từ điểm cuối đến cạnh phải của màn hình để đóng đồi núi
    SDL_RenderDrawLine(renderer, previousX, previousY,width, height);
    for (int i = previousX; i <width; i++) {
        SDL_RenderDrawLine(renderer, i, height, i, previousY);
    }

     SDL_SetRenderDrawColor(renderer, 34, 139, 34, 255);                            // Màu xanh lá cây
     SDL_Rect ground = {0, 370, width, height / 3}; // Chiếm 1/3 màn hình dưới cùng
     SDL_RenderFillRect(renderer, &ground);
}


