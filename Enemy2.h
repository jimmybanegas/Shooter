#ifndef ENEMY2_H
#define ENEMY2_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Enemy.h"

class Enemy2 : public Enemy
{
    public:
        Enemy2(SDL_Surface *screen);
        SDL_Surface *images[2];
        void logic();
        void render();
        void jump();
        virtual ~Enemy2();
    protected:
    private:
};

#endif // ENEMY2_H
