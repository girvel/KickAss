//
// Created by nik on 10.07.19.
//

#ifndef KICKASS_SDL_H
#define KICKASS_SDL_H

#include <SDL2/SDL.h>
#include "sprite.h"

typedef sprite* rsprite;

#define T rsprite
#include "collections/list.h"
#undef T

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;

    bool active;
    list_rsprite *sprites;
} sdl;

DEF_CTOR0(sdl, {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error during SDL initialization: %s\n", SDL_GetError());
        return NULL;
    }

    this->window = SDL_CreateWindow("KickAss", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

    if (!this->window) {
        printf("Error during window creation: %s\n", SDL_GetError());
        return NULL;
    }

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!this->renderer){
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        return NULL;
    }

    this->active = true;
    this->sprites = list_rsprite_create(10, 10);
})

DEF_DTOR(sdl, {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
})

void sdl_start(sdl *this) {
    while (this->active) {
        SDL_RenderClear(this->renderer);

        FOREACH (rsprite, s, this->sprites) {
            put_sprite(this->renderer, s);
        }

        SDL_RenderPresent(this->renderer);

        SDL_Delay(1000 / 24);
    }
}

#endif //KICKASS_SDL_H
