//
// Created by nik on 19.07.19.
//

#ifndef KICKASS_HEALTH_SYSTEM_H
#define KICKASS_HEALTH_SYSTEM_H

#include "../../hyper_c.h"

typedef struct {
    list_rcharacter *subjects;

    list_rcharacter *destroying_list;
} health_system;

DEF_CTOR(health_system, (list_rcharacter *destroying_list), {
    this->destroying_list = destroying_list;
    this->subjects = $(list_rcharacter)(10, 10);
})

DEF_DTOR(health_system, {
    list_rcharacter_destroy(this->subjects);
})

void health_system_update(health_system *this) {
    FOREACH(rcharacter, rc, this->subjects) {
        if (rc->health->hp <= 0) {
            list_rcharacter_add(this->destroying_list, rc);
        }
    }
}

void health_system_register(health_system *this, rcharacter item) {
    list_rcharacter_add(this->subjects, item);
}

void health_system_unregister(health_system *this, rcharacter item) {
    list_rcharacter_remove(this->subjects, item);
}

#endif //KICKASS_HEALTH_SYSTEM_H
