#include <SDL.h>
#include <stdio.h>
#include <string>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;




bool init();
bool loadMedia();
void close();
bool quit = false;
SDL_Event e;


//Key presses constants
enum KeyPressSurfaces {
    KEY_PRESS_SURFACE_DEFAULT,
    KEY_PRESS_SURFACE_UP,
    KEY_PRESS_SURFACE_DOWN,
    KEY_PRESS_SURFACE_LEFT,
    KEY_PRESS_SURFACE_RIGHT,
    KEY_PRESS_SURFACE_TOTAL
};

//circle shape
void set_pixel(SDL_Renderer *rend, int x, int y, Uint8 r, Uint8g, Uint8 b, Uint8a)
{
    SDL_SetRenderDrawColor( rend, r,g,b,a);
    SDL_RenderDrawPoint(rend, x, y);
};

void draw_circle(SDL_Renderer *surface, int n_cx, int n_cy)


///SDL LOADERS///
        //Window render
        SDL_Window* gWindow = NULL;
        //surface contained by window
        SDL_Surface* gScreenSurface = NULL;
        //hi
        SDL_Surface* gHelloWorld = NULL;
        //close window
        SDL_Surface* gXOut = NULL;
        //load individual image (should kill hello world splash screen but it's fine)
        SDL_Surface* loadSurface( std::string path);
        //images triggered by key presses
        SDL_Surface* gKeyPressSurfaces[ KEY_PRESS_SURFACE_TOTAL ];
        //Current displayed image
        SDL_Surface* gCurrentSurface = NULL;
///END OF SDL LOADERS///





        bool init()

    {
        //Initialization flag
        bool success = true;

        //Initialize SDL
        if( SDL_Init( SDL_INIT_VIDEO ) < 0)
        {
            printf("error: %s\n", SDL_GetError() );
            success = false;
        }

        else
        {

        //Create Window
        gWindow = SDL_CreateWindow(" Image banner", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if ( gWindow == NULL )
        {

            printf("error: %s\n", SDL_GetError() );
            success = false;
        }

        else
        {
            //get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }

        }
    return success;





    }

 bool loadMedia()
    {
        //Loading success flag
        bool success = true;



        //Load splash image
        gHelloWorld = SDL_LoadBMP( "banner.bmp" );
        if ( gHelloWorld == NULL)
        {
            printf("Error! Image didn't load, Error code: %s\n", SDL_GetError() );
            success = false;
        }
        return success;
    }

      void close()
    {
        //Deallocate surface
        SDL_FreeSurface( gHelloWorld );
        gHelloWorld = NULL;

        //Destroy the window!

        SDL_DestroyWindow ( gWindow );
        gWindow = NULL;

        //Quit SDL
        SDL_Quit();
    }






int main ( int argc, char* args[] ) {


    //Start up SDL and create window

    if( !init() )
    {
        printf("Error! Cannot Initialize!\n");
    }

    else
    {

    //Load media
    if (!loadMedia())
    {
        printf("Failed to load media!\n");
    }
    else
    {
        //Apply the image
        SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
        //Update the surface
        SDL_UpdateWindowSurface( gWindow );

    while (!quit)
    {
        while (SDL_PollEvent( &e ) !=0 )
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        SDL_BlitSurface( gXOut, NULL, gScreenSurface, NULL);
        SDL_UpdateWindowSurface( gWindow );
        }
    }

    }
}
}
