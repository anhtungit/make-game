#include"texturemanager.h"


class Road
{
private:
    int screenWidth;          // Vị trí hiện tại của vạch kẻ đường theo trục X
    int lineWidth;        // Chiều rộng của mỗi vạch kẻ đường
    int lineSpeed;        // Tốc độ di chuyển của vạch kẻ đường
    int lineHeight;            // Chiều cao của mỗi vạch kẻ
    int gap;                   // Khoảng cách giữa các vạch kẻ

    std::vector<int> lineX;     // Khoảng cách giữa các vạch kẻ đường

public:
    void setroad(int startX, int width, int speed, int lineHeight, int gap);

    void update();        // Cập nhật vị trí của vạch kẻ đường
    void draw(SDL_Renderer* renderer, int screenHeight, int screenWidth);  // Vẽ mặt đường
};