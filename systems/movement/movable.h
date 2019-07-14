//
// Created by nik on 15.07.19.
//

#ifndef KICKASS_MOVABLE_H
#define KICKASS_MOVABLE_H

#include "../../tools/vector.h"

typedef struct {
    int potential_velocity;
    vector direction;
} movable;

DEF_CTOR(movable, (int potential_velocity), {
    this->potential_velocity = potential_velocity;
    this->direction = vector_zero();
})

DEF_DTOR(movable, )

vector movable_get_velocity(movable *this) {
    return vector_multiply(this->potential_velocity, this->direction);
}

#endif //KICKASS_MOVABLE_H
