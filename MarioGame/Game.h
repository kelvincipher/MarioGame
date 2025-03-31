#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include "Mainwindow.h"
#include "Texture.h"
#include "Font.h"
#include "Keyboard.h"
#include "Event.h"
#include "Mario.h"
#include "Coin.h"
#include "Music.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define WINDOW_TITLE "Mario Coin"

class Game
{
private:
	MainWindow* window;
	Texture* background;
	Texture* ground;
	Texture* scoreText;
	Texture* hiScoreText;
	Texture* gameOverText;
	Texture* instructionText;
	Font* scoreFont;
	Font* gameOverFont;
	Font* instructionFont;
	Keyboard* keyboard;
	Event* event;
	Mario* mario;
	Coin* coins[NUM_COINS];
	Music* bgTheme;
	Sound* coinSound;
	Sound* lostSound;
	int score;
	int hiScore;
	bool isGameOver;
	bool gameOverSoundPlayed;

	void initialize();
	void update();
	void render();
	void cleanup();

public:
	Game();
	~Game();
	void run();
	void gameOver();
	void resetGame();
};

#endif //GAME_H