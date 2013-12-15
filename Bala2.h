#ifndef BALA2_H
#define BALA2_H
#include "Bala.h"

class Bala2
{
    public:
        Bala2(int x, int y);
        void draw(SDL_Surface* screen, int x, int y);

        bool exists;
        int x;
        int y;
        int getx();
        int gety();
        SDL_Surface * imagen();
        SDL_Surface* image;
        virtual ~Bala2();
    protected:
    private:
};

#endif // BALA2_H
