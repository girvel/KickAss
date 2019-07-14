//
// Created by nik on 15.07.19.
//

#ifndef KICKASS_GAME_H
#define KICKASS_GAME_H

#include "systems/output/output.h"
#include "systems/input/input.h"


typedef struct game {
    bool active;

    output *output;
    input *input;

    list_rcharacter *__all_characters;
} game;

void game_start(game *this) {
    while (this->active) {
        output_display(this->output);
        input_read(this->input);

        SDL_Delay(1000 / 24);
    }
}

void game_register(game *this, character *item) {
    output_register(this->output, item);
}

void game_register_player(game *this, character *item) {
    game_register(this, item);

    this->input->controllable = item;
}

void move_forward(input *input) {
    INCREMENT(vector, input->controllable->position->vector, $(vector)(0, -10));
}

void escape(input *input) {
    *input->game_active = false;
}

#define CONTROL_MAP map_char_input_action

DEF_CTOR(game, (), {
    this->__all_characters = $(list_rcharacter)(10, 10);

    this->output = output_create();
    this->input = input_create(&this->active);

    game_register_player(this,
        $(character)(
            $(sprite)(load_texture(this->output->renderer, "KickAss.bmp")),
            $(position)($(vector)(100, 100))));

    _(CONTROL_MAP, add)(this->input->control, 'w', &move_forward);
    _(CONTROL_MAP, add)(this->input->control, SDLK_ESCAPE, &escape);
})

DEF_DTOR(game, {
    FOREACH (rcharacter, rc, this->__all_characters) {
        character_destroy(rc);
    }

    output_destroy(this->output);
    input_destroy(this->input);
})

#endif //KICKASS_GAME_H
