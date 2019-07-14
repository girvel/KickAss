//
// Created by nik on 15.07.19.
//

#ifndef KICKASS_CHARACTER_H
#define KICKASS_CHARACTER_H

#include "systems/output/sprite.h"

typedef struct {
    sprite *sprite;
} character;

typedef character* rcharacter;

DEF_CTOR(character, (sprite *sprite), {
    this->sprite = sprite;
})

DEF_DTOR(character, {
    sprite_destroy(this->sprite);
})

#endif //KICKASS_CHARACTER_H
