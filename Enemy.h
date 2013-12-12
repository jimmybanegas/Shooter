#ifndef ENEMY_H
#define ENEMY_H
#include "Player.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

class Enemy
{
public:
    Player *player;
    int x,y;
    bool derecha;
    bool izquierda;
    bool arriba;
    bool abajo;
    int velocity;
    int acceleration;
    int current_frame;
    SDL_Surface *images[3];
    SDL_Surface *screen;

    Enemy();
    int getx();
    int gety();
    virtual void logic();
    virtual void render();
    virtual void jump();
    virtual bool checkCollision();
    virtual ~Enemy();
};

#endif // ENEMY_H
