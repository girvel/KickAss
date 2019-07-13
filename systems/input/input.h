//
// Created by nik on 11.07.19.
//

#ifndef KICKASS_INPUT_H
#define KICKASS_INPUT_H

#include <SDL2/SDL.h>
#include "../../hyper_c.h"

DEF_EQUAL(char, {
    return this == other;
})

typedef void (*input_action)(sprite *game_character);
#define TKEY char
#define TVALUE input_action
#include "../../collections/map.h"
#undef TKEY
#undef TVALUE

#undef MAP
#define MAP map_char_input_action
#define LIST list_pair_char_input_action


typedef struct {
    LIST *control;
} input;

DEF_CTOR0(input, {
    this->control = $(LIST)(10, 10);
})

DEF_DTOR(input, )

void input_read(input *this, bool *game_active, sprite *game_character) {
    SDL_Event event;

    while( SDL_PollEvent( &event ) ) {
        switch (event.type) {
            case SDL_KEYDOWN:
                printf("Key press detected\n");

                input_action action;
                if (_(MAP, get)(this->control, event.key.keysym.sym, &action)) {
                    action(game_character);
                }

                break;

            case SDL_KEYUP:
                printf("Key release detected\n");
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    *game_active = false;
                }
                break;

            default:
                break;
        }
    }
}

#endif //KICKASS_INPUT_H
