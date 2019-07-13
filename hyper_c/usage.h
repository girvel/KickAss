//
// Created by nik on 11.07.19.
//

#ifndef KICKASS_USAGE_H
#define KICKASS_USAGE_H

#define $(TYPE) _(TYPE, create)

#define CAST(FROM, VAR, TO) __(FROM, to, TO)(VAR)

#define EQUAL(TYPE, THIS, OTHER) _(TYPE, equals)(THIS, OTHER)

#define USING(TYPE, NAME, VALUE, CODE) { \
    TYPE *NAME = VALUE; \
    CODE \
    _(TYPE, destroy)(NAME); \
}

#endif //KICKASS_USAGE_H
