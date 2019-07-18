//
// Created by nik on 15.07.19.
//

#ifndef KICKASS_CHARACTER_H
#define KICKASS_CHARACTER_H

#include "systems/output/sprite.h"
#include "systems/placing/position.h"
#include "systems/movement/movable.h"
#include "systems/collision/collider.h"

typedef struct {
    sprite *sprite;
    position *position;
    movable *movable;
    collider *collider;
} character;

typedef character* rcharacter;

DEF_CTOR(character, (sprite *sprite, position *position, movable *movable, collider *collider), {
    this->sprite = sprite;
    this->position = position;
    this->movable = movable;
    this->collider = collider;
})

DEF_DTOR(character, {
    sprite_destroy(this->sprite);
    position_destroy(this->position);
    movable_destroy(this->movable);
    collider_destroy(this->collider);
})

#endif //KICKASS_CHARACTER_H
