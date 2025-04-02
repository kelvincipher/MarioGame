#include "Coin.h"
#include <cstdlib>

#define SCREEN_WIDTH 1280

// Constructor
Coin::Coin(SDL_Renderer* renderer) : coinPosX(std::rand() % SCREEN_WIDTH), coinPosY(0.0), coinSpeedY(0.0), coinRect({ 0, 0, COIN_WIDTH, COIN_HEIGHT })
{
	coinTex = new Texture(renderer);
	coinTex->loadFromFile(IMG_COIN);
}

// Destructor
Coin::~Coin()
{
	delete coinTex;
}

// Reset the coin position (When colliding with Mario)
void Coin::reset()
{
    coinPosX = (rand() % SCREEN_WIDTH); // Coin falling at different position horizontally
    coinPosY = rand() % 100; // Coin falling at different position vertically
    coinSpeedY = 0.0;
}

// Make the coin fall
void Coin::fall()
{
    coinSpeedY += ((std::rand() % 2) / ACCEL_RATE); // Range from 0 to 1/ACCEL_RATE
    coinPosY += coinSpeedY;
    if (coinPosY >= GROUND - COIN_HEIGHT / 2)
    {
        reset();
    }
}

// Render the coin at (x, y)
void Coin::render()
{
    coinTex->render(coinPosX, coinPosY);
}

// Get the rectangle of the coin (To check collision with Mario)
SDL_Rect Coin::getRect() const
{
    SDL_Rect coinRect;
    coinRect.w = COIN_WIDTH;
    coinRect.h = COIN_HEIGHT;
    coinRect.x = coinPosX;
    coinRect.y = coinPosY;
    return coinRect;
}
