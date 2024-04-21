#ifndef MAIN_LIB_HPP
#define MAIN_LIB_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "color_functions.hpp"
#include "complex_functions.hpp"
#include "graphic_functions.hpp"

#define DX 1200
#define DY 800
#define LINE_CENTER makeComplex(DX/2.0, DY-51)

#define MAXPOINTS 20

typedef struct
{
    Complex pos[MAXPOINTS];
    int radius[MAXPOINTS];
    int n;
    int sign[MAXPOINTS]; // 1 or -1, handles the direction of a point
    Color color[MAXPOINTS];
} World;

void initWorld(World& world, const int& n);
void draw(SDL_Renderer *renderer, const World& world);
void update(World& world, Mix_Chunk* notes[7]);

#endif