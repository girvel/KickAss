//
// Created by nik on 15.07.19.
//

#ifndef KICKASS_GAME_H
#define KICKASS_GAME_H

#include "hyper_c.h"
#include "character.h"


/* List generation begins */

#define T rcharacter
DEF_EQUAL(rcharacter, {
    return this == other;
})
#include "collections/list.h"
#undef T

/* List generation ends */


#include "systems/output/output.h"
#include "systems/input/input.h"
#include "systems/movement/movement.h"
#include "systems/collision/collision.h"
#include "systems/attack/attack.h"


typedef struct game {
    bool active;

    output *output;
    input *input;
    collision *collision;
    movement *movement;
    attack *attack;

    list_rcharacter *creation_list;
    list_rcharacter *destroying_list;

    list_rcharacter *__all_characters;
} game;

void game_unregister(game*, rcharacter);

void game_update(game *this) {
    output_display(this->output);
    input_read(this->input);
    movement_move(this->movement);
    collision_check(this->collision);

    FOREACH(rcharacter, rc, this->destroying_list) {
        game_unregister(this, rc);
    }

    list_rcharacter_clear(this->destroying_list);
}

void game_start(game *this) {
    while (this->active) {
        game_update(this);

        SDL_Delay(10);
    }
}

void game_register(game *this, character *item) {
    output_register(this->output, item);
    movement_register(this->movement, item);
    collision_register(this->collision, item);

    list_rcharacter_add(this->__all_characters, item);
}

void game_register_player(game *this, character *item) {
    game_register(this, item);

    this->input->controllable = item;
}

void game_unregister(game *this, character *item) {
    list_rcharacter_remove(this->__all_characters, item);

    if (this->input->controllable == item) {
        this->input->controllable = NULL;
    }

    output_unregister(this->output, item);
    collision_unregister(this->collision, item);
    movement_unregister(this->movement, item);

    character_destroy(item);
}


#define CONTROL_MAP map_char_input_action
#include "control.h"

DEF_CTOR(game, (), {
    this->__all_characters = $(list_rcharacter)(10, 10);

    this->creation_list = $(list_rcharacter)(10, 10);
    this->destroying_list = $(list_rcharacter)(10, 10);

    vector output_area = $(vector)(640, 960);

    this->output = $(output)(output_area);
    this->input = $(input)(&this->active);
    this->movement = $(movement)(output_area);
    this->collision = $(collision)(this->destroying_list);
    this->attack = $(attack)();

    sprite sprite = sprite_load(this->output->renderer, "KickAss.bmp");

    game_register_player(this,
        $(character)(
            $(sprite_renderer)(sprite),
            $(position)($(vector)(100, 100)),
            $(movable)(10, false),
            $(collider)(30, 10),
            $(attacking)($(vector)(0, -1))));

    game_register(this,
        $(character)(
            $(sprite_renderer)(sprite),
            $(position)($(vector)(300, 100)),
            $(movable)(0, true),
            $(collider)(30, 1),
            $(attacking)($(vector)(0, 1))));

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
