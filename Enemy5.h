#ifndef ENEMY5_H
#define ENEMY5_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Enemy.h"

class Enemy5 : public Enemy
{
    public:
        Enemy5(SDL_Surface *screen);
        SDL_Surface *images[6];
        void logic();
        void render();
        void jump();
        virtual ~Enemy5();
    protected:
    private:
};

#endif // ENEMY5_H
