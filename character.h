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
    bool marked_for_delete;

    sprite_renderer *sprite_renderer;
    position *position;
    movable *movable;
    collider *collider;
} character;

typedef character* rcharacter;

DEF_CTOR(character, (sprite_renderer *sprite_renderer, position *position, movable *movable, collider *collider), {
    this->sprite_renderer = sprite_renderer;
    this->position = position;
    this->movable = movable;
    this->collider = collider;

    this->marked_for_delete = false;
})

DEF_DTOR(character, {
    sprite_renderer_destroy(this->sprite_renderer);
    position_destroy(this->position);
    movable_destroy(this->movable);
    collider_destroy(this->collider);
})

#endif //KICKASS_CHARACTER_H
