//
// Created by nik on 10.07.19.
//

#ifndef KICKASS_OUTPUT_H
#define KICKASS_OUTPUT_H

#include <SDL2/SDL.h>
#include "sprite.h"
#include "../../character.h"
#include "../placing/position.h"



typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;

    list_rcharacter *subjects;
    vector size;

    float background_speed, background_offset;
    sprite background;
} output;

DEF_CTOR(output, (vector size, float background_speed), {
    this->size = size;
    this->background_speed = background_speed;
    this->background_offset = 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error during SDL initialization: %s\n", SDL_GetError());
        return NULL;
    }

    this->window = SDL_CreateWindow("KickAss", 100, 100, size.x, size.y, SDL_WINDOW_SHOWN);

    if (!this->window) {
        printf("Error during window creation: %s\n", SDL_GetError());
        return NULL;
    }

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (!this->renderer) {
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

SDL_Rect rect_construct(vector position, vector size) {
    SDL_Rect result;

    result.h = size.y;
    result.w = size.x;

    result.y = position.y;
    result.x = position.x;

    return result;
}

void output_sprite(output *this, sprite sprite, vector position) {
    SDL_Rect rect
        = rect_construct(
            sprite.centralized
            ? vector_substract(
                position,
                vector_divide(sprite.size, 2))
            : position,
            sprite.size);

    SDL_RenderCopy(this->renderer, sprite.texture, NULL, &rect);
}

void output_display(output *this) {
    SDL_RenderClear(this->renderer);

    this->background_offset += this->background_speed;
    float dummy;
    this->background_offset = modff(this->background_offset, &dummy);

    for (int x = 0; x < ((float) this->size.x) / this->background.size.x; x++) {
        for (int y = -1; y < ((float) this->size.y) / this->background.size.y + 1; y++) {
            output_sprite(this, this->background, vector_scale(this->background.size, x, y + this->background_offset));
        }
    }

    FOREACH (rcharacter, c, this->subjects) {
        output_sprite(this, c->sprite_renderer->sprite, c->position->vector);
    }

    SDL_RenderPresent(this->renderer);
}

void output_register(output *this, character *character) {
    list_rcharacter_add(this->subjects, character);
}

void output_unregister(output *this, character *character) {
    list_rcharacter_remove(this->subjects, character);
}

#endif //KICKASS_OUTPUT_H
