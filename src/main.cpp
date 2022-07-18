//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char** args)
{
    //Initialize all the systems of SDL
    SDL_Init(SDL_INIT_EVERYTHING);

    //Create a window with a title, "Getting Started", in the centre
    //(or undefined x and y positions), with dimensions of 800 px width
    //and 600 px height and force it to be shown on screen
    SDL_Window* window = SDL_CreateWindow("Getting Started", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);

    //Create a renderer for the window created above, with the first display driver present
    //and with no additional settings
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface* bmpsurface = SDL_LoadBMP("LAND2.bmp");

    if (bmpsurface == NULL)
    {
        printf("can't open bmp!"); 
    }
    SDL_Texture* bmptexture = SDL_CreateTextureFromSurface(renderer, bmpsurface);
    SDL_RenderCopy(renderer, bmptexture, NULL, NULL);

    //Set the draw color of renderer to green
    //SDL_SetRenderDrawColor(renderer, 0, 255, 255, 1);

    //Clear the renderer with the draw color
    //SDL_RenderClear(renderer);

    //Update the renderer which will show the renderer cleared by the draw color which is green
    
    SDL_RenderPresent(renderer);


    bool isquit = false;
    SDL_Event event;
    while (!isquit) {
        if (SDL_PollEvent( & event)) {
            if (event.type == SDL_QUIT) {
                isquit = true;
            }
        }
    }
    
    //Destroy the renderer created above
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(bmptexture);

    //Destroy the window created above
    SDL_DestroyWindow(window);

    //Close all the systems of SDL initialized at the top
    SDL_Quit();

    return 0;
}