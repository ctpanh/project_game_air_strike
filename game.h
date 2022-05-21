#ifndef GAME__H
#define GAME__H

#include "SDL_utils.h"
#include "GameObject.h"
#include "Plane.h"
#include "enemy.h"
#include "text.h"
#include "explosion.h"
#include "score.h"
#include "button.h"

using namespace Utils;

static SDL_Texture* backGround;
static SDL_Texture* backGroundMenu;
static bool isPlayerAlive = true;
static bool isMenu = true;
static Plane plane;
static vector<Enemy> enemies;
static vector<Explosion> explosion;
static int score = 0;
static int velEnemy = 1;
static int velBullet = 10;
static Text text, getScore;
static Button startGame, highScore, quitGame, turnBack, reset;
static GameObject gameOver;
static GameObject logo;
static Mix_Music* music;
static Mix_Chunk* expSound;


void initialize();
void setBackState();
void logicGame();
void showMenu();
void handleButtonStart();
void handleButtonQuit();
void handleButtonHighScore();
void gameLoop();

#endif // GAME__H
