#include "GameObject.h"

GameObject::GameObject(){
    rect.x = 10;
    rect.y = 10;
    rect.w = 100;
    rect.h = 100;
    img_obj = NULL;
}

GameObject::GameObject(SDL_Renderer* renderer, string path){
    rect.x = 10;
    rect.y = 10;
    rect.w = 100;
    rect.h = 100;
    img_obj = Utils::loadTexture(renderer, path);
}

GameObject::~GameObject(){

}

void GameObject::show(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, img_obj, NULL, &rect);
}

void GameObject::setImg(SDL_Renderer* renderer, string path){
    img_obj = Utils::loadTexture(renderer, path);
}

void GameObject::setPos(int x, int y) {
    rect.x = x;
    rect.y = y;
}

SDL_Rect GameObject::getRect() {
    return rect;
}
