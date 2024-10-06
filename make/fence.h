#include "texturemanager.h"


class Fence {
public:
    void setfence(int Width, int width, int height, int speed, int gap);
    void update();
    void draw(SDL_Renderer* renderer, int screenWidth, int screenHeight);

private:
    int screenWidth;   
    int fenceWidth; // Chiều rộng của lan can
    int fenceHeight; // Chiều cao của lan can
   
    int speedfence;
    int Gap;                   // Khoảng cách giữa các hàng rào

    std::vector<int> fenceX;
};
