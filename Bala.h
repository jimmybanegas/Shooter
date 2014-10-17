#ifndef BALA_H
#define BALA_H
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_image.h"
#include <vector>
#include <string>
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Bala
{
    public:
        Bala(int x, int y);
        virtual ~Bala();

        void draw(SDL_Surface* screen, int x, int y);

        bool exists;
        int x;
        int y;
        int getx();
        int gety();
        SDL_Surface * imagen();
      //  bool checkcollision(Player *player);
       // bool checkcollision2(Enemy enemy);
        SDL_Surface* image;

    protected:
    private:
};

#endif // BALA_H
