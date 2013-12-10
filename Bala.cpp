#include "Bala.h"

Bala::Bala(SDL_Surface *screen, int x, int y)
{
    this->screen = screen;
    this->images[0] = IMG_Load( "player/fireball.png" );
    this->x = x+70;
    this->y = y;
    this->acceleration=2;
    this->velocity=0;
    this->current_frame=0;
    //ctor
}

Bala::~Bala()
{
    SDL_FreeSurface( images[0] );
     //dtor
}


void Bala::render()
{
    SDL_Rect offset;

    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;

    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    current_frame++;
    if(current_frame>2)
        current_frame=0;
}
