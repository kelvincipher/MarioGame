#include "Mario.h"
#include "Defs.h"

#define SCREEN_WIDTH 1280

Mario::Mario(SDL_Renderer* renderer) : 
    marioHealth(MAX_HEALTH),
	healthBarRect({ 0, 75, MAX_HEALTH * 2, 25 }),
	lastHealthDecreaseTime(0),
	marioState(IDLE), 
	marioPos(SCREEN_WIDTH / 2.0, GROUND - MARIO_HEIGHT), 
	marioSpeed(0.0, 0.0),
	marioRect({ 0, 0, MARIO_WIDTH, MARIO_HEIGHT }),
	jumpSound(new Sound(SOUND_JUMP))
{
	marioTex = new Texture(renderer);
	marioTex->loadFromFile(IMG_MARIO);
	marioPos.y = GROUND - MARIO_HEIGHT;
}

Mario::~Mario()
{
	delete marioTex;
	delete jumpSound;
}

void Mario::handleInput(Keyboard* keyboard)
{
    if (marioState != JUMP) // If not jump (move right or left)
    {
        if (!(keyboard->getKey(KEY_LEFT) || keyboard->getKey(KEY_RIGHT) || keyboard->getKey(KEY_A) || keyboard->getKey(KEY_D)))
        {
            marioSpeed.x = IDLE_X;
            marioState = IDLE;
        }
        if (keyboard->getKey(KEY_LEFT) || keyboard->getKey(KEY_A))
        {
            marioSpeed.x = -DFLT_SPEEDX;
            marioState = RUN;
        }
        if (keyboard->getKey(KEY_RIGHT) || keyboard->getKey(KEY_D))
        {
            marioSpeed.x = DFLT_SPEEDX;
            marioState = RUN;
        }
        if ((keyboard->getKey(KEY_UP) || keyboard->getKey(KEY_W) || keyboard->getKey(KEY_SPACE)) && marioPos.y == GROUND - MARIO_HEIGHT)
        {
            marioSpeed.y = DFLT_SPEEDY;
            marioState = JUMP;
			jumpSound->play();
        }
    }
}

void Mario::move(Keyboard* keyboard)
{
    handleInput(keyboard);
	healthDecrease();

    if (marioState == JUMP) // If currently jumping
    {
        marioSpeed.y += GRAVITY;
        marioPos.y += marioSpeed.y;
        // Horizontal bound (Y bound)
        if (marioPos.y > GROUND - MARIO_HEIGHT)
        {
            marioSpeed.y = 0.0;
            marioPos.y = GROUND - MARIO_HEIGHT;
            marioState = IDLE;
        }
    }
    marioPos.x += marioSpeed.x;
    // Vertical bound (X bound)
    if (marioPos.x < 0) // Left bound
    {
        marioPos.x = 0.0;
        marioSpeed.x = 0.0;
    }
    if (marioPos.x > SCREEN_WIDTH - MARIO_WIDTH) // Right bound
    {
        marioPos.x = SCREEN_WIDTH - MARIO_WIDTH;
        marioSpeed.x = 0.0;
    }
}

SDL_Rect Mario::getRect() const
{
    SDL_Rect marioRect;
    marioRect.w = MARIO_WIDTH;
    marioRect.h = MARIO_HEIGHT;
    marioRect.x = marioPos.x;
    marioRect.y = marioPos.y;
    return marioRect;
}

bool Mario::checkMarioCollision(SDL_Rect& coinRect)
{
    SDL_Rect marioRect = getRect();
    return checkCollision(marioRect, coinRect);
}

void Mario::render()
{
    marioTex->render(marioPos.x, marioPos.y, nullptr, 0.0, nullptr, (marioSpeed.x < 0) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
}

void Mario::healthDecrease()
{
	Uint32 currentTime = SDL_GetTicks();
	if (currentTime - lastHealthDecreaseTime >= HEALTH_DECREASE_INTERVAL && marioHealth > 0)
	{
		marioHealth -= HEALTH_DECREASE_AMOUNT;
		if (marioHealth <= 0)
		{
			marioHealth = 0;
		}
		lastHealthDecreaseTime = currentTime;
	}
}

void Mario::renderHealthBar(SDL_Renderer* renderer)
{
	// Render health bar
	healthBarRect.x = 0;
	healthBarRect.y = 75;
	healthBarRect.w = marioHealth * 2;
	healthBarRect.h = 25;
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(renderer, &healthBarRect);
}

unsigned int Mario::getHealth() const
{
	return marioHealth;
}

void Mario::resetMario()
{
	marioHealth = MAX_HEALTH;
	marioPos.x = SCREEN_WIDTH / 2.0;
	marioPos.y = GROUND - MARIO_HEIGHT;
	marioSpeed.x = 0.0;
	marioSpeed.y = 0.0;
	marioState = IDLE;
}
