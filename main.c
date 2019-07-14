#include "game.h"

int main() {
    USING(game, game, game_create(), {
        game_start(game);
    })

    return 0;
}