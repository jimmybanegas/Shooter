#include "Bala.h"



Bala::Bala(int x, int y)
{
  //  this->screen = screen;
    //this->images[0] = IMG_Load( "player/fireball.png" );
    this->x=x;
    this->y=y;
    this->image=IMG_Load("player/laser-red.png");
    //ctor
}

Bala::~Bala()
{
   // SDL_FreeSurface( images[0] );
     //dtor
}

int Bala::getx()
{
    return this->x;

}

int Bala::gety()
{
    return this->y;

}

SDL_Surface* Bala::imagen()
{
    return this->image;

}



void Bala::draw(SDL_Surface* screen,int x,int y) {
    //Holds offsets
    SDL_Rect offset;
    //Get offsets
    offset.x = x;
    offset.y = y;
    //Blit
    SDL_BlitSurface( image, NULL, screen, &offset );

}

/*bool Bala:: checkcollision(Player *player)
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

bool Bala:: checkcollision2(Enemy enemy)
{

}
*/
