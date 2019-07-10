#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include "tools/string.h"
#include "tools/vector.h"
#include "sdl.h"
#include "sprite.h"

#define T int
#include "collections/list.h"
#undef T

#define TKEY vector
#define TVALUE int
#include "collections/map.h"
#undef TKEY
#undef TVALUE

#include "collections/iteration.h"
#include "hyper_c.h"


void game_start(sdl *sdl) {
    vector position = {100, 100};
    SDL_Texture *kick_ass = load_texture(sdl->renderer, "KickAss.bmp");

    list_rsprite_add(sdl->sprites, sprite_create(kick_ass, position));
    list_rsprite_add(sdl->sprites, sprite_create(kick_ass, vector_add(position, position)));

    sdl_start(sdl);
}



int main() {
    sdl *sdl = sdl_create();

    game_start(sdl);

    sdl_destroy(sdl);
/*
    int __arr[3] = {1, 2, 3};

    USING (list_int, list, list_int_create(2, 1), {
        USING (array_int, safe_array, array_int_create(__arr, 3, false), {
            list_int_put(list, safe_array);
        })

        list_int_add(list, -1);
        list_int_add(list, -100);

        FOREACH (int, e, list) {
            printf("%i ", e);
        }
    })

    MAP(vector, int) *map = CTOR(MAP(vector, int))(10, 10);
    map_vector_int_add(map, vector_create(3, 4), 5);
    map_vector_int_add(map, vector_create(5, 12), 13);

    int result;
    if (map_vector_int_get(map, vector_create(5, 12), &result)) {
        printf("result is %i\n", result);
    } else {
        printf("there is no result\n");
    }
*/
    return 0;
}