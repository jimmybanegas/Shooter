#include "Enemy6.h"

Enemy6::Enemy6(SDL_Surface *screen, Player *player)
{
    this->player=player;
    this->screen = screen;
    this->images[0] = IMG_Load( "enemy/flying-saucer1.png" );
    this->images[1] = IMG_Load( "enemy/flying-saucer2.png" );
    this->images[2] = IMG_Load( "enemy/flying-saucer3.png" );
    this->images[3] = IMG_Load( "enemy/flying-saucer4.png" );
    this->x = 400;
    this->y = 320;
    this->acceleration=2;
    this->velocity=0;
    this->current_frame=0;
    //ctor
}

Enemy6::~Enemy6()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );
    SDL_FreeSurface( images[2] );
    SDL_FreeSurface( images[3] );

}

void Enemy6::logic()
{
    if(checkCollision())
        this->player->vida-=5;

    x-=8;
    if(x<-100)
        x=1000;

   /*if(y>50)
     y--;
   else
      y=400;*/

}

void Enemy6::jump()
{
    velocity=-30;
}

void Enemy6::render()
{
    SDL_Rect offset;

    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;

    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    current_frame++;
    if(current_frame>2)
        current_frame=0;
}
