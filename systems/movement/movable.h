//
// Created by nik on 15.07.19.
//

#ifndef KICKASS_MOVABLE_H
#define KICKASS_MOVABLE_H

#include "../../tools/vector.h"

typedef struct {
    vector velocity;
} movable;

DEF_CTOR(movable, (), {
    this->velocity = $(vector)(0, 1);
})

DEF_DTOR(movable, )

#endif //KICKASS_MOVABLE_H
