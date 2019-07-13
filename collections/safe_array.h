//
// Created by nik on 10.07.19.
//

#ifdef T
#include "../hyper_c.h"
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY _(array, T)

typedef struct {
    T *first;
    size_t size;
    bool dynamic;
} ARRAY;

DEF_CTOR3(ARRAY, T *first, size_t size, bool dynamic, {
    this->first = first;
    this->size = size;
    this->dynamic = dynamic;
})

DEF_DTOR(ARRAY, {
    if (this->dynamic) {
        free(this->first);
    }
})

#undef ARRAY
#endif