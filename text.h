#ifndef TEXT__H
#define TEXT__H

#include "GameObject.h"

class Text : public GameObject
{
private:
    string str;
    SDL_Color text_color;
    SDL_Surface* textSurface;
public:
    enum TextColor
    {
        RED = 0,
        WHITE = 1,
        BLACK = 2,
    };
    Text();
    ~Text();
    void initText(TTF_Font*& fontText);
    void setText(string text);
    void setColor(const int& type);
    void creatText(TTF_Font* font, SDL_Renderer* renderer);
};
#endif // TEXT__H

