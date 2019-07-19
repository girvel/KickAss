//
// Created by nik on 09.07.19.
//

#ifndef KICKASS_VECTOR_H
#define KICKASS_VECTOR_H

#include <SDL_rect.h>
#include "../hyper_c.h"
#include <stdlib.h>

typedef struct {
    int x, y;
} vector;

DEF_VALUE_CTOR(vector, (int x, int y), {
    this.x = x;
    this.y = y;
})

vector vector_zero() {return $(vector)(0, 0);}

DEF_EQUAL(vector, {
    return this.x == other.x && this.y == other.y;
})

vector vector_add(vector v1, vector v2) {
    return $(vector) (
        v1.x + v2.x,
        v1.y + v2.y
        );
}

vector vector_invert(vector this) {
    return $(vector)(-this.x, -this.y);
}

vector vector_substract(vector v1, vector v2) {
    return vector_add(v1, vector_invert(v2));
}

vector vector_divide(vector this, int k) {
    return $(vector)(this.x / k, this.y / k);
}

vector vector_scale(vector v1, int kx, int ky) {
    return $(vector)(
        v1.x * kx,
        v1.y * ky
        );
}

double vector_magnitude(vector this) {
    return sqrt(this.x * this.x + this.y * this.y);
}

vector vector_multiply(int scalar, vector vector) {
    return $(vector)(
        scalar * vector.x,
        scalar * vector.y
        );
}

#endif //KICKASS_VECTOR_H
