//
// Created by nik on 10.07.19.
//

#include <SDL2/SDL.h>
#include "tools/string.h"
#include "tools/vector.h"

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
    vector position;
} sprite;

DEF_CTOR2(sprite, SDL_Texture *texture, vector position, {
    this->texture = texture;
    this->position = position;
})

DEF_DTOR(sprite, {})

void put_sprite(SDL_Renderer *renderer, sprite *sprite) {
    SDL_Rect rect = CAST(vector, sprite->position, SDL_Rect);

    SDL_QueryTexture(sprite->texture, NULL, NULL, &rect.w, &rect.h);
    SDL_RenderCopy(renderer, sprite->texture, NULL, &rect);
}

#endif //KICKASS_SPRITE_H