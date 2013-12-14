//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include <string>
#include <vector>
#include "Background.h"

#include "Bala.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Enemy4.h"
#include "Enemy5.h"
#include "Enemy6.h"
#include "Enemy7.h"
#include "Timer.h"
#include "Player.h"

using namespace std;
//Screen attributes
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 500;
const int SCREEN_BPP = 32;

SDL_Surface *screen = NULL;
Timer* update;

std::string toString(int number)
{
    if (number == 0)
        return "0";
    std::string temp="";
    std::string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0;i<(int)temp.length();i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL )
{
    //Holds offsets
    SDL_Rect offset;
    //Get offsets
    offset.x = x;
    offset.y = y;

    //Blit
    SDL_BlitSurface( source, clip, destination, &offset );
}

void clean_up()
{
        //Free the surfaces
    SDL_FreeSurface( screen );
    // SDL_FreeSurface( gameover );
    // Mix_FreeMusic( score_surface );
    //  Mix_FreeChunk( high );
    //Close the font
    //    TTF_CloseFont( font );
    //Quit SDL_ttf
    TTF_Quit();
    Mix_CloseAudio();
    //Quit SDL
    SDL_Quit();
}


bool init()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return false;
    }
    //Initialize SDL_mixer
    if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;
    }

    //Initialize SDL_ttf
    if( TTF_Init() == -1 )
    {
        return false;
    }

    //Set up the screen
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );

    //Set the window caption
    SDL_WM_SetCaption( "SHOOTER", NULL );

    //If everything initialized fine
    return true;
}

void frameCap()
{
    int frames_per_seccond = 15;
    if(update->get_ticks() < 1000 / frames_per_seccond)
    {
        //Sleep the remaining frame time
        SDL_Delay( ( 1000 / frames_per_seccond ) - update->get_ticks() );
    }
    update->start();
}

/*void checkcollision(Enemy enemy, Bala *bullet)
{
     if((((enemy.getx()>=bullet->getx())&& (enemy.getx()<= bullet->getx()+10)) ||
        ((enemy.getx()+10 >= bullet->getx())&& (enemy.getx()+10 <= bullet->getx()+10))) &&
        (((enemy.gety() >= bullet->gety()) && (enemy.gety() <= bullet->gety()+20)) ||
        ((enemy.gety()+20 >= bullet->gety()) && (enemy.gety()+20 <= bullet->gety()+20))))
     {
       enemy.vida-=5;
     }
}*/

/*void disparar(vector<Bala*>bullets)
{
    if(bullets.size()!=0)
    {
        for(int i=0;i<bullets.size();i++){
            bullets[i]->draw(screen,bullets[i]->x,bullets[i]->y);
            bullets[i]->x+=6;
          //  checkcollision()
        }
    }
}*/

vector<Bala*>bullets;

