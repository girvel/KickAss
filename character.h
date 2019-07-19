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
#include "systems/health/health.h"

typedef struct character {
    sprite_renderer *sprite_renderer;
    position *position;
    movable *movable;
    collider *collider;
    attacking *attacking;
    health *health;
} character;

typedef character* rcharacter;

DEF_CTOR(character, (
    sprite_renderer *sprite_renderer,
    position *position,
    movable *movable,
    collider *collider,
    attacking *attacking,
    health *health), {

    this->sprite_renderer = sprite_renderer;
    this->position = position;
    this->movable = movable;
    this->collider = collider;
    this->attacking = attacking;
    this->health = health;
})

DEF_DTOR(character, {
    sprite_renderer_destroy(this->sprite_renderer);
    position_destroy(this->position);
    movable_destroy(this->movable);
    collider_destroy(this->collider);
    attacking_destroy(this->attacking);
    health_destroy(this->health);
})

DEF_CLONE(character, {
    return $(character)(
        MEMBERWISE_CLONE(sprite_renderer, this->sprite_renderer),
        MEMBERWISE_CLONE(position, this->position),
        MEMBERWISE_CLONE(movable, this->movable),
        MEMBERWISE_CLONE(collider, this->collider),
        MEMBERWISE_CLONE(attacking, this->attacking),
        MEMBERWISE_CLONE(health, this->health));
})

#endif //KICKASS_CHARACTER_H
