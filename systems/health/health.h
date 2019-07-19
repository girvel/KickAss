//
// Created by nik on 19.07.19.
//

#ifndef KICKASS_HEALTH_H
#define KICKASS_HEALTH_H

#include <stdbool.h>
#include "../../hyper_c.h"

typedef struct {
    int max_hp, hp;
    bool is_visible;
} health;

DEF_CTOR(health, (int hp, bool is_visible), {
    this->hp = hp;
    this->max_hp = hp;
    this->is_visible = is_visible;
})

DEF_DTOR(health, )

#endif //KICKASS_HEALTH_H
