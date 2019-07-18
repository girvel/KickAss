//
// Created by nik on 15.07.19.
//

#ifndef KICKASS_MOVEMENT_H
#define KICKASS_MOVEMENT_H

#include "../../hyper_c.h"

typedef struct {
    list_rcharacter *subjects;
} movement;

DEF_CTOR(movement, (), {
    this->subjects = $(list_rcharacter)(10, 10);
})

DEF_DTOR(movement, {
    list_rcharacter_destroy(this->subjects);
})

void movement_register(movement *this, rcharacter item) {
    list_rcharacter_add(this->subjects, item);
}

void movement_unregister(movement *this, rcharacter item) {
    list_rcharacter_remove(this->subjects, item);
}

void movement_move(movement *this) {
    FOREACH(rcharacter, rc, this->subjects) {
        INCREMENT(vector, rc->position->vector, movable_get_velocity(rc->movable));
    }
}

#endif //KICKASS_MOVEMENT_H
