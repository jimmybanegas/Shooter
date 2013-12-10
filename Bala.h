#ifndef BALA_H
#define BALA_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>

#include "SDL/SDL_image.h"

class Bala
{
    public:
        Bala(int x, int y);
        virtual ~Bala();

        void draw(SDL_Surface* screen, int x, int y);

        bool exists;
        int x;
        int y;
        SDL_Surface* image;
        //int speedX;
        //int speedY;
      //  int damage;
       // int flightType;


    protected:
    private:
};

#endif // BALA_H
