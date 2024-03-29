//
// Created by nik on 10.07.19.
//

#ifdef T
#include "../hyper_c.h"
#include <stdlib.h>
#include "iteration.h"
#include "safe_array.h"

#define LIST _(list, T)
#define ARRAY _(array, T)

typedef struct {
    T *first;
    size_t size;
    size_t memory_size;
    size_t memory_increment;
} LIST;

DEF_CTOR(LIST, (size_t memory_size, size_t memory_increment), {
    this->first = ALLOCATE_ARRAY(T, memory_size);
    this->size = 0;
    this->memory_size = memory_size;
    this->memory_increment = memory_increment;
})

DEF_DTOR(LIST, {
    free(this->first);
})

void _(LIST, expand) (LIST *this) {
    this->memory_size += this->memory_increment;
    
    ALLOCATE_VAR_ARRAY(T, new_array, this->memory_size)
    
    FOREACH(T, element, this) {
        new_array[i] = element;
    }
    
    free(this->first);
    this->first = new_array;
}

void _(LIST, add) (LIST *this, T item) {
    if (this->size == this->memory_size) {
        _(LIST, expand)(this);
    }
    
    this->first[this->size++] = item;
}

void _(LIST, put) (LIST *this, ARRAY *array) {
    FOREACH(T, e, array) {
        _(LIST, add)(this, e);
    }
}

void _(LIST, remove_at) (LIST *this, size_t index) {
    this->size--;
    for (int i = index; i < this->size; i++) {
        this->first[i] = this->first[i + 1];
    }
}

bool _(LIST, remove) (LIST *this, T item) {
    FOREACH(T, t, this) {
        if (!EQUAL(T, t, item)) continue;
        _(LIST, remove_at)(this, i);
        return true;
    }

    return false;
}

void _(LIST, clear) (LIST *this) {
    this->size = 0;
}

#undef LIST
#undef ARRAY
#endif
