#pragma once
#include "SDL_utils.h"

class GameObject {
protected:
    SDL_Rect rect;
    SDL_Texture* img_obj;
public:
    GameObject();
    GameObject(SDL_Renderer* renderer, string path);
    ~GameObject();

    void show(SDL_Renderer* renderer);

    void setImg(SDL_Renderer* renderer, string path);

    void setPos(int x, int y);

    SDL_Rect getRect();

};
