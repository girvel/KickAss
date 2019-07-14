#include "systems/output/output.h"
#include "systems/input/input.h"

typedef struct game {
    bool active;

    output *output;
    input *input;
} game;

void game_start(game *this) {
    while (this->active) {
        output_display(this->output);
        input_read(this->input);
        SDL_Delay(1000 / 24);
    }
}

#define CONTROL_MAP map_char_input_action

void move_forward(input *input) {
    INCREMENT(vector, input->controllable->position, $(vector)(0, -10));
}

void escape(input *input) {
    input->game->active = false;
}

DEF_CTOR(game, (), {
    this->output = output_create();

    vector position = $(vector)(100, 100);
    SDL_Texture *kick_ass = load_texture(this->output->renderer, "KickAss.bmp");

    sprite *character;
    list_rsprite_add(this->output->sprites, sprite_create(kick_ass, position));
    list_rsprite_add(this->output->sprites, character = sprite_create(kick_ass, vector_add(position, position)));

    this->input = input_create(this, character);

    _(CONTROL_MAP, add)(this->input->control, 'w', &move_forward);
    _(CONTROL_MAP, add)(this->input->control, SDLK_ESCAPE, &escape);
})

DEF_DTOR(game, {
    output_destroy(this->output);
    input_destroy(this->input);
})


int main() {
    USING(game, game, game_create(), {
        game_start(game);
    })

    return 0;
}