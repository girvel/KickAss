//
// Created by nik on 15.07.19.
//

#ifndef KICKASS_GAME_H
#define KICKASS_GAME_H

#include "systems/output/output.h"
#include "systems/input/input.h"
#include "systems/movement/movement.h"


typedef struct game {
    bool active;

    output *output;
    input *input;
    movement *movement;

    list_rcharacter *__all_characters;
} game;

void game_update(game *this) {
    output_display(this->output);
    input_read(this->input);
    movement_move(this->movement);
}

void game_start(game *this) {
    while (this->active) {
        game_update(this);

        SDL_Delay(1000 / 50);
    }
}

void game_register(game *this, character *item) {
    output_register(this->output, item);
    movement_register(this->movement, item);
    list_rcharacter_add(this->__all_characters, item);
}

void game_register_player(game *this, character *item) {
    game_register(this, item);

    this->input->controllable = item;
}


#define CONTROL_MAP map_char_input_action
#include "control.h"

DEF_CTOR(game, (), {
    this->__all_characters = $(list_rcharacter)(10, 10);

    this->output = $(output)();
    this->input = $(input)(&this->active);
    this->movement = $(movement)();

    game_register_player(this,
        $(character)(
            $(sprite)(load_texture(this->output->renderer, "KickAss.bmp")),
            $(position)($(vector)(100, 100)),
            $(movable)(10)));


    register_control(this->input);
})

DEF_DTOR(game, {
    FOREACH (rcharacter, rc, this->__all_characters) {
        character_destroy(rc);
    }

    output_destroy(this->output);
    input_destroy(this->input);
})

#endif //KICKASS_GAME_H
