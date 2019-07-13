//
// Created by nik on 09.07.19.
//

#ifndef KICKASS_STRING_H
#define KICKASS_STRING_H

#include "../hyper_c.h"

typedef char* string;

int string_size(const string str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (i >= 1024) {
            return -1;
        }
    }

    return i;
}


string string_concat(string first, string second) {
    int first_size = string_size(first),
        second_size = string_size(second);

    string new_string = (string) malloc((first_size + second_size + 1) * sizeof(char));

    int i;
    for (i = 0; i < first_size; i++) {
        new_string[i] = first[i];
    }

    int j;
    for (j = 0; j < second_size; j++) {
        new_string[i + j] = second[j];
    }

    new_string[i + j] = '\0';

    return new_string;
}

DEF_DTOR(char, )

#endif //KICKASS_STRING_H
