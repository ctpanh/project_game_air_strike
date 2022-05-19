#include "SDL_utils.h"
#include "GameObject.h"
#include "Plane.h"
#include "enemy.h"
#include "text.h"
#include "explosion.h"

using namespace Utils;

int main(int argc, char* argv[])
{
    srand(time(0));
    initSDL(window, renderer);

    SDL_Texture* newTexture = loadTexture(renderer, "Image/bg.png");

    GameObject gameOver;
    gameOver.setImg(renderer, "Image/gameOver.png");
    gameOver.setRect(500, 500);
    gameOver.setPos(SCREEN_WIDTH / 2 - gameOver.getRect().w/2, SCREEN_HEIGHT / 3 - gameOver.getRect().h/2);

    Plane plane(renderer);
    bool isPlayerAlive = true;
    vector<Enemy> enemies;
    vector<Explosion> explosion;

    Mix_Music* music = Mix_LoadMUS("Music/wind.wav");
    Mix_Chunk* expSound = Mix_LoadWAV("Music/awp.wav");

    for (int i = 0; i < 4; i++)
    {
        Explosion exp(renderer, i);
        explosion.push_back(exp);
    }
    int score = 0;

    Text text, getScore;
    getScore.setColor(0);
    getScore.setRect(100,100);
    getScore.setPos(SCREEN_WIDTH/2 - getScore.getRect().w/2, SCREEN_HEIGHT/2 - getScore.getRect().h/2);

    for (int i = 0; i < 3; i++)
    {
        Enemy enemy(renderer, i);
        enemy.createBullet(renderer);
        enemies.push_back(enemy);
    }

    while(!quit)
    {
        while (isPlayerAlive)
        {
            Mix_HaltMusic();
            if(!Mix_PlayingMusic())
            {
                Mix_PlayMusic(music, -1);
            }

            while(SDL_PollEvent(&event) != 0)
            {
                if(event.type == SDL_QUIT)
                {
                    quit = true;
                    isPlayerAlive = false;
                }
                SDL_ShowCursor(SDL_DISABLE);
                plane.move(event);
            }
            SDL_RenderClear(renderer);
            SDL_RenderCopy(renderer, newTexture, NULL, NULL);
            plane.update(renderer);
            for (int i = 0; i < 3; i++)
            {
                enemies[i].update(renderer);
                enemies[i].enemyBullet(renderer);

                if(checkCollision(enemies[i].getRect(), plane.getRect()))
                {
                    Mix_PlayChannel(-1, expSound, 0);
                    vector<Explosion> exp;
                    exp = explosion;
                    for (int k = 0; k < 4; k++)
                    {
                        exp[k].setPos(enemies[i].getRect().x, enemies[i].getRect().y);
                        exp[k].show(renderer);
                        SDL_Delay(50);
                    }
                    gameOver.show(renderer);
                    getScore.initText(fontText, "Score:" + to_string(score),1000);
                    getScore.creatText(fontText,renderer);
                    SDL_RenderPresent(renderer);
                    quit = true;
                    isPlayerAlive = false;
                    SDL_ShowCursor(SDL_ENABLE);
                    SDL_Delay(2000);
                    break;
                }

                vector<Bullet*> enemyBulletList;
                enemyBulletList = enemies[i].getBulletList();
                for (int j = 0; j < enemyBulletList.size(); j++)
                {
                    if(checkCollision(enemyBulletList[j]->getRect(),plane.getRect()))
                    {
                        Mix_PlayChannel(-1, expSound, 0);
                        vector<Explosion> exp;
                        exp = explosion;
                        for (int k = 0; k < 4; k++)
                        {
                            exp[k].setPos(plane.getRect().x, plane.getRect().y);
                            exp[k].show(renderer);
                            SDL_Delay(50);
                        }

                        gameOver.show(renderer);
                        getScore.initText(fontText, "Score:" + to_string(score),1000);
                        getScore.creatText(fontText,renderer);
                        SDL_RenderPresent(renderer);
                        quit = true;
                        isPlayerAlive = false;
                        SDL_ShowCursor(SDL_ENABLE);
                        SDL_Delay(2000);
                        break;
                    }
                }
                if((checkCollision(enemies[i].getRect(), plane.getRectBullet())))
                {
                    Mix_PlayChannel(-1, expSound, 0);
                    plane.clearBullet();
                    vector<Explosion> exp;
                    exp = explosion;
                    for (int k = 0; k < 4; k++)
                    {
                        exp[k].setPos(enemies[i].getRect().x, enemies[i].getRect().y);
                        exp[k].show(renderer);
                    }
                    score ++;
                    enemies[i].resetPos();
                    break;
                }
                if (enemies[i].getRect().y > SCREEN_HEIGHT)
                {
                    quit = true;
                    isPlayerAlive = false;
                    SDL_ShowCursor(SDL_ENABLE);
                    break;
                }
            }
            text.initText(fontText, "Score:" + to_string(score),40);
            text.creatText(fontText,renderer);
            SDL_RenderPresent(renderer);
        }
    }

    quitSDL(window, renderer);
    return 0;
}
