#ifndef ENEMY2_H
#define ENEMY2_H
#include "Player.h"
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Enemy.h"

class Enemy2 : public Enemy
{
    public:
        Enemy2(SDL_Surface *screen, Player *player);
                Player *player;

        SDL_Surface *images[2];
        void logic();
        void render();
        void jump();
        int getx();
        int gety();
        bool checkCollision();
        virtual ~Enemy2();
    protected:
    private:
};

#endif // ENEMY2_H
