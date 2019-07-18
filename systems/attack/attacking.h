//
// Created by nik on 19.07.19.
//

#ifndef KICKASS_ATTACKING_H
#define KICKASS_ATTACKING_H

#include "../../tools/vector.h"

typedef struct {
    vector attack_direction;
    bool attacks_now;
} attacking;

DEF_CTOR(attacking, (vector attack_direction), {
    this->attack_direction = attack_direction;
    this->attacks_now = false;
})

DEF_DTOR(attacking, )

#endif //KICKASS_ATTACKING_H
