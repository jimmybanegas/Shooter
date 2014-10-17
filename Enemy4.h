#ifndef ENEMY4_H
#define ENEMY4_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "Enemy.h"
#include "Player.h"
#include "Bala.h"

using namespace std;

class Enemy4 : public Enemy
{
    public:
        Enemy4(SDL_Surface *screen, Player *player);
        Player *player;

        SDL_Surface *images[6];
        void logic(vector<Bala*>bullets,SDL_Surface *screen, Player *player);
        vector<Bala*>bullets;
        void disparar(SDL_Surface *screen);
        void render();
        void jump();
        int getx();
        int gety();
        int getvida();
        bool checkCollision();
        virtual ~Enemy4();
    protected:
    private:
};

#endif // ENEMY4_H
