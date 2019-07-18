//
// Created by nik on 16.07.19.
//

#ifndef KICKASS_COLLISION_H
#define KICKASS_COLLISION_H

typedef struct {
    list_rcharacter *destroying_list;

    list_rcharacter *solids;
} collision;

DEF_CTOR(collision, (list_rcharacter *destroying_list), {
    this->destroying_list = destroying_list;
    this->solids = $(list_rcharacter)(10, 10);
})

DEF_DTOR(collision, {
    list_rcharacter_destroy(this->solids);
})

void collision_register(collision *this, rcharacter item) {
    list_rcharacter_add(this->solids, item);
}

void collision_unregister(collision *this, rcharacter item) {
    list_rcharacter_remove(this->solids, item);
}

void collision_check(collision *this) {
    FOREACH(rcharacter, solid, this->solids) {
        FOREACH(rcharacter, other, this->solids) {
            if (solid != other &&
                solid->collider->durability <= other->collider->durability &&
                vector_magnitude(
                    vector_substract(
                        solid->position->vector,
                        other->position->vector))
                        < solid->collider->radius + other->collider->radius) {

                list_rcharacter_add(this->destroying_list, solid);
            }
        }
    }
}

#endif //KICKASS_COLLISION_H
