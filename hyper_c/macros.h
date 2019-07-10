//
// Created by nik on 11.07.19.
//

#ifndef KICKASS_MACROS_H
#define KICKASS_MACROS_H

#define NEW(TYPE) (TYPE *) malloc(sizeof(TYPE))
#define NEW_VAR(TYPE, NAME) TYPE *NAME = NEW(TYPE);

#define NEW_ARRAY(TYPE, SIZE) (TYPE *) calloc(SIZE, sizeof(TYPE))
#define NEW_VAR_ARRAY(TYPE, NAME, SIZE) TYPE *NAME = NEW_ARRAY(TYPE, SIZE);

#endif //KICKASS_MACROS_H
