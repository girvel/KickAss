//
// Created by nik on 16.07.19.
//

#ifndef KICKASS_COLLISION_H
#define KICKASS_COLLISION_H

typedef struct {
    list_rcharacter *solids;
} collision;

DEF_CTOR(collision, (), {
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
            if (solid == other ||
                vector_magnitude(
                    vector_substract(
                        solid->position->vector,
                        other->position->vector))
                >= solid->collider->radius + other->collider->radius) continue;

            if (other->collider->is_healer) {
                printf("Heal!\n");
                solid->health->hp = MIN(solid->health->hp + other->collider->durability, solid->health->max_hp);
                other->health->hp = 0;
                continue;
            }

            if (solid->collider->durability <= other->collider->durability) {

                printf("Collision!\n");
                solid->health->hp -= other->collider->durability;
            }
        }
    }
}

#endif //KICKASS_COLLISION_H
