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
    this->vida=10;
    //ctor
}

Enemy6::~Enemy6()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );
    SDL_FreeSurface( images[2] );
    SDL_FreeSurface( images[3] );

}

void Enemy6::logic(vector<Bala*>bullets)
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

    x-=8;
    if(x<-100)
        x=1000;

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

   if(vida>0)
    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    current_frame++;
    if(current_frame>2)
        current_frame=0;
}


int Enemy6::getx()
{
   return this->x;
}

int Enemy6::gety()
{
    return this->y;
}

bool Enemy6::checkCollision()
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
