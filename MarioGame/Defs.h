#ifndef DEFS_H
#define DEFS_H
// Screen dimensions
#define SCREEN_WIDTH 1280;
#define SCREEN_HEIGHT 720;

// Window title
#define WINDOW_TITLE		"Mario Coin";
#define WINDOW_ICON_PATH	"gfx/coin_icon.png"

// Background
#define BACKGROUND_INTRO	"..."
#define BACKGROUND_LEVEL	"..."
#define BACKGROUND_GAMEOVER "..."

// Font
#define FONT_PATH			"font/8bit.ttf"

// Music
#define MUSIC_THEME_PATH	"sfx/bgtheme.mp3"
#define SOUND_JUMP			"sfx/jump.wav"
#define SOUND_COIN			"sfx/coin.wav"
#define SOUND_LOST			"sfx/lost.mp3"

// Image
#define IMG_COIN			"gfx/coin.png"
#define IMG_GROUND			"gfx/ground.png"
#define IMG_MARIO			"gfx/mario1985.png"

// Text size
#define TEXT_SIZE_BIG 30
#define TEXT_SIZE_SMALL 16

// For keyboard handling
#define KEY_MAX		100
#define KEY_ESC		SDL_SCANCODE_ESCAPE
#define KEY_LEFT	SDL_SCANCODE_LEFT
#define KEY_RIGHT	SDL_SCANCODE_RIGHT
#define KEY_UP		SDL_SCANCODE_UP
#define KEY_SPACE	SDL_SCANCODE_SPACE
#define KEY_A		SDL_SCANCODE_W
#define KEY_W		SDL_SCANCODE_S
#define KEY_D		SDL_SCANCODE_D
#define KEY_ENTER	SDL_SCANCODE_RETURN

#endif //DEFS_H
