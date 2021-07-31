#include <stdio.h>
#include "SDL2/SDL.h"
#include "chip8.h"

int main(int argc, char **argv)
{
    struct chip8 chip8;
    chip8_memory_set(&chip8.memory, 50, 'Z');
    printf("%c\n", chip8_memory_get(&chip8.memory, 50));

    SDL_Init(SDL_INIT_EVERYTHING);

    // Create a window
    SDL_Window *window = SDL_CreateWindow(
        EMULATOR_WINDOW_TITLE,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        CHIP8_WIDTH * CHIP8_WINDOW_MULTIPLIER,
        CHIP8_HEIGHT * CHIP8_WINDOW_MULTIPLIER,
        SDL_WINDOW_SHOWN);

    // Create a renderer (for the window) so you can use it to draw pixels on the screen.
    SDL_Renderer *renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_TEXTUREACCESS_TARGET);

    // Infinite loop: Break out on the 'Quit' event or if ESC button is pressed.
    while (1)
    {
        SDL_Event event;
        // Process events
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                printf("Exiting... User closed the window.\n");
                goto out;
            }

            if (event.type == SDL_KEYDOWN)
            {
                // Check which key has been pressed.
                const char *key = SDL_GetKeyName(event.key.keysym.sym);
                printf("User pressed: %s\n", key);
                if (strcmp(key, "Escape") == 0)
                {
                    printf("Exiting... User pressed ESC button.\n");
                    goto out;
                }
            }
        }

        // Draw black background for the window
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); // set the renderer color to black (RGBA).
        SDL_RenderClear(renderer);                    // paint the entire screen with black color.

        // Draw a white rectangle
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0); // set renderer to white.
        SDL_Rect r;                                         // Create a rectangle.
        r.x = 0;
        r.y = 0;
        r.w = 40;
        r.h = 40;
        SDL_RenderFillRect(renderer, &r); // Sketch a white rectangle (outline) and fill it with white color.

        // Present the changes to the screen (without this, none of the above are visible).
        SDL_RenderPresent(renderer);
    }

out:
    // User has either closed the Window or pressed ESC key
    // so in that case clear the resources.
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
