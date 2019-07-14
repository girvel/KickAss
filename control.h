//
// Created by nik on 15.07.19.
//

#ifndef KICKASS_CONTROL_H
#define KICKASS_CONTROL_H
#ifdef CONTROL_MAP


#include "hyper_c.h"
#define DEF_MOVE(DIRECTION, AXIS, VALUE) \
void _(move, DIRECTION)(input *input) { \
    input->controllable->movable->direction.AXIS = VALUE; \
} \
\
void _(stop, DIRECTION)(input *input) { \
    if (input->controllable->movable->direction.AXIS == VALUE) { \
        input->controllable->movable->direction.AXIS = 0; \
    } \
}


#include "systems/input/input.h"
#include "SDL2/SDL.h"

DEF_MOVE(forward,  y, -1)
DEF_MOVE(backward, y,  1)
DEF_MOVE(left,     x, -1)
DEF_MOVE(right,    x,  1)

void escape(input *input) {
    *input->game_active = false;
}


#define REGISTER_DOWN(METHOD, KEY) _(CONTROL_MAP, add)(input->control_press, KEY, &METHOD);
#define REGISTER_UP(METHOD, KEY) _(CONTROL_MAP, add)(input->control_release, KEY, &METHOD);

#define REGISTER_MOVE(DIRECTION, KEY) REGISTER_DOWN(_(move, DIRECTION), KEY) REGISTER_UP(_(stop, DIRECTION), KEY)


void register_control(input *input) {
    REGISTER_MOVE(forward,  'w')
    REGISTER_MOVE(backward, 's')
    REGISTER_MOVE(left,     'a')
    REGISTER_MOVE(right,    'd')

    REGISTER_DOWN(escape, SDLK_ESCAPE)
}

#undef REGISTER_MOVE
#undef REGISTER_UP
#undef REGISTER_DOWN

#undef DEF_MOVE


#endif
#endif //KICKASS_CONTROL_H
