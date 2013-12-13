#ifndef ENEMY3_H
#define ENEMY3_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Enemy.h"
#include "Player.h"
class Enemy3 : public Enemy
{
    public:
        Enemy3(SDL_Surface *screen, Player *player);
                Player *player;

        SDL_Surface *images[6];
        void logic();
        void render();
        void jump();
        int getx();
        int gety();
            bool checkCollision();
        virtual ~Enemy3();
    protected:
    private:
};

#endif // ENEMY3_H
