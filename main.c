#include "systems/output/output.h"
#include "systems/input/input.h"

typedef struct {
    bool active;

    output *output;
    input *input;
} game;

void game_start(game *this) {
    vector position = {100, 100};
    SDL_Texture *kick_ass = load_texture(this->output->renderer, "KickAss.bmp");

    sprite *character;
    list_rsprite_add(this->output->sprites, sprite_create(kick_ass, position));
    list_rsprite_add(this->output->sprites, character = sprite_create(kick_ass, vector_add(position, position)));

    while (this->active) {
        output_display(this->output);
        input_read(this->input, &this->active, character);
        SDL_Delay(1000 / 24);
    }
}

#define CONTROL_MAP map_char_input_action

void move_forward(sprite *game_character) {
    INCREMENT(vector, game_character->position, $(vector)(0, -5));
}

DEF_CTOR0(game, {
    this->output = output_create();
    this->input = input_create();

    _(CONTROL_MAP, add)(this->input->control, 'w', &move_forward);
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