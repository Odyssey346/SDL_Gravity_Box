#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

#include "renderwindow.hpp"
#include "entity.hpp"
#include "math.hpp"

// Screen resolution.
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

// Setup the delta time.
double CurrentTime = SDL_GetTicks();
double LastTime = CurrentTime;
double DeltaTime = ( CurrentTime - LastTime ) / 1000.0f;


int main(int argc, char* args[]){
        // Add some files to this code.
        freopen( "output.txt", "w", stdout);
        freopen( "error.txt", "w", stderr );

        std::cout << "-----------------------[ SDL START ! ]-----------------------"  << std::endl;

        // Init the SDL video
        if (SDL_Init(SDL_INIT_VIDEO) > 0 ) {
        std::cerr << "SDL_Init defenitely failed here... ERROR: " << SDL_GetError() << std::endl;
        return 2;
    }

        if (!(IMG_Init(IMG_INIT_PNG))) {
        std::cerr << "IMG_Init failed, but this is still a good progress! ERROR: " << SDL_GetError() << std::endl;
        return 3;
        }

        RenderWindow window("GAME v1.0", SCREEN_WIDTH, SCREEN_HEIGHT);
                


        SDL_Texture* faceSprite = window.loadTexture("res/img/sprite.png");

        // Entity entities[3] = { Entity(0,0, faceSprite),
        //                      Entity(120,120, faceSprite),
        //                      Entity(240,240, faceSprite)
        //};


        // Create a dummy SDL_Event.
        // This is currently used to keep the game up after rendering the frame.

        bool gameRunning = true;
        SDL_Event event;
 
        int XPos1 = 0;
        int YPos1 = 0;
                                                                                          
        std::vector<Entity> entities = {
                                       Entity(Vector2f(XPos1,YPos1), faceSprite),
                                       Entity(Vector2f(XPos1+120,YPos1+120), faceSprite),
                                       Entity(Vector2f(XPos1+240,YPos1+240), faceSprite)
        };


        while (gameRunning){
            while (SDL_PollEvent(&event)){
                // Poll the close event  
                if (event.type == SDL_QUIT) {
                    gameRunning = false;
                }
                //User presses a key
                else if( event.type == SDL_KEYDOWN ) {
                   switch (event.key.keysym.sym) {
                        case SDLK_UP:
                        std::cout << "UP!" << std::endl;
                        std::cout << YPos1 << " <-- YPos Before" << std::endl;
                        YPos1 = YPos1 +10;
                        std::cout << YPos1 << " <-- YPos After" << std::endl;
                        break;

                        case SDLK_DOWN:
                        std::cout << "UP!" << std::endl;
                        std::cout << YPos1 << " <-- YPos Before" << std::endl;
                        YPos1 = YPos1 -10;
                        std::cout << YPos1 << " <-- YPos After" << std::endl;
                        break;


                   } 
                }

                // Get the mouse position on the window.
                else if (event.type == SDL_MOUSEMOTION) {
                 int XPos_mo { event.motion.x };
                 int YPos_mo { event.motion.y };
                 std::cout << "Position of mouse is " << XPos_mo << "," << YPos_mo << "." << std::endl;
                 XPos_mo = XPos1;
                 YPos_mo = YPos1;
                }  

                else if (DeltaTime != 0) {
                std::cout << "FPS: " << DeltaTime << "." << std::endl;
                std::cout << "TimeStart : " << CurrentTime << "." << std::endl;   
                std::cout << "TimeEnd : " << LastTime << "." << std::endl;
                }       





                // Clear the render
                window.clear();
                // Render the faces (3)
                     for (Entity& face : entities){                
                        window.render(face); 
                    };
                // Update the render with a new frame.
                window.display();                                              




            }
           
            
        }
        // Destroy the window.
        window.cleanUp();
         std::cout << "-----------------------[ SDL EXITING ! ]-----------------------"  << std::endl;
        // Quit SDL
        SDL_Quit();
        // Return a successful exit code.
        return 0;
}



