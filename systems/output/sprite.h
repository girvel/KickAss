//
// Created by nik on 10.07.19.
//

#include <SDL2/SDL.h>
#include "../../tools/string.h"
#include "../../tools/vector.h"

#ifndef KICKASS_SPRITE_H
#define KICKASS_SPRITE_H

typedef struct {
    SDL_Texture *texture;
    vector size;
    bool centralized;
} sprite;

DEF_VALUE_CTOR(sprite, (SDL_Texture *texture, vector size, bool centralized), {
    this.texture = texture;
    this.size = size;
    this.centralized = centralized;
})

sprite sprite_load(SDL_Renderer *renderer, string name, bool centralized) {
    SDL_Surface *bmp;

    USING (char, s, string_concat("../Assets/Sprites/", name), {
        bmp = SDL_LoadBMP(s);
    })

    if (!bmp) {
        printf("Error loading sprite\n");
    }

    sprite sprite = $(sprite)(SDL_CreateTextureFromSurface(renderer, bmp), vector_zero(), centralized);
    SDL_QueryTexture(sprite.texture, NULL, NULL, &sprite.size.x, &sprite.size.y);

    SDL_FreeSurface(bmp);

    return sprite;
}

typedef struct {
    sprite sprite;
} sprite_renderer;

DEF_CTOR(sprite_renderer, (sprite sprite), {
    this->sprite = sprite;
})

DEF_DTOR(sprite_renderer, )

#endif //KICKASS_SPRITE_H
