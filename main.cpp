//The headers
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "Background.h"
#include "Player.h"
#include "Enemy.h"
#include "Timer.h"
#include <string>

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

int main( int argc, char* args[] )
{
    //Initialize
    init();
    update=new Timer();
    update->start();
    SDL_Surface * game_over = IMG_Load( "game_over.png" );

    TTF_Font *font = TTF_OpenFont( "lazy.ttf", 30 );
    SDL_Color textColor = { 0, 0, 0 };
    SDL_Surface * score_surface = NULL;

    Mix_Chunk *jump = Mix_LoadWAV( "jump.ogg" );
    Mix_Chunk *tittle = Mix_LoadWAV( "title.ogg" );

    Background background(screen);
    Player player(screen);
    Enemy enemy(screen);

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
        if(menu)
             Mix_PlayChannel( -1, tittle, 0 );
     //   else if(!=menu)
           //  Mix_PlayChannel( -1, tittle, 0 );


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
                    case SDLK_UP:
                        if (menu==true)
                          cursor_opciones_y--;
                        if (menu==false)
                         player.y-=100;
                    break;
                    case SDLK_DOWN:
                        if (menu==true)
                        cursor_opciones_y++;
                        if (menu==false)
                          player.y+=100;
                    break;
                    case SDLK_LEFT:
                         player.x-=100;
                    break;
                    case SDLK_RIGHT:
                         player.x+=100;
                    break;
                    case SDLK_SPACE:
                        player.jump();
                        Mix_PlayChannel( -1, jump, 0 );
                    break;
                    case SDLK_d:
                         Bala bala(screen,player.x,player.y);

                         bala.render();
                         bala.logic();

                        //  Mix_PlayChannel( -1, jump, 0 );
                    break;

                    /*default:
                        break;*/
                  }
            }
            //If the user has Xed out the window
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
                  if(cursor_opciones_y<=200)
                            cursor_opciones_y=200;
                  if(cursor_opciones_y>=410)
                            cursor_opciones_y=410;

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
                            menu=false;
                          if(cursor_opciones_y==270)
                             apply_surface(0,0,instrucciones,screen);
                             SDL_Delay(3000);
                          if(cursor_opciones_y==340)
                           //quit=true;
                          if(cursor_opciones_y==410)
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
        player.logic();
        enemy.logic();
        SDL_Rect offset;
        offset.x = 0;
        offset.y = 0;
        SDL_Surface * score_surface = TTF_RenderText_Solid( font, toString(score+=5).c_str(), textColor );
        SDL_BlitSurface( score_surface, NULL, screen, &offset );
        SDL_Flip( screen );
        SDL_FreeSurface( score_surface );

       /* if(player.x-enemy.x<50
           && player.x-enemy.x>-50
           && player.y-enemy.y<50
           && player.y-enemy.y>-50
           )
        {
           break;
        }*/

        background.render();
        player.render();
        enemy.render();

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
        frameCap();

        //Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }
    }

    return 0;
}
