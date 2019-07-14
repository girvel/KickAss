//
// Created by nik on 10.07.19.
//

#include <SDL2/SDL.h>
#include "../../tools/string.h"
#include "../../tools/vector.h"

#ifndef KICKASS_SPRITE_H
#define KICKASS_SPRITE_H

SDL_Texture *load_texture(SDL_Renderer *renderer, string name) {
    SDL_Surface *bmp;

    USING (char, s, string_concat("../Assets/Sprites/", name), {
        bmp = SDL_LoadBMP(s);
    })

    if (!bmp) {
        printf("Error loading sprite\n");
    }

    SDL_Texture *sprite = SDL_CreateTextureFromSurface(renderer, bmp);
    SDL_FreeSurface(bmp);

    return sprite;
}

typedef struct {
    SDL_Texture *texture;
} sprite;

DEF_CTOR(sprite, (SDL_Texture *texture), {
    this->texture = texture;
})

DEF_DTOR(sprite, )

#endif //KICKASS_SPRITE_H
