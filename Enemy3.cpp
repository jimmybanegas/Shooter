#include "Enemy3.h"

Enemy3::Enemy3(SDL_Surface *screen, Player *player)
{
    this->player=player;
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
    this->vida=10;
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

void Enemy3::logic(vector<Bala*>bullets)
{
   for(int x=0;x<bullets.size();x++)
   {
     if((((bullets[x]->getx()>= this->getx())&& (bullets[x]->getx()<= this->getx()+10)) ||
        ((bullets[x]->getx()+10 >= this->getx())&& (bullets[x]->getx()+10 <= this->getx()+10))) &&
        (((bullets[x]->gety() >= this->gety()) && (bullets[x]->gety() <= this->gety()+20)) ||
        ((bullets[x]->gety()+20 >= this->gety()) && (bullets[x]->gety()+20 <= this->gety()+20))))
    {
      this->vida-=5;
    }
   }

    x-=7;
    if(x<-100)
        x=1000;


    /* y--;
   else
      y=400;*/

}

void Enemy3::jump()
{
    velocity=-30;
}

int Enemy3::getx()
{
   return this->x;
}

int Enemy3::gety()
{
    return this->y;
}

void Enemy3::render()
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

bool Enemy3::checkCollision()
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
