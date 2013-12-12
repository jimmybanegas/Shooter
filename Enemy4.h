#ifndef ENEMY4_H
#define ENEMY4_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Enemy.h"

class Enemy4 : public Enemy
{
    public:
        Enemy4(SDL_Surface *screen, Player *player);
        SDL_Surface *images[6];
        void logic();
        void render();
        void jump();
        virtual ~Enemy4();
    protected:
    private:
};

#endif // ENEMY4_H
