//
// Created by nik on 11.07.19.
//

#ifndef KICKASS_DEFINITION_H
#define KICKASS_DEFINITION_H

#include <stdbool.h>
#include <stdlib.h>
#include "macros.h"

#define DEF_CTOR(TYPE, ARGS, CODE) TYPE *_(TYPE, create) ARGS {\
    ALLOCATE_VAR(TYPE, this) \
    CODE \
    return this; \
}

#define DEF_VALUE_CTOR(TYPE, ARGS, CODE) TYPE _(TYPE, create) ARGS {\
    TYPE this; \
    CODE \
    return this; \
}

#define DEF_DTOR(TYPE, CODE) void _(TYPE, destroy)(TYPE *this) {\
    CODE \
    free(this); \
}

#define DEF_CAST(FROM, TO, CODE) TO __(FROM, to, TO)(FROM this) {\
    TO other; \
    CODE \
    return other; \
}

#define DEF_EQUAL(TYPE, CODE) bool _(TYPE, equals) (TYPE this, TYPE other) { \
    CODE \
}

#define DEF_NATIVE_EQUAL(TYPE) DEF_EQUAL(TYPE, return this == other;)

#define DEF_CLONE(TYPE, CODE) TYPE *_(TYPE, clone)(TYPE *this) {\
    CODE \
}

#endif //KICKASS_DEFINITION_H
