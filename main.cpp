#include "game.h"

int main(int argc, char* argv[])
{
    srand(time(0));
    initialize();
    gameLoop();
    quitSDL(window, renderer);
    return 0;
}
