//
// Created by nik on 09.07.19.
//

#ifndef KICKASS_VECTOR_H
#define KICKASS_VECTOR_H

#include <SDL_rect.h>
#include "../hyper_c.h"

typedef struct {
    int x, y;
} vector;

DEF_VALUE_CTOR2(vector, int x, int y, {
    this.x = x;
    this.y = y;
})

DEF_CAST(vector, SDL_Rect, {
    other.x = this.x;
    other.y = this.y;
})

DEF_EQUAL(vector, {
    return this.x == other.x && this.y == other.y;
})

vector vector_add(vector v1, vector v2) {
    vector result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    return result;
}

#endif //KICKASS_VECTOR_H
