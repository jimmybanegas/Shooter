#ifndef ENEMY6_H
#define ENEMY6_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Enemy.h"
#include "Player.h"
using namespace std;

class Enemy6 : public Enemy
{
    public:
        Enemy6(SDL_Surface *screen, Player *player);
                Player *player;

        SDL_Surface *images[4];
        void logic();
        void render();
        void jump();
        int getx();
        int gety();
           bool checkCollision();
        virtual ~Enemy6();
    protected:
    private:
};

#endif // ENEMY6_H
