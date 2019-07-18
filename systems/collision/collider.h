//
// Created by nik on 16.07.19.
//

#ifndef KICKASS_COLLIDER_H
#define KICKASS_COLLIDER_H

#include "../../hyper_c.h"

typedef struct {
    int radius;
    int durability;
} collider;

DEF_CTOR(collider, (int radius, int durability), {
    this->radius = radius;
    this->durability = durability;
})

DEF_DTOR(collider, )

#endif //KICKASS_COLLIDER_H
