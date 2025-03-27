#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <cstdlib>
#include <vector>

#include "Mainwindow.h"
#include "Texture.h"
#include "Music.h"
#include "Defs.h"
#include "Font.h"
#include "Event.h"
#include "Keyboard.h"
#include "Utility.h"


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define WINDOW_TITLE "Mario Coin"

int main(int argc, char* argv[])
{
    MainWindow* window = new MainWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    window->setIcon(WINDOW_ICON_PATH);

    Texture* background = new Texture(window->getRenderer());
    background->loadFromFile(IMG_BACKGROUND);

    Texture* coins[NUM_COINS];
    for (int i = 0; i < NUM_COINS; i++)
    {
        coins[i] = new Texture(window->getRenderer());
        coins[i]->loadFromFile(IMG_COIN);
    }


    Texture* mario = new Texture(window->getRenderer());
    mario->loadFromFile(IMG_MARIO);

    Texture* ground = new Texture(window->getRenderer());
    ground->loadFromFile(IMG_GROUND);

    Keyboard* keyboard = new Keyboard();
    Event* event = new Event();



    // Mario state
    enum MarioStatus { 
        JUMP, 
        RUN, 
        IDLE 
    };

    // Mario's and coin's dimensions
    const double MARIO_WIDTH = mario->getWidth();
    const double MARIO_HEIGHT = mario->getHeight();
    const double COIN_WIDTH = coins[0]->getWidth();
    const double COIN_HEIGHT = mario->getHeight();

    // Initialize Mario's state
    int marioState = IDLE;

    // Initialize Mario's spawn point
    Vector2D marioPos(SCREEN_WIDTH / 2.0, GROUND - MARIO_HEIGHT);

    // Initialize Mario's horizontal and vertical speed
    Vector2D marioSpeed(0.0, 0.0);
    



    // Initialize coin's speed
    double coinSpeedY[NUM_COINS];
    double coinPosX[NUM_COINS];
    double coinPosY[NUM_COINS];
    for (int i = 0; i < NUM_COINS; i++)
    {
        coinPosX[i] = std::rand() % SCREEN_WIDTH;
        coinPosY[i] = 0.0;
        coinSpeedY[i] = 0.0;
    }

    while (!(keyboard->getKey(KEY_ESC) || event->getEvent(EVENT_OUT)))
    {
        event->PollEvent(keyboard);

        // Handle input and update state
        
        // Mario's motion
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
            }
        }
        else // If currently jumping
        {
            marioSpeed.y += GRAVITY;
            marioPos.y += marioSpeed.y;
            // Y bound
            if (marioPos.y > GROUND - MARIO_HEIGHT)
            {
                marioSpeed.y = 0.0;
                marioPos.y = GROUND - MARIO_HEIGHT;
                marioState = IDLE;
            }
        }
        marioPos.x += marioSpeed.x;
        // X bound
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
        
        // Coin falling
        for (int i = 0; i < NUM_COINS; i++)
        {
            coinSpeedY[i] += (FALL_ACCEL + (std::rand() % 2) / 1.5);
            coinPosY[i] += coinSpeedY[i];
            if (coinPosY[i] >= GROUND - COIN_HEIGHT / 2)
            {
                coinPosX[i] = (rand() % SCREEN_WIDTH);
                coinPosY[i] = rand() % 100;
                coinSpeedY[i] = 0.0;
            }
        }

        // Clear screen
        window->clear();

        // Render everything
        background->render(0, 0);
        ground->render(0, GROUND);
        for (int i = 0; i < NUM_COINS; i++)
        {
            coins[i]->render(coinPosX[i], coinPosY[i]);
        }
        mario->render(marioPos.x, marioPos.y, nullptr, 0.0, nullptr, 
                     (marioSpeed.x < 0) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);

        // Update screen
        window->update();

        // Add small delay to prevent 100% CPU usage
        SDL_Delay(16);  // ~60 FPS
    }

    // Cleanup
    delete keyboard;
    delete event;
    delete background;
    for (int i = 0; i < NUM_COINS; i++)
    {
        delete coins[i];
    }
    delete mario;
    delete ground;
    delete window;

    return 0;
}