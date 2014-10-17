#include "Bala2.h"

Bala2::Bala2(int x, int y)
{
    this->x=x;
    this->y=y;
    this->image=IMG_Load("player/fireball.png");   //ctor
}

Bala2::~Bala2()
{
    //dtor
}

int Bala2::getx()
{
    return this->x;

}

int Bala2::gety()
{
    return this->y;

}

SDL_Surface* Bala2::imagen()
{
    return this->image;

}

void Bala2::draw(SDL_Surface* screen,int x,int y) {
    //Holds offsets
    SDL_Rect offset;
    //Get offsets
    offset.x = x;
    offset.y = y;
    //Blit
    SDL_BlitSurface( image, NULL, screen, &offset );

}
