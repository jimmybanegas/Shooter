#include "Enemy2.h"

Enemy2::Enemy2(SDL_Surface *screen)
{
    this->screen = screen;
    this->images[0] = IMG_Load( "enemy/bandit-interceptor1.png" );
    this->images[1] = IMG_Load( "enemy/bandit-interceptor2.png" );
    this->x = 800;
    this->y = 400;
    this->acceleration=2;
    this->velocity=0;
    this->current_frame=0;
    //ctor
}

Enemy2::~Enemy2()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );

}

void Enemy2::logic()
{
    x-=10;
    if(x<-100)
        x=1000;

   if(y>50)
     y--;
   else
      y=400;

}

void Enemy2::jump()
{
    velocity=-30;
}

void Enemy2::render()
{
    SDL_Rect offset;

    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;

    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    current_frame++;
    if(current_frame>2)
        current_frame=0;
}
