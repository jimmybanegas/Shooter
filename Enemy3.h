#ifndef ENEMY3_H
#define ENEMY3_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Enemy.h"

class Enemy3 : public Enemy
{
    public:
        Enemy3(SDL_Surface *screen);
        SDL_Surface *images[6];
        void logic();
        void render();
        void jump();
        virtual ~Enemy3();
    protected:
    private:
};

#endif // ENEMY3_H
