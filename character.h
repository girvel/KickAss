//
// Created by nik on 15.07.19.
//

#ifndef KICKASS_CHARACTER_H
#define KICKASS_CHARACTER_H

#include "systems/output/sprite.h"
#include "systems/placing/position.h"

typedef struct {
    sprite *sprite;
    position *position;
} character;

typedef character* rcharacter;

DEF_CTOR(character, (sprite *sprite, position *position), {
    this->sprite = sprite;
    this->position = position;
})

DEF_DTOR(character, {
    sprite_destroy(this->sprite);
})

#endif //KICKASS_CHARACTER_H
