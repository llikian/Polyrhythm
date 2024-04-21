#ifndef GRAPHIC_FUNCTIONS
#define GRAPHIC_FUNCTIONS

#include <SDL2/SDL.h>

#include <cmath>
#include "color_functions.hpp"
#include "complex_functions.hpp"

void setColor(SDL_Renderer* renderer, const Color& color);
void drawCircle(SDL_Renderer* renderer, const Complex& center, const int& radius, const Color& color);
void fillCircle(SDL_Renderer* renderer, const Complex& center, const int& radius, const Color& color);
void drawUpperArc(SDL_Renderer* renderer, const Complex& center, const int& radius, const Color& color);
void outlinedCircle(SDL_Renderer* renderer, const Complex& center, const Color& outline, const Color& filling, const int& radius);
void drawLine(SDL_Renderer* renderer, const Complex& start, const Complex& end, const Color& color);

#endif