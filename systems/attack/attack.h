//
// Created by nik on 19.07.19.
//

#ifndef KICKASS_ATTACK_H
#define KICKASS_ATTACK_H

#include "../../hyper_c.h"

typedef struct {
    list_rcharacter *subjects;

    list_rcharacter *creation_list;
} attack;

DEF_CTOR(attack, (list_rcharacter *creation_list), {
    this->creation_list = creation_list;
    this->subjects = $(list_rcharacter)(10, 10);
})

DEF_DTOR(attack, )


void attack_register(attack *this, character *item) {
    list_rcharacter_add(this->subjects, item);
}

void attack_unregister(attack *this, character *item) {
    list_rcharacter_remove(this->subjects, item);
}

void attack_create_bullets(attack *this) {
    FOREACH(rcharacter, rc, this->subjects) {
        if (rc->attacking->attacks_now) {
            rc->attacking->attacks_now = false;

            character *clone = CLONE(character, rc->attacking->bullet);

            list_rcharacter_add(this->creation_list, clone);

            clone->movable->direction = rc->attacking->attack_direction;

            clone->position->vector =
                vector_add(
                    rc->position->vector,
                    vector_multiply(
                        clone->collider->radius + rc->collider->radius,
                        rc->attacking->attack_direction
                        )
                    );
        }
    }
}


#endif //KICKASS_ATTACK_H
