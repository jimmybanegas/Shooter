#include "Enemy3.h"

Enemy3::Enemy3(SDL_Surface *screen)
{
    this->screen = screen;
    this->images[0] = IMG_Load( "enemy/boss-tentacles1.png" );
    this->images[1] = IMG_Load( "enemy/boss-tentacles2.png" );
    this->images[2] = IMG_Load( "enemy/boss-tentacles3.png" );
    this->images[3] = IMG_Load( "enemy/boss-tentacles4.png" );
    this->images[4] = IMG_Load( "enemy/boss-tentacles5.png" );
    this->images[5] = IMG_Load( "enemy/boss-tentacles6.png" );
    this->x = 1000;
    this->y = 200;
    this->acceleration=2;
    this->velocity=0;
    this->current_frame=0;
    //ctor
}

Enemy3::~Enemy3()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );
    SDL_FreeSurface( images[2] );
    SDL_FreeSurface( images[3] );
    SDL_FreeSurface( images[4] );
    SDL_FreeSurface( images[5] );

}

void Enemy3::logic()
{
    x-=10;
    if(x<-100)
        x=1000;

   if(y>50)
     y--;
   else
      y=400;

}

void Enemy3::jump()
{
    velocity=-30;
}

void Enemy3::render()
{
    SDL_Rect offset;

    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;

    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    current_frame++;
    if(current_frame>2)
        current_frame=0;
}