#include "Bala.h"

Bala::Bala(int x, int y)
{
  //  this->screen = screen;
    //this->images[0] = IMG_Load( "player/fireball.png" );
    this->x = x+70;
    this->y = y;
    //this->acceleration=2;
    //this->velocity=0;
    //this->current_frame=0;
   // this->x=x;
    //this->y=y;
    this->image=IMG_Load("player/fireball.png");
    //ctor
}

Bala::~Bala()
{
   // SDL_FreeSurface( images[0] );
     //dtor
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
