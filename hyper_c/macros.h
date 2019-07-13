//
// Created by nik on 11.07.19.
//

#ifndef KICKASS_MACROS_H
#define KICKASS_MACROS_H

#include "concatenation.h"

#define ALLOCATE(TYPE) (TYPE *) malloc(sizeof(TYPE))
#define ALLOCATE_VAR(TYPE, NAME) TYPE *NAME = ALLOCATE(TYPE);

#define ALLOCATE_ARRAY(TYPE, SIZE) (TYPE *) calloc(SIZE, sizeof(TYPE))
#define ALLOCATE_VAR_ARRAY(TYPE, NAME, SIZE) TYPE *NAME = ALLOCATE_ARRAY(TYPE, SIZE);

#define INCREMENT(TYPE, VARIABLE, SIZE) VARIABLE = _(TYPE, add)(VARIABLE, SIZE)

#endif //KICKASS_MACROS_H
