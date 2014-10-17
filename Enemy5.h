#ifndef ENEMY5_H
#define ENEMY5_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Enemy.h"
#include "Player.h"
#include "Bala.h"

using namespace std;

class Enemy5 : public Enemy
{
    public:
        Enemy5(SDL_Surface *screen, Player *player);
                Player *player;

        SDL_Surface *images[6];
        void logic(vector<Bala*>bullets);
        void render();
        void jump();
        int getx();
        int gety();
        int getvida();
          bool checkCollision();
        virtual ~Enemy5();
    protected:
    private:
};

#endif // ENEMY5_H
