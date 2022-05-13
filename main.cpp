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
    bool isPlayerAlive = true;
    //Bullet b;
    vector<Enemy> enemies;
    Text text;
    text.initText(fontText);
    int score = 0;
    while(!quit) {
        while (isPlayerAlive)
        {
            for (int i = 0; i < 6; i++)
            {
                Enemy enemy(renderer, i);
                enemy.setPos(rand() % (SCREEN_WIDTH - enemy.getRect().w), 0);
                enemy.createBullet();
                enemies.push_back(enemy);
            }
            while(SDL_PollEvent(&event) != 0) {
                if(event.type == SDL_QUIT) {
                    quit = true;
                    isPlayerAlive = false;
                }
                SDL_ShowCursor(SDL_DISABLE);
                plane.move(event);
            }
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, newTexture, NULL, NULL);
            plane.update(renderer);
            for (int i = 0; i < 6; i++)
            {
                if (enemies[i].isEnemyAlive()){
                    if((checkCollision(enemies[i].getRect(), plane.getRectBullet())))
                    {
                        enemies[i].dead();
                        enemies.erase(enemies.begin()+i);
                        score += 1;
                        break;
                    }
                    enemies[i].update(renderer);
                    enemies[i].enemyBullet(renderer);
                }
                if (enemies[i].getRect().y > SCREEN_HEIGHT)
                {
                    quit = true;
                    isPlayerAlive = false;
                    break;
                }
            }
            text.setText("Score:" + to_string(score));
            text.creatText(fontText,renderer);
            SDL_RenderPresent(renderer);
        }
    }

    quitSDL(window, renderer);
    return 0;
}
