#ifndef BALA_H
#define BALA_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "Player.h"
#include <string>


class Bala
{
    public:
        int x,y;
        bool derecha;
        bool izquierda;
        bool arriba;
        bool abajo;
        int velocity;
        int acceleration;
        int current_frame;
        SDL_Surface *images[3];
        SDL_Surface *screen;

        Bala(SDL_Surface *screen, int x, int y);

        void logic();
        void render();

        virtual ~Bala();
    protected:
    private:
};

#endif // BALA_H
