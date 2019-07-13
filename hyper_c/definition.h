//
// Created by nik on 11.07.19.
//

#ifndef KICKASS_DEFINITION_H
#define KICKASS_DEFINITION_H

#include <stdbool.h>
#include "macros.h"

#define DEF_CTOR(TYPE, ARGS, CODE) TYPE *_(TYPE, create) ARGS {\
    ALLOCATE_VAR(TYPE, this) \
    CODE \
    return this; \
}

#define DEF_CTOR0(TYPE, CODE) TYPE *_(TYPE, create)() { \
    ALLOCATE_VAR(TYPE, this) \
    CODE \
    return this; \
}

#define DEF_CTOR1(TYPE, ARG1, CODE) TYPE *_(TYPE, create)(ARG1) { \
    ALLOCATE_VAR(TYPE, this) \
    CODE \
    return this; \
}

#define DEF_CTOR2(TYPE, ARG1, ARG2, CODE) TYPE *_(TYPE, create)(ARG1, ARG2) { \
    ALLOCATE_VAR(TYPE, this) \
    CODE \
    return this; \
}

#define DEF_CTOR3(TYPE, ARG1, ARG2, ARG3, CODE) TYPE *_(TYPE, create)(ARG1, ARG2, ARG3) { \
    ALLOCATE_VAR(TYPE, this) \
    CODE \
    return this; \
}

#define DEF_VALUE_CTOR2(TYPE, ARG1, ARG2, CODE) TYPE _(TYPE, create)(ARG1, ARG2) {\
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

#endif //KICKASS_DEFINITION_H
