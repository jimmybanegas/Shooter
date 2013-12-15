#include "Player.h"
#include "Bala.h"

Player::Player(SDL_Surface *screen)
{
    this->screen = screen;
    this->images[0] = IMG_Load( "player/1.png" );
    this->images[1] = IMG_Load( "player/2.png" );
    this->images[2] = IMG_Load( "player/3.png" );
    this->images[3] = IMG_Load( "player/4.png" );
    this->x = 90;
    this->y = 60;
    this->acceleration=2;
    this->velocity=0;
    this->current_frame=0;
    this->vida=500;
    this->score=1;
}

Player::~Player()
{
    SDL_FreeSurface( images[0] );
    SDL_FreeSurface( images[1] );
    SDL_FreeSurface( images[2] );
    SDL_FreeSurface( images[3] );
}

void Player::logic()
{
    if(y>=500-images[current_frame]->w/2)
    {
        y=500-images[current_frame]->w/2;
        velocity=0;
    }

     if(y>600)
       y=600;
     if(y<60)
        y=60;
     if(x>900)
      x=900;
     if(x<90)
        x=90;
}

void Player::jump()
{
   y+=velocity;
   velocity+=acceleration;
   velocity=-30;
}

void Player::disparar(SDL_Surface *screen)
{

}

int Player::getx()
 {
    return this->x;
 }

 int Player::gety()
 {
     return this->y;
 }

void Player::render()
{
    SDL_Rect offset;
    offset.x = x - images[current_frame]->w/2;
    offset.y = y - images[current_frame]->h/2;

    SDL_BlitSurface( images[current_frame], NULL, screen, &offset );

    current_frame++;
    if(current_frame>3)
        current_frame=0;
}
