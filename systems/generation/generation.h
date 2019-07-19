//
// Created by nik on 19.07.19.
//

#ifndef KICKASS_GENERATION_H
#define KICKASS_GENERATION_H

#include "../../hyper_c.h"

typedef struct {
    float current_delay, delay, step;
    int width;

    list_rcharacter *creation_list;
    rcharacter enemy_prototype;
} generation;

DEF_CTOR(generation, (list_rcharacter *creation_list, rcharacter enemy_prototype, float start_delay, float step, int width), {
    this->creation_list = creation_list;
    this->enemy_prototype = enemy_prototype;

    this->delay = start_delay;
    this->current_delay = 0;
    this->step = step;
    this->width = width;
})

DEF_DTOR(generation, )

void generation_update(generation *this) {
    this->current_delay++;

    if (this->current_delay > this->delay) {
        this->current_delay = 0;
        this->delay *= this->step;

        rcharacter clone = CLONE(character, this->enemy_prototype);
        list_rcharacter_add(this->creation_list, clone);
        clone->position->vector = $(vector)(rand() % this->width, 0);
    }
}

#endif //KICKASS_GENERATION_H
