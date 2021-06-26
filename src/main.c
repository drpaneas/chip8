#include <stdio.h>
#include "SDL2/SDL.h"

// Window dimensions (the original 64x32 is very small, so scale up)
static const int width = 640;
static const int height = 320;

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    // Create a window (it's actually a pointer)
    SDL_Window *window = SDL_CreateWindow(
        "Chip8 Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width, height, SDL_WINDOW_SHOWN);

    // Create a renderer for the window
    SDL_Renderer *renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_TEXTUREACCESS_TARGET);

    // Infinite loop. Break out on the 'Quit' event or ESC button pressed.
    int running = 1; // true
    SDL_Event event;
    while (running)
    {
        // Process events
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                printf("Exiting... User closed the window.\n");
                running = 0; // false
            }

            if (event.type == SDL_KEYDOWN)
            {
                // Check which key has been pressed
                const char *key = SDL_GetKeyName(event.key.keysym.sym);
                printf("Pressed: %s\n", key);
                if (strcmp(key, "Escape") == 0)
                {
                    printf("Exiting... User pressed ESC button.\n");
                    running = 0; // false
                }
            }
        }

        // Draw black background for the window
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); // set the renderer color to black
        SDL_RenderClear(renderer);                    // apply the renderer color on the whole screen

        // Draw a white rectangle
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0); // set renderer to white
        SDL_Rect r;                                         // Create a rectangle
        r.x = 0;
        r.y = 0;
        r.w = 40;
        r.h = 40;
        SDL_RenderFillRect(renderer, &r); // Sketch a white rectangle (outline) and fill it with white color

        // Show what was drawn (without this, none of the above are visible)
        SDL_RenderPresent(renderer);
    }

    // User has either closed the Window or pressed ESC key
    // so in that case clear the resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
