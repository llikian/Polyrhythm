#include "mainLib.hpp"

void initWorld(World& world, const int& n) {
    world.n = n;
    const int radius = (DX - 100) / (world.n * 2);

    Color colorScheme[4];
    colorScheme[0] = makeColor(103, 190, 242);
    colorScheme[1] = makeColor(255, 130, 248);
    colorScheme[2] = makeColor(203, 90, 255);
    colorScheme[3] = makeColor(192, 0, 255);

    for(int i = 0 ; i < n ; ++i) {
        world.pos[i] = makeComplex(DX / 2.0 - radius * (i + 1), DY - 51);
        world.radius[i] = 5;
        world.sign[i] = 1;
        world.color[i] = colorScheme[i % 4];
    }
}

void draw(SDL_Renderer* renderer, const World& world) {
    for(int i = 0 ; i < world.n ; ++i) {
        drawUpperArc(renderer, LINE_CENTER, (i + 1) * (DX - 100) / (world.n * 2), world.color[i]);
        fillCircle(renderer, world.pos[i], world.radius[i], world.color[i]);
    }

    for(int i = 50 ; i < DX - 50 ; ++i) {
        fillCircle(renderer, makeComplex((double) i, DY - 51), 2, WHITE);
    }
}

void update(World& world, Mix_Chunk* notes[7]) {
    double angle;
    const double velocity = 2;

    for(int i = 0 ; i < world.n ; ++i) {
        if(round(world.pos[i].y) > DY - 50) {
            world.sign[i] *= -1;
            Mix_PlayChannel(-1, notes[i % 7], 0);
        }

        angle = PI + (velocity - i * 1 / 30.0) * SDL_GetTicks() / 1000.0;
        angle = (world.sign[i] == 1) ? angle : 2 * PI - angle;

        world.pos[i] = makeComplexExp((DX - 100.0) / (world.n * 2) * (i + 1), angle) + LINE_CENTER;
    }
}