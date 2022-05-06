#include "text.h"

Text::Text()
{
    rect.w = 70;
    rect.h = 30;
    setColor(1);
}

Text::~Text()
{
}

void Text::initText(TTF_Font*& fontText)
{
    if (TTF_Init() == -1)
    {
        cout << "-1";
    }
    fontText = TTF_OpenFont("Text/arial.ttf", 20);
    if(fontText == NULL)
    {
        cout << "Lỗi font!\n";
    }
}

void Text::setText(string text)
{
    str = text;
}

void Text::setColor(const int& type)
{
    if (type == RED)
    {
        SDL_Color color = {255, 0, 0};
        text_color = color;
    }
    else if (type == WHITE)
    {
        SDL_Color color = {255, 255, 255};
        text_color = color;

    }
    else
    {
        SDL_Color color = {0, 0, 0};
        text_color = color;
    }
}

void Text::creatText(TTF_Font* font, SDL_Renderer* renderer)
{
    textSurface = TTF_RenderText_Solid(font, str.c_str(),text_color);
    img_obj = SDL_CreateTextureFromSurface(renderer, textSurface);
    show(renderer);
}
