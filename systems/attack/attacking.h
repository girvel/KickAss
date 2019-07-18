//
// Created by nik on 19.07.19.
//

#ifndef KICKASS_ATTACKING_H
#define KICKASS_ATTACKING_H

#include "../../tools/vector.h"

struct character;
typedef struct character character;

typedef struct {
    vector attack_direction;
    bool attacks_now;

    character *bullet;
} attacking;

DEF_CTOR(attacking, (vector attack_direction, character *bullet), {
    this->attack_direction = attack_direction;
    this->attacks_now = false;
    this->bullet = bullet;
})

DEF_DTOR(attacking, )

#endif //KICKASS_ATTACKING_H
