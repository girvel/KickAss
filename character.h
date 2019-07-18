//
// Created by nik on 15.07.19.
//

#ifndef KICKASS_CHARACTER_H
#define KICKASS_CHARACTER_H

#include "systems/output/sprite.h"
#include "systems/placing/position.h"
#include "systems/movement/movable.h"
#include "systems/collision/collider.h"
#include "systems/attack/attacking.h"

typedef struct {
    sprite_renderer *sprite_renderer;
    position *position;
    movable *movable;
    collider *collider;
    attacking *attacking;
} character;

typedef character* rcharacter;

DEF_CTOR(character, (
    sprite_renderer *sprite_renderer,
    position *position,
    movable *movable,
    collider *collider,
    attacking *attacking), {

    this->sprite_renderer = sprite_renderer;
    this->position = position;
    this->movable = movable;
    this->collider = collider;
    this->attacking = attacking;
})

DEF_DTOR(character, {
    sprite_renderer_destroy(this->sprite_renderer);
    position_destroy(this->position);
    movable_destroy(this->movable);
    collider_destroy(this->collider);
})

#endif //KICKASS_CHARACTER_H
