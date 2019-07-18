#include "game.h"

#define T vector
#include "collections/list.h"
#undef T

int main() {
    USING(game, game, game_create(), {
        game_start(game);
    })

    return 0;
}