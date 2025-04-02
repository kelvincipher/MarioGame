#ifndef DEFS_H
#define DEFS_H

// Screen dimensions
#define SCREEN_WIDTH 1280;
#define SCREEN_HEIGHT 720;

// Window title
#define WINDOW_TITLE		"Mario Coin";
#define WINDOW_ICON_PATH	"gfx/coin_icon.png"

// Font
#define FONT_PATH			"font/8bit.ttf"
#define FONT_SCORE_SIZE		35
#define FONT_GAMEOVER_SIZE	100
#define FONT_INSTRUCTION_SIZE 10

// Music
#define MUSIC_THEME_PATH	"sfx/bgtheme.mp3"
#define SOUND_JUMP			"sfx/jump.wav"
#define SOUND_COIN			"sfx/coin.wav"
#define SOUND_LOST			"sfx/lost.wav"

// Image
#define IMG_COIN			"gfx/coin.png"
#define IMG_GROUND			"gfx/ground.png"
#define IMG_MARIO			"gfx/mario1985.png"
#define IMG_BACKGROUND		"gfx/background.png"

// For keyboard handling
#define KEY_MAX		100
#define KEY_ESC		SDL_SCANCODE_ESCAPE
#define KEY_LEFT	SDL_SCANCODE_LEFT
#define KEY_RIGHT	SDL_SCANCODE_RIGHT
#define KEY_UP		SDL_SCANCODE_UP
#define KEY_SPACE	SDL_SCANCODE_SPACE
#define KEY_A		SDL_SCANCODE_A
#define KEY_W		SDL_SCANCODE_W
#define KEY_D		SDL_SCANCODE_D
#define KEY_ENTER	SDL_SCANCODE_RETURN

// Mario physics constants
const double DFLT_SPEEDX = 15, DFLT_SPEEDY = -32;
const double GRAVITY = 2.7; 
const double GROUND = 613;
const double IDLE_X = 0.0;

// Mario's status
enum marioStatus
{
	JUMP,
	RUN,
	IDLE
};

// Mario's health
const unsigned int MAX_HEALTH = 100;
const int HEALTH_DECREASE_INTERVAL = 1000; // Decrease health every 1 second
const int HEALTH_DECREASE_AMOUNT = 2;   // Decrease health by 2

// Coin physics constants
const double ACCEL_RATE = 1.5;
// Nunber of coins
const int NUM_COINS = 1000;

// Mario's and coin's dimension
#define MARIO_WIDTH		52
#define MARIO_HEIGHT	96
#define COIN_WIDTH		32
#define COIN_HEIGHT		40

#endif //DEFS_H
