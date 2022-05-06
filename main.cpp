#include "SDL_utils.h"
#include "Plane.h"
#include "enemy.h"
#include "text.h"

using namespace Utils;

int main(int argc, char* argv[])
{
    srand(time(0));
    initSDL(window, renderer);

    SDL_Texture* newTexture = loadTexture(renderer, "Image/bg.png");

    Plane plane(renderer);
    plane.setImg(renderer, "Image/plane.png");
    Bullet b;
    vector<Enemy> enemies;
    Text text;
    text.initText(fontText);
    int score = 0;
    for (int i = 0; i < 6; i++)
    {
        Enemy enemy(renderer, i);
        int x = rand()%SCREEN_WIDTH - enemy.getRect().w;
        int y = rand()%SCREEN_HEIGHT/4;
        enemy.setPos(x, y);
        enemies.push_back(enemy);
    }
    while(!quit) {
        while(SDL_PollEvent(&event) != 0) {
            if(event.type == SDL_QUIT) {
                quit = true;
            }
            SDL_ShowCursor(SDL_DISABLE);
            plane.move(event);
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, newTexture, NULL, NULL);
        plane.update(renderer);
        for (int i = 1; i < 7; i++)
        {
            if (enemies.at(i-1).isKilled()){
                if((checkCollision(enemies.at(i-1).getRect(), plane.getRectBullet())))
                {
                    enemies.at(i-1).dead();
                    score += 1;
                    break;
                }
                enemies.at(i-1).update(renderer);
            }
        }
        text.setText("Score:" + to_string(score));
        text.creatText(fontText,renderer);
        SDL_RenderPresent(renderer);
    }

    quitSDL(window, renderer);
    return 0;
}
