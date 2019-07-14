//
// Created by nik on 11.07.19.
//

#ifndef KICKASS_INPUT_H
#define KICKASS_INPUT_H

#include <SDL2/SDL.h>
#include "../../hyper_c.h"



/* Map generation begins */

DEF_EQUAL(char, {
    return this == other;
})

struct game;
typedef struct game game;

struct input;
typedef struct input input;

typedef void (*input_action)(input *input);
#define TKEY char
#define TVALUE input_action
#include "../../collections/map.h"
#undef TKEY
#undef TVALUE

#undef MAP
#define MAP map_char_input_action
#define LIST list_pair_char_input_action

/* Map generation ends */



typedef struct input {
    character *controllable;
    bool *game_active;

    LIST *control_press, *control_release;
} input;

DEF_CTOR(input, (bool *game_active), {
    this->control_press = $(LIST)(10, 10);
    this->control_release = $(LIST)(10, 10);
    this->game_active = game_active;
})

DEF_DTOR(input, )

void input_read(input *this) {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if (this->controllable != NULL
            && (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)) {
            printf("Key change detected\n");

            input_action action;
            if (_(MAP, get)(
                event.type == SDL_KEYDOWN
                 ? this->control_press
                 : this->control_release,
                event.key.keysym.sym, &action)) {

                action(this);
            }
        }
    }
}

#endif //KICKASS_INPUT_H
