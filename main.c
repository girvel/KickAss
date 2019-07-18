#include "game.h"

DEF_NATIVE_EQUAL(int)

int main() {
    USING(game, game, game_create(), {
        game_start(game);
    })

    return 0;
}