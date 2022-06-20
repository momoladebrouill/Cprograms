#include "SDL2/SDL.h"
#include <stdio.h>


void clear(SDL_Renderer * renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void draw(SDL_Renderer * renderer, SDL_Rect * rect) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, rect);
    SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {

    SDL_Window * window;
    SDL_Renderer * renderer;

    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "LE SEXE",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_OPENGL
    );

    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Rect rectangle = {.x = 10,.y = 10,.w = 10,.h = 10};

    clear(renderer);

    int quit = 0;
    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                // Handle arrow keys
                switch(event.key.keysym.scancode) {
                    case SDL_SCANCODE_W:
                        rectangle.x -= 10;
                        break;
                    case SDL_SCANCODE_A:
                        rectangle.x +=10;
                        break;
                    case SDL_SCANCODE_S:
                        rectangle.y -= 10;
                        break;
                    case SDL_SCANCODE_D:
                        rectangle.y += 10;
                        break;
                    case SDL_SCANCODE_Q:
                        quit=1;
                        break;
                    default:
                        break;
                }
            } else if (event.type == SDL_QUIT) {
                quit = 1;
                puts("QUIT!");
                break;
            }
        }
        clear(renderer);
        draw(renderer, &rectangle);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

