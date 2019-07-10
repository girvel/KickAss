//
// Created by nik on 10.07.19.
//

#ifdef TKEY
#ifdef TVALUE
#include "../hyper_c.h"

#define PAIR __(pair, TKEY, TVALUE)

typedef struct {
    TKEY key;
    TVALUE value;
} PAIR;

DEF_VALUE_CTOR2(PAIR, TKEY key, TVALUE value, {
    this.key = key;
    this.value = value;
})

#define T PAIR
#include "list.h"
#undef T

#define LIST _(list, PAIR)

#define MAP __(map, TKEY, TVALUE)



bool _(MAP, get)(LIST *this, TKEY key, TVALUE *value) {
    FOREACH (PAIR, pair, this) {
        if (EQUAL(TKEY, pair.key, key)) {
            *value = pair.value;
            return true;
        }
    }

    return false;
}

bool _(MAP, add)(LIST *this, TKEY key, TVALUE value) {
    _(LIST, add)(this, CTOR(PAIR)(key, value));
}

#undef PAIR
#undef LIST
#undef MAP

#define MAP(TKEY1, TVALUE1) __(list_pair, TKEY1, TVALUE1)
#endif
#endif