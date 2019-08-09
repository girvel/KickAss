//
// Created by nik on 05.08.19.
//

#ifndef KICKASS_SOUND_H
#define KICKASS_SOUND_H

#include <SDL2/SDL.h>
#include "../../hyper_c.h"

typedef struct {
    SDL_AudioDeviceID device;
} sound;

DEF_CTOR(sound, (), {
    SDL_AudioSpec want;
    SDL_AudioSpec have;

    SDL_memset(&want, 0, sizeof(want)); /* or SDL_zero(want) */
    want.freq = 44100;
    want.format = AUDIO_U16;
    want.channels = 2;
    want.samples = 4096;
    want.callback = NULL; /* you wrote this function elsewhere -- see SDL_AudioSpec for details */

    this->device = SDL_OpenAudioDevice(NULL, 0, &want, &have, SDL_AUDIO_ALLOW_ANY_CHANGE);
    if (this->device == 0) {
        SDL_Log("Failed to open audio: %s", SDL_GetError());
    } else {
        if (have.format != want.format) { /* we let this one thing change. */
            SDL_Log("We didn't get Float32 audio format.");
        }
        SDL_PauseAudioDevice(this->device, 0); /* start audio playing. */
        SDL_Delay(5000); /* let the audio callback play some sound for 5 seconds. */

        Uint8* audio_buf;
        Uint32 audio_len;
        SDL_LoadWAV("../Assets/Audio/soundtrack.wav", &have, &audio_buf, &audio_len);
        SDL_QueueAudio(this->device, audio_buf, audio_len);
    }
})

DEF_DTOR(sound, {
    SDL_CloseAudioDevice(this->device);
})

#endif //KICKASS_SOUND_H
