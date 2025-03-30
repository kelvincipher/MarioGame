#ifndef COIN_H
#define COIN_H

#include <SDL.h>
#include "Texture.h"
#include "Utility.h"
#include "Defs.h"

class Coin
{
private:
	Texture* coinTex;
	double coinPosX, coinPosY;
	double coinSpeedY;
	SDL_Rect coinRect;

public:
	Coin(SDL_Renderer* renderer);
	~Coin();
	void fall();
	void render();
	SDL_Rect getRect() const;
	void reset();
};


#endif COIN_H