#include "graphic_functions.hpp"

void setColor(SDL_Renderer* renderer, const Color& color)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void drawCircle(SDL_Renderer* renderer, const Complex& center, const int& radius, const Color& color)
{
    int x = 0, y = radius;
    SDL_Point points[8];

    setColor(renderer, color);

    while(x <= y)
    {
        points[0] = {x, y};
        points[1] = {-x, y};
        points[2] = {x, -y};
        points[3] = {-x, -y};
        points[4] = {y, x};
        points[5] = {-y, x};
        points[6] = {y, -x};
        points[7] = {-y, -x};

        for(SDL_Point &point : points)
        {
            point.x += (int)center.x;
            point.y += (int)center.y;
        }

        SDL_RenderDrawPoints(renderer, points, 8);

        ++x;
        y = (int)sqrt(radius*radius - x*x);
    }
}

void fillCircle(SDL_Renderer* renderer, const Complex& center, const int& radius, const Color& color)
{
    int x = 0, y = radius, a, b, c, d;

    setColor(renderer, color);

    while(x <= radius)
    {
        a = (int)center.x + x;
        b = (int)center.y + y;
        c = (int)center.x - x;
        d = (int)center.y - y;

        SDL_RenderDrawLine(renderer, a, b, a, d);
        SDL_RenderDrawLine(renderer, c, b, c, d);

        ++x;
        y = (int)sqrt(radius*radius - x*x);
    }
}

void drawUpperArc(SDL_Renderer* renderer, const Complex& center, const int& radius, const Color& color)
{
    int x = 0, y = radius;
    SDL_Point points[4];

    setColor(renderer, color);

    while(x <= y)
    {
        points[0] = {y, -x};
        points[1] = {-y, -x};
        points[2] = {x, -y};
        points[3] = {-x, -y};

        for(SDL_Point &point : points)
        {
            point.x += (int)center.x;
            point.y += (int)center.y;
        }

        SDL_RenderDrawPoints(renderer, points, 4);

        ++x;
        y = (int)sqrt(radius*radius - x*x);
    }
}

void outlinedCircle(SDL_Renderer* renderer, const Complex& center, const Color& outline, const Color& filling, const int& radius)
{
    fillCircle(renderer, center, radius, filling);
    drawCircle(renderer, center, radius, outline);
}

void drawLine(SDL_Renderer* renderer, const Complex& start, const Complex& end, const Color& color)
{
    setColor(renderer, color);
    SDL_RenderDrawLine(renderer, (int)start.x, (int)start.y, (int)end.x, (int)end.y);
}