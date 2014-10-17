#include "Bala.h"



Bala::Bala(int x, int y)
{
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
