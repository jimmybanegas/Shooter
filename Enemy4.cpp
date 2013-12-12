#include "Enemy4.h"

Enemy4::Enemy4(SDL_Surface *screen, Player *player)
{
    this->player=player;
    this->screen = screen;
    this->images[0] = IMG_Load( "enemy/e_f1.png" );
    this->images[1] = IMG_Load( "enemy/e_f2.png" );
    this->images[2] = IMG_Load( "enemy/e_f3.png" );
    this->images[3] = IMG_Load( "enemy/e_f4.png" );
    this->images[4] = IMG_Load( "enemy/e_f5.png" );
    this->images[5] = IMG_Load( "enemy/e_f6.png" );

    this->x = 700;
    this->y = 400;
    this->acceleration=2;
    this->velocity=0;
    this->current_frame=0;
    //ctor
}

Enemy4::~Enemy4()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );
    SDL_FreeSurface( images[2] );
    SDL_FreeSurface( images[3] );
    SDL_FreeSurface( images[4] );
    SDL_FreeSurface( images[5] );

}

void Enemy4::logic()
{
    if(checkCollision())
        this->player->vida-=5;

    x-=5;
    if(x<-100)
        x=1000;

/*   if(y>50)
     y--;
   else
      y=400;*/

}

void Enemy4::jump()
{
    velocity=-30;
}

void Enemy4::render()
{
    SDL_Rect offset;

    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;

    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    current_frame++;
    if(current_frame>2)
        current_frame=0;
}

