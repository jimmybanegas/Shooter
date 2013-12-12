#ifndef PLAYER_H
#define PLAYER_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Bala.h"
using namespace std;

class Player
{
public:
    int x;
    int y;
    int velocity;
    int acceleration;
    int vida;
    int current_frame;
    SDL_Surface *images[4];
    SDL_Surface *screen;
    Bala *balas;

    Player(SDL_Surface *screen);
    void logic();
    void render();
    void jump();
    int getx();
    int gety();
    void disparar(SDL_Surface*screen);
    virtual ~Player();
};

#endif // PLAYER_H
