#include "Enemy5.h"
Enemy5::Enemy5(SDL_Surface *screen, Player *player)
{
    this->player=player;
    this->screen = screen;
    this->images[0] = IMG_Load( "enemy/f1.png" );
    this->images[1] = IMG_Load( "enemy/f2.png" );
    this->images[2] = IMG_Load( "enemy/f3.png" );
    this->images[3] = IMG_Load( "enemy/f4.png" );
    this->images[4] = IMG_Load( "enemy/f5.png" );
    this->images[5] = IMG_Load( "enemy/f6.png" );
    this->x = 500;
    this->y = 250;
    this->acceleration=2;
    this->velocity=0;
    this->current_frame=0;
    //ctor
}

Enemy5::~Enemy5()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );
    SDL_FreeSurface( images[2] );
    SDL_FreeSurface( images[3] );
    SDL_FreeSurface( images[4] );
    SDL_FreeSurface( images[5] );

}

void Enemy5::logic()
{
    x-=6;
    if(x<-100)
        x=1000;



   /*if(y>50)
     y--;
   else
      y=400;
      */

}

void Enemy5::jump()
{
    velocity=-30;
}

int Enemy5::getx()
{
   return this->x;
}

int Enemy5::gety()
{
    return this->y;
}


void Enemy5::render()
{
    SDL_Rect offset;

    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;

    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    current_frame++;
    if(current_frame>2)
        current_frame=0;
}


bool Enemy5::checkCollision()
{
 if(
      (((player->getx()>= this->getx())&& (player->getx()<= this->getx()+10)) ||
    ((player->getx()+10 >= this->getx())&& (player->getx()+10 <= this->getx()+10))) &&
    (((player->gety() >= this->gety()) && (player->gety() <= this->gety()+20)) ||
    ((player->gety()+20 >= this->gety()) && (player->gety()+20 <= this->gety()+20))))
  {
   return true;
  }

  return false;
}
