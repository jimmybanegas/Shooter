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
    this->vida=30;
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

void Enemy4::logic(vector<Bala*>bullets, SDL_Surface *screen, Player *player)
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

 for(int x=0;x<this->bullets.size();x++)
   {
     if((((this->bullets[x]->getx()>= player->getx())&& (this->bullets[x]->getx()<= player->getx()+10)) ||
        ((this->bullets[x]->getx()+10 >= player->getx())&& (this->bullets[x]->getx()+10 <= player->getx()+10))) &&
        (((this->bullets[x]->gety() >= player->gety()) && (this->bullets[x]->gety() <= player->gety()+20)) ||
        ((this->bullets[x]->gety()+20 >= player->gety()) && (this->bullets[x]->gety()+20 <= player->gety()+20))))
    {
      player->vida-=0.5;
    }
   }

    x-=5;
    if(x<-100)
        x=1000;

    disparar(screen);
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

    if(vida>0)
    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    current_frame++;
    if(current_frame>2)
        current_frame=0;
}

int Enemy4::getx()
{
   return this->x;
}

int Enemy4::gety()
{
    return this->y;
}

int Enemy4::getvida()
{
    return this->vida;
}


bool Enemy4::checkCollision()
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

void Enemy4::disparar(SDL_Surface * screen)
{
   for(int i=0;i<bullets.size();i++){
    bullets[i]->draw(screen,bullets[i]->x,bullets[i]->y);
    bullets[i]->x-=50;
   }
}
