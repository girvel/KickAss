//
// Created by nik on 10.07.19.
//

#ifndef KICKASS_OUTPUT_H
#define KICKASS_OUTPUT_H

#include <SDL2/SDL.h>
#include "sprite.h"
#include "../../character.h"

#define T rcharacter
#include "../../collections/list.h"
#include "../placing/position.h"

#undef T

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;

    list_rcharacter *subjects;
} output;

DEF_CTOR(output, (), {
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

    this->subjects = list_rcharacter_create(10, 10);
})

DEF_DTOR(output, {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);
    SDL_Quit();
})

void output_sprite(output *this, sprite *sprite, position *position) {
    SDL_Rect rect = CAST(vector, position->vector, SDL_Rect);

    SDL_QueryTexture(sprite->texture, NULL, NULL, &rect.w, &rect.h);
    SDL_RenderCopy(this->renderer, sprite->texture, NULL, &rect);
}

void output_display(output *this) {
    SDL_RenderClear(this->renderer);

    FOREACH (rcharacter, c, this->subjects) {
        output_sprite(this, c->sprite, c->position);
    }

    SDL_RenderPresent(this->renderer);
}

void output_register(output *this, character *character) {
    list_rcharacter_add(this->subjects, character);
}

#endif //KICKASS_OUTPUT_H
