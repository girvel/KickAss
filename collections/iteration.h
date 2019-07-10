//
// Created by nik on 10.07.19.
//

#ifndef KICKASS_ITERATION_H
#define KICKASS_ITERATION_H

#define FOREACH(TYPE, VAR, COLLECTION) \
    int i = 0; \
    for (TYPE VAR = COLLECTION->first[i]; i < COLLECTION->size; VAR = COLLECTION->first[++i])

#endif //KICKASS_ITERATION_H