int main( int argc, char* args[] )
{
    //Initialize
    init();
    update=new Timer();
    update->start();
    SDL_Surface * game_over = IMG_Load( "game_over.png" );

    TTF_Font *font = TTF_OpenFont( "lazy.ttf", 30 );
    SDL_Color textColor = { 255, 255, 255 };
    SDL_Surface * score_surface = NULL;

    Mix_Chunk *jump = Mix_LoadWAV( "jump.ogg" );
    Mix_Chunk *shot = Mix_LoadWAV( "laser-pink.ogg" );
    Mix_Chunk *gameover = Mix_LoadWAV( "game-over.ogg" );
    Mix_Chunk *tittle = Mix_LoadWAV( "title.ogg" );

    Background background(screen);
    Player *player=new Player(screen);
    Enemy1 enemy1(screen,player);
    Enemy2 enemy2(screen,player);
    Enemy3 enemy3(screen,player);
    Enemy4 enemy4(screen,player);
    Enemy5 enemy5(screen,player);
    Enemy6 enemy6(screen,player);
    Enemy7 enemy7(screen,player);


    SDL_Event event;
    //Quit flag
    bool quit = false;
    int score=0;
    SDL_Surface* opciones_de_juego = IMG_Load("menu/menu.png");
    SDL_Surface* instrucciones = IMG_Load("menu/instrucciones.png");
    SDL_Surface* cursor_opciones = IMG_Load("menu/cursor_menu.png");
    int cursor_opciones_y=200;
    int cursor_opciones_x=1;
    bool menu=true;

    while( quit == false )
    {
      /* if(menu)
             Mix_PlayChannel( -1, tittle, 0 );
      else if(!=menu)
           Mix_PlayChannel( -1, tittle, 0 );*/

           if(enemy1.checkCollision())
            player->vida-=0.5;
           if(enemy2.checkCollision())
            player->vida-=0.5;
           if(enemy3.checkCollision())
            player->vida-=0.5;
           if(enemy4.checkCollision())
            player->vida-=0.5;
           if(enemy5.checkCollision())
            player->vida-=0.5;
           if(enemy6.checkCollision())
            player->vida-=0.5;
           if(enemy7.checkCollision())
            player->vida-=0.5;

        SDL_Rect offset;
        offset.x = 0;
        offset.y = 0;
        if(player->vida==0)
           break;

        SDL_Surface * vidas_surface = TTF_RenderText_Solid( font, toString(player->vida).c_str(), textColor );

               //If there's an event to handle
        Uint8 *keystates = SDL_GetKeyState( NULL );


          if( keystates[ SDLK_d ] )
            {
               bullets.push_back(new Bala(player->getx()+10, player->gety()));
               Mix_PlayChannel( -1, shot, 0 );
            }

    if(bullets.size()!=0)
    {
        for(int i=0;i<bullets.size();i++){
            bullets[i]->draw(screen,bullets[i]->x,bullets[i]->y);
            bullets[i]->x+=15;
        }
    }
        if( SDL_PollEvent( &event ) )
        {
            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //Set the proper message surface
                switch( event.key.keysym.sym )
                {
                    case SDLK_ESCAPE: quit = true; break;
                    case SDLK_UP:
                        if (menu==true)
                          cursor_opciones_y--;
                        if (menu==false)
                        {
                            //Mix_PlayChannel( -1, jump, 0 );
                            player->y-=20;
                        }

                    break;
                    case SDLK_DOWN:
                        if (menu==true)
                        cursor_opciones_y++;
                        if (menu==false)
                        {
                             //Mix_PlayChannel( -1, jump, 0 );
                             player->y+=20;
                        }

                    break;
                    case SDLK_LEFT:
                         player->x-=20;
                    break;
                    case SDLK_RIGHT:
                         player->x+=20;
                    break;
                    case SDLK_SPACE:
                        player->jump();
                        //Mix_PlayChannel( -1, jump, 0 );
                    break;
                    case SDLK_d:

                        //  Mix_PlayChannel( -1, shot, 0 );
                    break;
                      //  player.disparar(screen);

                        //  Mix_PlayChannel( -1, jump, 0 );
                 //   break;

                    /*default:
                        break;*/
                  }
            }
            else if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        if (menu==true)
        {
            apply_surface(0,0,opciones_de_juego,screen);
            apply_surface((cursor_opciones_x*219),cursor_opciones_y,cursor_opciones,screen);

              if( SDL_PollEvent( &event ) )
            {

            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                 /* if(cursor_opciones_y>200)
                            cursor_opciones_y=200;
                  if(cursor_opciones_y>410)
                            cursor_opciones_y=410;*/

                //Set the proper message surface
                switch( event.key.keysym.sym )
                {
                    case SDLK_ESCAPE: quit = true; break;
                    case SDLK_UP:
                          cursor_opciones_y-=70;
                    break;
                    case SDLK_DOWN:
                          cursor_opciones_y+=70;
                    break;
                    case SDLK_RETURN:
                          if(cursor_opciones_y==200)
                          {
                            menu=false;
                            //break;
                          }
                          else if(cursor_opciones_y==270)
                          {
                             // SDL_FreeSurface( screen );
                              apply_surface(0,0,instrucciones,screen);
                            //  SDL_Delay(5000);

                                switch( event.key.keysym.sym )
                                {
                                   case SDLK_RETURN:
                                       break;
                                }
                          }
                          else if(cursor_opciones_y==340)
                            quit=true;
                          else if(cursor_opciones_y==410)
                            quit=true;
                        break;
                  }
            }
            //If the user has Xed out the window
            else if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        }
        if (menu==false)
        {

        background.logic();
        apply_surface(10,10,vidas_surface,screen);
        player->logic();
        enemy1.logic(bullets);
        enemy2.logic(bullets);
        enemy3.logic(bullets);
        enemy4.logic(bullets);
        enemy5.logic(bullets);
        enemy6.logic(bullets);
        enemy7.logic(bullets);

        SDL_Rect offset;
        offset.x = 0;
        offset.y = 0;

        SDL_Surface * score_surface = TTF_RenderText_Solid( font, toString(score+=5).c_str(), textColor );
        //SDL_BlitSurface( score_surface, NULL, screen, &offset );
        SDL_Flip( screen );
        SDL_FreeSurface( score_surface );
        SDL_FreeSurface( vidas_surface );

       /* if(player.x-enemy.x<50
           && player.x-enemy.x>-50
           && player.y-enemy.y<50
           && player.y-enemy.y>-50
           )
        {
           break;
        }*/

            background.render();
            player->render();
            enemy1.render();
            enemy2.render();
            enemy3.render();
            enemy4.render();
            enemy5.render();
            enemy6.render();
            enemy7.render();
        }

        frameCap();

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

    }

    while( quit == false )
    {
        //If there's an event to handle
        if( SDL_PollEvent( &event ) )
        {
            //If a key was pressed
            if( event.type == SDL_KEYDOWN )
            {
                //Set the proper message surface
                switch( event.key.keysym.sym )
                {
                    case SDLK_ESCAPE: quit = true; break;
                }
            }
            //If the user has Xed out the window
            else if( event.type == SDL_QUIT )
            {
                //Quit the program
                quit = true;
            }
        }

        SDL_Rect offset;
        offset.x = 0;
        offset.y = 0;

        SDL_BlitSurface( game_over, NULL, screen, &offset );
        Mix_PlayChannel( -1, gameover, 0 );
        frameCap();

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
    }

    clean_up();

    return 0;
}
