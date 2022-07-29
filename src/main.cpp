#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

#include "renderwindow.hpp"
#include "entity.hpp"


const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;



int main(int argc, char* args[]){
        if (SDL_Init(SDL_INIT_VIDEO) > 0 )
        std::cout << "SDL_Init defenitely failed here... ERROR: " << SDL_GetError() << std::endl;

        if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG_Init failed, but this is still a good progress! ERROR: " << SDL_GetError() << std::endl;

        RenderWindow window("GAME v1.0", SCREEN_WIDTH, SCREEN_HEIGHT);
                


        SDL_Texture* faceSprite = window.loadTexture("res/img/sprite.png");

        // Entity entities[3] = { Entity(0,0, faceSprite),
        //                      Entity(120,120, faceSprite),
        //                      Entity(240,240, faceSprite)
        //};

        std::vector<Entity> entities = {Entity(0,0, faceSprite),
                                       Entity(120,120, faceSprite),
                                       Entity(240,240, faceSprite)
        };

        bool gameRunning = true;
        SDL_Event event;

       

        while (gameRunning){
            while (SDL_PollEvent(&event)){
                if (event.type == SDL_QUIT) {
                    gameRunning = false;
                }
            }
            window.clear();
            
              for (Entity& face : entities){                
                 window.render(face); 
             };
            window.display();
        }
        window.cleanUp();
        SDL_Quit();

        return 0;
}



