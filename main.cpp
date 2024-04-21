#include "src/mainLib.hpp"

int main([[maybe_unused]]int argc, [[maybe_unused]]char* args[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_AudioInit("waveout");

    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_CreateWindowAndRenderer(DX, DY, 0, &window, &renderer);

    Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_FLAC | MIX_INIT_MOD);
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);

    Mix_AllocateChannels(16);

    bool stop = false;
    SDL_Event event;
    const Uint8* keyboard;

    World world;
    initWorld(world, 7);

    Mix_Chunk* notes[7];
    notes[0] = Mix_LoadWAV("data/Do.wav");
    notes[1] = Mix_LoadWAV("data/Re.wav");
    notes[2] = Mix_LoadWAV("data/Mi.wav");
    notes[3] = Mix_LoadWAV("data/Fa.wav");
    notes[4] = Mix_LoadWAV("data/Sol.wav");
    notes[5] = Mix_LoadWAV("data/La.wav");
    notes[6] = Mix_LoadWAV("data/Si.wav");

    while(!stop) {
        keyboard = SDL_GetKeyboardState(nullptr);
        setColor(renderer, DARK_GREY);
        SDL_RenderClear(renderer);
        ////

        draw(renderer, world);
        update(world, notes);

        ////
        SDL_RenderPresent(renderer);

        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT || keyboard[SDL_SCANCODE_ESCAPE]) {
                stop = true;
            }
        }
    }

    for(Mix_Chunk* i: notes) {
        Mix_FreeChunk(i);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();

    SDL_Quit();
    Mix_Quit();

    return 0;
}