#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::~Enemy()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );
    SDL_FreeSurface( images[2] );
    SDL_FreeSurface( images[3] );
}

void Enemy::logic()
{
    x-=10;
    if(x<-100)
        x=1000;
}

void Enemy::jump()
{
    velocity=-30;
}

int Enemy::getx()
{
   return this->x;
}

int Enemy::gety()
{
    return this->y;
}

void Enemy::render()
{
    SDL_Rect offset;

    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;

   if(vida>0)
    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    current_frame++;
    if(current_frame>2)
        current_frame=0;
}


