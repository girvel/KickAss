//
// Created by nik on 19.07.19.
//

#ifndef KICKASS_AI_H
#define KICKASS_AI_H

typedef struct {
    list_rcharacter *subjects;

    int attack_delay, current_attack_delay;
} ai;

DEF_CTOR(ai, (int attack_delay), {
    this->subjects = $(list_rcharacter)(10, 10);
    this->attack_delay = attack_delay;
    this->current_attack_delay = 0;
})

DEF_DTOR(ai, {
    list_rcharacter_destroy(this->subjects);
})

void ai_register(ai *this, rcharacter item) {
    list_rcharacter_add(this->subjects, item);
}

void ai_unregister(ai *this, rcharacter item) {
    list_rcharacter_remove(this->subjects, item);
}

void ai_update(ai *this) {
    this->current_attack_delay++;

    if (this->current_attack_delay > this->attack_delay) {
        this->current_attack_delay = 0;

        FOREACH(rcharacter, rc, this->subjects) {
            rc->attacking->attacks_now = true;
        }
    }
}

#endif //KICKASS_AI_H
