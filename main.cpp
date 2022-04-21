#include "SDL_utils.h"

using namespace Utils;

int main(int argc, char* argv[])
{
    initSDL(window, renderer);

    SDL_Texture* newTexture = loadTexture(renderer, "bg.png");
    while(!quit) {
        while(SDL_PollEvent(&event) != 0) {
            if(event.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, newTexture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }
    quitSDL(window, renderer);
    return 0;
}
