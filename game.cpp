#include "game.h"

void initialize()
{
    initSDL(window, renderer);
    backGround = loadTexture(renderer, "Image/bg.png");
    backGroundMenu = loadTexture(renderer, "Image/bgMenu.png");

    plane.initPlane(renderer);

    getScore.setColor(0);
    getScore.setRect(100,100);
    getScore.setPos(SCREEN_WIDTH/2 - getScore.getRect().w/2, SCREEN_HEIGHT/2 - getScore.getRect().h/2);

    startGame.setImg(renderer, "Image/button_play.png");
    startGame.setPos(SCREEN_WIDTH / 2 - startGame.getRect().w / 2, SCREEN_HEIGHT / 2 - startGame.getRect().h/2);
    highScore.setImg(renderer, "Image/button_highScore.png");
    highScore.setPos(SCREEN_WIDTH / 2 - highScore.getRect().w / 2, SCREEN_HEIGHT / 2 + highScore.getRect().h/2 + 10);
    quitGame.setImg(renderer, "Image/button_quit.png");
    quitGame.setPos(SCREEN_WIDTH / 2 - quitGame.getRect().w / 2, SCREEN_HEIGHT / 2 + 3*quitGame.getRect().h/2 + 20);
    turnBack.setImg(renderer,"Image/button_back.png");
    turnBack.setPos(0,20);
    reset.setImg(renderer,"Image/button_reset.png");
    reset.setPos(SCREEN_WIDTH/2 - reset.getRect().w/2, SCREEN_HEIGHT/2 + reset.getRect().h/2 + 20);

    gameOver.setImg(renderer, "Image/gameOver.png");
    gameOver.setRect(500, 500);
    gameOver.setPos(SCREEN_WIDTH / 2 - gameOver.getRect().w/2, SCREEN_HEIGHT / 3 - gameOver.getRect().h/2);
    logo.setImg(renderer, "Image/logo.png");
    logo.setRect(300, 300);
    logo.setPos(SCREEN_WIDTH / 2 - logo.getRect().w / 2, SCREEN_HEIGHT / 2 - 4*startGame.getRect().h + 30);

    music = Mix_LoadMUS("Music/wind.wav");
    expSound = Mix_LoadWAV("Music/awp.wav");

    for (int i = 0; i < 4; i++)
    {
        Explosion exp(renderer, i);
        explosion.push_back(exp);
    }

    for (int i = 0; i < 3; i++)
    {
        Enemy enemy(renderer, i);
        enemy.createBullet(renderer);
        enemies.push_back(enemy);
    }
}

void setBackState()
{
    isPlayerAlive = true;
    score = 0;
    velEnemy = 1;
    velBullet = 10;
    // Tat hien thi chuot tren man hinh
    SDL_ShowCursor(SDL_DISABLE);
    plane.setPos(SCREEN_WIDTH/2, SCREEN_HEIGHT*3/4);
    plane.clearBullet();
    for (int i = 0; i < 3; i++)
    {
        enemies[i].setPos(rand() % (SCREEN_WIDTH - enemies[i].getRect().w), -enemies[i].getRect().h);
        vector<Bullet*> enemyBulletList;
        enemyBulletList = enemies[i].getBulletList();
        for (int j = 0; j < enemyBulletList.size(); j++)
        {
            enemyBulletList[j]->setPos(enemies[i].getRect().x + enemies[i].getRect().w / 2 - 10, enemies[i].getRect().y + enemies[i].getRect().h);
        }
    }
    // Delay 0.5s roi vao game
    SDL_Delay(500);
}

void logicGame()
{
    for (int i = 0; i < 3; i++)
    {
        enemies[i].update(renderer,velEnemy);
        enemies[i].enemyBullet(renderer, velBullet);

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
            isMenu = true;
            isPlayerAlive = false;
            SDL_ShowCursor(SDL_ENABLE);
            SDL_Delay(1000);
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
                isMenu = true;
                isPlayerAlive = false;
                SDL_ShowCursor(SDL_ENABLE);
                SDL_Delay(1000);
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
            gameOver.show(renderer);
            getScore.initText(fontText, "Score:" + to_string(score),1000);
            getScore.creatText(fontText,renderer);
            SDL_RenderPresent(renderer);
            isMenu = true;
            isPlayerAlive = false;
            SDL_ShowCursor(SDL_ENABLE);
            SDL_Delay(1000);
            break;
        }
        if (score > 10)
        {
            velEnemy = 2;
            velBullet = 11;
        }
        if (score > 20)
        {
            velEnemy = 3;
            velBullet = 12;
        }
    }
}

void showMenu()
{
    SDL_RenderCopy(renderer, backGroundMenu, NULL, NULL);
    Mix_HaltMusic();
    if(!Mix_PlayingMusic())
    {
        Mix_PlayMusic(music, -1);
    }
    logo.show(renderer);
    startGame.show(renderer);
    highScore.show(renderer);
    quitGame.show(renderer);
    SDL_RenderPresent(renderer);
}

void handleButtonStart()
{
    if(startGame.input(event))
    {
        setBackState();
        // Tro choi chinh
        while(isPlayerAlive)
        {
            // Delay 10 ms
            SDL_Delay(1);

            // Trong khi co su kien
            while(SDL_PollEvent(&event))
            {
                if(event.type == SDL_QUIT)
                {
                    isPlayerAlive = false;
                    isMenu = false;
                    break;
                }
                plane.move(event);
            }
            SDL_RenderCopy(renderer, backGround, NULL, NULL);
            plane.update(renderer);

            logicGame();

            text.initText(fontText, "Score:" + to_string(score),40);
            text.creatText(fontText,renderer);
            SDL_RenderPresent(renderer);
            SDL_RenderClear(renderer);
        }
        if (score > Score::getBestScore())
        {
            Score::setBestScore(score);
        }
    }
}

void handleButtonQuit()
{
    if (quitGame.input(event))
    {
        isMenu = false;
        isPlayerAlive = false;
    }
}

void handleButtonHighScore()
{
    if (highScore.input(event))
    {
        bool isHighScore = true;
        SDL_RenderCopy(renderer, backGroundMenu, NULL, NULL);
        while (isHighScore)
        {
            Text highScoreT;
            highScoreT.initText(fontText,"HIGH SCORE: " + to_string(Score::getBestScore()),100);
            highScoreT.setRect(200,100);
            highScoreT.setColor(3);
            highScoreT.setPos(SCREEN_WIDTH/2 - highScoreT.getRect().w/2,SCREEN_HEIGHT/2 - highScoreT.getRect().h/2);
            highScoreT.creatText(fontText, renderer);
            turnBack.show(renderer);
            reset.show(renderer);
            SDL_RenderPresent(renderer);
            while(SDL_PollEvent(&event))
            {

                if(event.key.keysym.sym == SDLK_ESCAPE)
                {
                    isHighScore = false;
                    break;
                }
                else if (reset.input(event))
                {
                    Score::setBestScore(0);
                    isHighScore = false;
                    break;
                }
                else if (turnBack.input(event))
                {
                    isHighScore = false;
                    break;
                }
                else if(event.type == SDL_QUIT)
                {
                    isHighScore = false;
                    isMenu = false;
                    break;
                }
            }
        }
    }

}

void gameLoop()
{
    while(isMenu)
    {
        showMenu();
        while(SDL_PollEvent(&event))
        {
            handleButtonStart();
            handleButtonQuit();
            handleButtonHighScore();
        }
    }
}
