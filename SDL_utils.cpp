#include "SDL_utils.h"
using namespace std;

namespace Utils {
void logSDLError(std::ostream& os, const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);


    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);

    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
void refresh_screen(const SDL_Rect& rect, SDL_Renderer* renderer)
{
    //Đặt màu đen, xóa toàn bộ màn hình về màu đen
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer,255,255,255,255);
    SDL_RenderFillRect(renderer,&rect);
    SDL_RenderPresent(renderer);
}

SDL_Texture* loadTexture(SDL_Renderer* renderer, const string &path)
{
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);
    return newTexture;
}

void render_texture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void renderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y, int w, int h)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
    rect.w = w;
    rect.h = h;
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}

}