#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



class Entity {
    
     //p_x : parameter X  || p_y : parameter y

    public:
        Entity(float p_x, float p_y, SDL_Texture* p_tex);
        void init();
        float getX(), getY();
        SDL_Texture* getTex();
        SDL_Rect getCurrentFrame(); 

    private:
        float x, y;
        SDL_Rect currentFrame;
        SDL_Texture* tex;
};
