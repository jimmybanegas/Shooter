#ifndef ENEMY_H
#define ENEMY_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include <vector>
#include "Player.h"
#include "Bala.h"

using namespace std;

class Enemy
{
public:
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

    //Player *player;
    virtual int getx();
    virtual int gety();
    virtual void logic();
    virtual void render();
    virtual void jump();

    Enemy();
    virtual ~Enemy();

protected:
private:
};

#endif // ENEMY_H


