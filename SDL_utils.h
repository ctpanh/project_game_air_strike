#ifndef SDL_UTILS__H
#define SDL_UTILS__H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <vector>
#include <time.h>
#include <string>

using namespace std;

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 800;
const string WINDOW_TITLE = "Air Strike";

static SDL_Window* window;
static SDL_Renderer* renderer;
static SDL_Event event;
static TTF_Font* fontText = NULL;

namespace Utils {
    void logSDLError(std::ostream& os, const std::string &msg, bool fatal);

    void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

    void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

    SDL_Texture* loadTexture(SDL_Renderer* renderer, const string &path);

    bool checkCollision(SDL_Rect a, SDL_Rect b);

}
#endif // SDL_UTILS__H
