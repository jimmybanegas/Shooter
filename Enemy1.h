#ifndef ENEMY1_H
#define ENEMY1_H
#include "Player.h"
#include "Enemy.h"

class Enemy1 : public Enemy
{
    public:
        Enemy1(SDL_Surface *screen, Player *player);
        Player *player;
        void logic();
        void render();
        void jump();
        int getx();
        int gety();
        bool checkCollision();

        virtual ~Enemy1();
    protected:
    private:
};

#endif // ENEMY1_H
