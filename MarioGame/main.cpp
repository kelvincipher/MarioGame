#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

#include "Mainwindow.h"
#include "Texture.h"
#include "Music.h"
#include "Defs.h"
#include "Font.h"
#include "Event.h"
#include "Keyboard.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define WINDOW_TITLE "Mario Coin"

int main(int argc, char* argv[])
{
    MainWindow* window = new MainWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    window->setIcon(WINDOW_ICON_PATH);

    Texture* coin = new Texture(window->getRenderer());
    coin->loadFromFile(IMG_COIN);

    Texture* mario = new Texture(window->getRenderer());
    mario->loadFromFile(IMG_MARIO);

    Keyboard* keyboard = new Keyboard();
    Event* event = new Event();

    // Mario physics constants
    const double DFLT_SPEEDX = 5.0, DFLT_SPEEDY = -20.0;
    const double GRAVITY = 0.5;  // Reduced gravity for more natural feel
    const double GROUND = 600.0;
    const double IDLE_X = 0.0;

    // Mario state
    enum MarioStatus { JUMP, RUN, IDLE };
    int marioState = IDLE;
    double posX = SCREEN_WIDTH / 2.0, posY = GROUND;
    double speedX = 0.0, speedY = 0.0;

    bool running = true;
    while (running)
    {
        event->PollEvent(keyboard);

        // Handle input and update state
        if (keyboard->getKey(KEY_ESC) || event->getEvent(EVENT_OUT))
        {
            running = false;
            break;
        }

        // Movement logic
        speedX = IDLE_X;  // Reset horizontal speed each frame
        if (keyboard->getKey(KEY_LEFT) || keyboard->getKey(KEY_A))
        {
            speedX = -DFLT_SPEEDX;
            marioState = RUN;
        }
        else if (keyboard->getKey(KEY_RIGHT) || keyboard->getKey(KEY_D))
        {
            speedX = DFLT_SPEEDX;
            marioState = RUN;
        }
        else if (marioState != JUMP)
        {
            marioState = IDLE;
        }

        // Jump logic
        if ((keyboard->getKey(KEY_SPACE) || keyboard->getKey(KEY_W) || keyboard->getKey(KEY_UP)) 
            && posY >= GROUND)
        {
            speedY = DFLT_SPEEDY;
            marioState = JUMP;
        }

        // Apply physics
        if (marioState == JUMP)
        {
            speedY += GRAVITY;  // Apply gravity
            posY += speedY;
            
            // Check ground collision
            if (posY >= GROUND)
            {
                posY = GROUND;
                speedY = 0.0;
                marioState = IDLE;
            }
        }
        
        posX += speedX;

        // Clear screen
        window->clear();

        // Render everything
        coin->render(100, 100, nullptr, 0.0, nullptr, SDL_FLIP_NONE);
        mario->render(posX, posY, nullptr, 0.0, nullptr, 
                     (speedX < 0) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);

        // Update screen
        window->update();

        // Add small delay to prevent 100% CPU usage
        SDL_Delay(16);  // ~60 FPS
    }

    // Cleanup
    delete coin;
    delete mario;
    delete keyboard;
    delete event;
    delete window;

    return 0;
}