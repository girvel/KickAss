//
// Created by nik on 15.07.19.
//

#ifndef KICKASS_POSITION_H
#define KICKASS_POSITION_H

#include "../../tools/vector.h"

typedef struct {
    vector vector;
} position;

DEF_CTOR(position, (vector vector), {
    this->vector = vector;
})

DEF_DTOR(position, )

#endif //KICKASS_POSITION_H
