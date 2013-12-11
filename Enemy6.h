#ifndef ENEMY6_H
#define ENEMY6_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Enemy.h"

class Enemy6 : public Enemy
{
    public:
        Enemy6(SDL_Surface *screen);
        SDL_Surface *images[4];
        void logic();
        void render();
        void jump();
        virtual ~Enemy6();
    protected:
    private:
};

#endif // ENEMY6_H
