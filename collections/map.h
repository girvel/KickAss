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

DEF_VALUE_CTOR(PAIR, (TKEY key, TVALUE value), {
    this.key = key;
    this.value = value;
})

DEF_EQUAL(PAIR, {
    return EQUAL(TKEY, this.key, other.key) && EQUAL(TVALUE, this.value, other.value);
})

#define T PAIR
#include "list.h"
#undef T

#define LIST __(list_pair, TKEY, TVALUE)
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
    TVALUE dummy;
    if (_(MAP, get)(this, key, &dummy)) return false;

    _(LIST, add)(this, $(PAIR)(key, value));
    return true;
}

#undef PAIR
#undef LIST
#undef MAP

#define MAP(TKEY_, TVALUE_) __(list_pair, TKEY_, TVALUE_)
#endif
#endif