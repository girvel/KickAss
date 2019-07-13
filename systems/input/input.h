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
    game *game;
    sprite *controllable;

    LIST *control;
} input;

DEF_CTOR(input, (game *game, sprite *controllable), {
    this->control = $(LIST)(10, 10);
    this->game = game;
    this->controllable = controllable;
})

DEF_DTOR(input, )

void input_read(input *this) {
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_KEYDOWN:
                printf("Key press detected\n");

                input_action action;
                if (_(MAP, get)(this->control, event.key.keysym.sym, &action)) {
                    action(this);
                }

                break;
        }
    }
}

#endif //KICKASS_INPUT_H
