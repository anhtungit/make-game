
#include "texturemanager.h"


const int SUN_RADIUS = 50;  // Bán kính của mặt trời

class Sun
{
private:
    float x, y;  // Vị trí hiện tại của mặt trời
    float speedY;
    int sunMinY, sunMaxY;  // Giới hạn của mặt trời

public:
    void setsun(float startX, float startY, int minY, int maxY);

    void update();  // Cập nhật vị trí của mặt trời

    float getX() const;  // Lấy vị trí X của mặt trời
    float getY() const;  // Lấy vị trí Y của mặt trời

    static void drawGradientSun(SDL_Renderer* renderer, int x, int y, int radius);  // Vẽ mặt trời với hiệu ứng gradient
};