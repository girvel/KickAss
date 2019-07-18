//
// Created by nik on 10.07.19.
//

#ifndef KICKASS_ITERATION_H
#define KICKASS_ITERATION_H

#define FOREACH(TYPE, VAR, COLLECTION) \
    TYPE VAR = COLLECTION->first[0]; \
    for (int i = 0; i < COLLECTION->size; VAR = COLLECTION->first[++i])

#define FOR(COUNTER, COLLECTION) for(int COUNTER = 0; i < COLLECTION->size; COUNTER++)

#endif //KICKASS_ITERATION_H
