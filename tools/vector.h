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

DEF_VALUE_CTOR(vector, (int x, int y), {
    this.x = x;
    this.y = y;
})

vector vector_zero() {return $(vector)(0, 0);}

DEF_CAST(vector, SDL_Rect, {
    other.x = this.x;
    other.y = this.y;
})

DEF_EQUAL(vector, {
    return this.x == other.x && this.y == other.y;
})

vector vector_add(vector v1, vector v2) {
    return $(vector) (
        v1.x + v2.x,
        v1.y + v2.y
        );
}

vector vector_multiply(int scalar, vector vector) {
    return $(vector)(
        scalar * vector.x,
        scalar * vector.y
        );
}

#endif //KICKASS_VECTOR_H
