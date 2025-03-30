#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <string>
#include <SDL.h>

struct Vector2D 
{
	double x, y;

	Vector2D(double _x, double _y) : x(_x), y(_y) {}
};


bool checkCollision(const SDL_Rect& marioRect, const SDL_Rect& coinRect);

std::string convertIntToString(int num);
#endif // UTILITY_H
