//
// Created by nik on 15.07.19.
//

#ifndef KICKASS_MOVEMENT_H
#define KICKASS_MOVEMENT_H

#include "../../hyper_c.h"
#include "../../tools/math.h"

typedef struct {
    list_rcharacter *subjects;

    vector border;
} movement;

DEF_CTOR(movement, (vector border), {
    this->subjects = $(list_rcharacter)(10, 10);
    this->border = border;
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

        if (rc->movable->can_leave_screen) continue;

        MAKE_MEDIAN(
            rc->position->vector.x,
            0,
            this->border.x)

        MAKE_MEDIAN(
            rc->position->vector.y,
            0,
            this->border.y)
    }
}

#endif //KICKASS_MOVEMENT_H
