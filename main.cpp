#include "make/gameloop.h"


gameloop* g = new gameloop();

int main(int argc, char** argv)
{
    g->Init();
    while(g->getGameState())
    {
        g->Render();
        g->Event();
        g->update();
    }
    g->Clear();
    return 0;
}