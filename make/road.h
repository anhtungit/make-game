#include"texturemanager.h"


class Road
{
private:
    int lineX;            // Vị trí hiện tại của vạch kẻ đường theo trục X
    int lineWidth;        // Chiều rộng của mỗi vạch kẻ đường
    int lineSpeed;        // Tốc độ di chuyển của vạch kẻ đường
    int lineSpacing;      // Khoảng cách giữa các vạch kẻ đường

public:
    void setroad(int startX, int width, int speed, int spacing);

    void update();        // Cập nhật vị trí của vạch kẻ đường
    void draw(SDL_Renderer* renderer, int screenWidth, int screenHeight);  // Vẽ mặt đường
};