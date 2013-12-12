#include "Enemy.h"
#include "Player.h"

Enemy::Enemy()
{
  //  this->screen = screen;
    /*this->images[0] = IMG_Load( "enemy/1.png" );
    this->images[1] = IMG_Load( "enemy/2.png" );
    this->images[2] = IMG_Load( "enemy/3.png" );
    this->x = 1000;
    this->y = 400;
    this->acceleration=2;
    this->velocity=0;
    this->current_frame=0;*/
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
    if(checkCollision())
        this->player->vida-=5;

    x-=10;
    if(x<-100)
        x=1000;

 /*  if(y>50)
     y--;
   else
      y=400;*/

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

    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    current_frame++;
    if(current_frame>2)
        current_frame=0;
}

bool Enemy::checkCollision()
{
 if(
    (((player->getx()>= this->getx())&& (player->getx() <= this->getx()+50)) ||
    ((player->getx()+50 >= this->getx())&& (player->getx()+50 <= this->getx()+50))) &&
    (((player->gety() >= this->gety()) && (player->gety() <= this->gety()+100)) ||
    ((player->gety()+100 >= this->gety()) && (player->gety()+100 <= this->gety()+100))))
  {
   return true;
  }
  else
  {
    return false;
  }
  return false;
}


