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
#include "systems/generation/generation.h"
#include "systems/ai/ai.h"
#include "systems/health/health_system.h"
#include "systems/sound/sound.h"

#define SYSTEM(TYPE) TYPE *TYPE;

typedef struct game {
    bool active;

    SYSTEM(output)
    SYSTEM(input)
    SYSTEM(collision)
    SYSTEM(movement)
    SYSTEM(attack)
    SYSTEM(generation)
    SYSTEM(ai)
    SYSTEM(health_system)
    SYSTEM(sound)

    list_rcharacter *creation_list;
    list_rcharacter *destroying_list;

    list_rcharacter *__all_characters;
    list_rcharacter *__all_prototypes;
} game;


void game_unregister(game*, rcharacter);

void game_destroy_by_list(game *this) {
    FOREACH(rcharacter, rc, this->destroying_list) {
        game_unregister(this, rc);
    }

    list_rcharacter_clear(this->destroying_list);
}


void game_register(game*, rcharacter);


void game_create_by_list(game *this) {
    FOREACH(rcharacter, rc, this->creation_list) {
        game_register(this, rc);
    }

    list_rcharacter_clear(this->creation_list);
}


void game_update_systems(game *this) {
    output_display(this->output);
    input_read(this->input);
    movement_move(this->movement);
    collision_check(this->collision);
    attack_create_bullets(this->attack);
    generation_update(this->generation);
    ai_update(this->ai);
    health_system_update(this->health_system);
}


void game_update(game *this) {
    game_update_systems(this);
    game_destroy_by_list(this);
    game_create_by_list(this);
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
    if (item->health != NULL) health_system_register(this->health_system, item);
    if (item->attacking != NULL) attack_register(this->attack, item);

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
    if (item->health != NULL) health_system_unregister(this->health_system, item);
    if (item->attacking != NULL) attack_unregister(this->attack, item);
    ai_unregister(this->ai, item);

    character_destroy(item);
}


#define CONTROL_MAP map_char_input_action
#include "control.h"

//DEF_CTOR(game, (), {
game *game_create() {
    ALLOCATE_VAR(game, this);

    this->__all_characters = $(list_rcharacter)(10, 10);
    this->__all_prototypes = $(list_rcharacter)(10, 10);

    this->creation_list = $(list_rcharacter)(10, 10);
    this->destroying_list = $(list_rcharacter)(10, 10);

    vector output_area = $(vector)(640, 960);

    this->output = $(output)(output_area, 0.005f);
    this->input = $(input)(&this->active);
    this->movement = $(movement)(output_area);
    this->collision = $(collision)();
    this->attack = $(attack)(this->creation_list);
    this->health_system = $(health_system)(this->destroying_list);
    this->sound = $(sound)();

    rcharacter bullet = $(character)(
        $(sprite_renderer)(sprite_load(this->output->renderer, "Bullet.bmp", true)),
        $(position)(vector_zero()),
        $(movable)(20, true),
        $(collider)(3, 15),
        NULL,
        $(health)(1, false));
    list_rcharacter_add(this->__all_prototypes, bullet);

    rcharacter enemy_bullet = CLONE(character, bullet);
    enemy_bullet->movable->potential_velocity = 5;
    list_rcharacter_add(this->__all_prototypes, enemy_bullet);

    rcharacter enemy = $(character)(
        $(sprite_renderer)(sprite_load(this->output->renderer, "Enemy.bmp", true)),
        $(position)(vector_zero()),
        $(movable)(3, true),
        $(collider)(25, 9),
        $(attacking)($(vector)(0, 1), enemy_bullet),
        $(health)(1, false));
    list_rcharacter_add(this->__all_prototypes, enemy);

    rcharacter healer = $(character)(
        $(sprite_renderer)(sprite_load(this->output->renderer, "Healer.bmp", true)),
        $(position)(vector_zero()),
        $(movable)(2, true),
        $(collider)(25, 25),
        NULL,
        $(health)(1, false));
    healer->collider->is_healer = true;
    list_rcharacter_add(this->__all_prototypes, healer);

    this->ai = $(ai)(150);
    this->generation = $(generation)(this->creation_list, enemy, healer, this->ai, 350.0f, 0.9f, output_area.x);

    this->output->background = sprite_load(this->output->renderer, "Background.bmp", false);

    game_register_player(this,
        $(character)(
            $(sprite_renderer)(sprite_load(this->output->renderer, "KickAss.bmp", true)),
            $(position)($(vector)(100, 100)),
            $(movable)(10, false),
            $(collider)(10, 10),
            $(attacking)($(vector)(0, -1), bullet),
            $(health)(100, true)));

    register_control(this->input);

    return this;
}

DEF_DTOR(game, {
    FOREACH (rcharacter, rc, this->__all_characters) {
        character_destroy(rc);
    }

    FOREACH (rcharacter, rp, this->__all_prototypes) {
        character_destroy(rp);
    }

    output_destroy(this->output);
    input_destroy(this->input);
    collision_destroy(this->collision);
    movement_destroy(this->movement);
    attack_destroy(this->attack);
    generation_destroy(this->generation);
    ai_destroy(this->ai);
    health_system_destroy(this->health_system);
    sound_destroy(this->sound);
})

#endif //KICKASS_GAME_H
