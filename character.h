//
// Created by nik on 15.07.19.
//

#ifndef KICKASS_CHARACTER_H
#define KICKASS_CHARACTER_H

#include "systems/output/sprite.h"
#include "systems/placing/position.h"
#include "systems/movement/movable.h"

typedef struct {
    sprite *sprite;
    position *position;
    movable *movable;
} character;

typedef character* rcharacter;

DEF_CTOR(character, (sprite *sprite, position *position, movable *movable), {
    this->sprite = sprite;
    this->position = position;
    this->movable = movable;
})

DEF_DTOR(character, {
    sprite_destroy(this->sprite);
    position_destroy(this->position);
    movable_destroy(this->movable);
})

#endif //KICKASS_CHARACTER_H
