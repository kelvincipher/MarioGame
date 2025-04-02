#ifndef MARIO_H
#define MARIO_H

#include <SDL.h>
#include "Texture.h"
#include "Keyboard.h"
#include "Utility.h"
#include "Defs.h"
#include "Music.h"

class Mario
{
private:
	Texture* marioTex;
	Sound* jumpSound;
	Vector2D marioPos;
	Vector2D marioSpeed;
	SDL_Rect marioRect;
	SDL_Rect healthBarRect;
	int marioState;
	unsigned int marioHealth;
	Uint32 lastHealthDecreaseTime;

	void handleInput(Keyboard* keyboard);
	void healthDecrease();

public:
	Mario(SDL_Renderer* renderer);
	~Mario();
	void move(Keyboard* keyboard);
	void render();
	SDL_Rect getRect() const;
	bool checkMarioCollision(SDL_Rect& otherRect);
	void renderHealthBar(SDL_Renderer* renderer);
	int getHealth() const;
	void resetMario(); // When the game is over
};

#endif //MARIO_H
