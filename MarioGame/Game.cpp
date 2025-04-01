#include "Game.h"

Game::Game() : score(0), hiScore(0), isGameOver(false), gameOverSoundPlayed(false)
{
	initialize();
}

Game::~Game()
{
	cleanup();
}

void Game::initialize()
{
    // Initialize window
    window = new MainWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    window->setIcon(WINDOW_ICON_PATH);


    //Initialize textures
    background = new Texture(window->getRenderer());
    background->loadFromFile(IMG_BACKGROUND);

    ground = new Texture(window->getRenderer());
    ground->loadFromFile(IMG_GROUND);

    scoreFont = new Font(FONT_PATH, FONT_SCORE_SIZE);
    scoreFont->loadFromFile(FONT_PATH, FONT_SCORE_SIZE);
    scoreText = new Texture(window->getRenderer());
	hiScoreText = new Texture(window->getRenderer());
	scoreText->loadFromRenderedText(convertIntToString(score), *scoreFont, { 255, 255, 255, 255 }); // White color
	hiScoreText->loadFromRenderedText(convertIntToString(hiScore), *scoreFont, { 255, 255, 0 }); // Yellow color

	instructionFont = new Font(FONT_PATH, FONT_INSTRUCTION_SIZE);
	instructionFont->loadFromFile(FONT_PATH, FONT_INSTRUCTION_SIZE);
	instructionText = new Texture(window->getRenderer());
	instructionText->loadFromRenderedText("Press A, D, <-, -> to move. Press Space, W to jump. Press Enter to restart. Press Esc or Close the window to quit.", 
        *instructionFont, { 255, 255, 255, 255 }); // White color


    this->keyboard = new Keyboard();
    this->event = new Event();

    // Coins
    for (int i = 0; i < NUM_COINS; i++)
    {
        coins[i] = new Coin(window->getRenderer());
    }
    // Mario
    mario = new Mario(window->getRenderer());

    // Music and sound effects
	bgTheme = new Music(MUSIC_THEME_PATH);
	coinSound = new Sound(SOUND_COIN);
	lostSound = new Sound(SOUND_LOST);
	bgTheme->play();
}

void Game::update()
{
	// Check if the game is over
	if (isGameOver)
	{
		event->PollEvent(keyboard);
		// Check if the player wants to play again
		if (keyboard->getKey(KEY_ENTER))
		{
			resetGame();
		}
		return;
	}

	// If the game is not over
    event->PollEvent(keyboard);

    mario->move(keyboard);

    static SDL_Rect marioRect;
    static SDL_Rect coinRect[NUM_COINS];
   
    for (int i = 0; i < NUM_COINS; i++)
    {
        coins[i]->fall();

        marioRect = mario->getRect();
        coinRect[i] = coins[i]->getRect();

        /*std::cout << "Mario Rect: (" << marioRect.x << ", " << marioRect.y << ", " << marioRect.w << ", " << marioRect.h << ")"
            << " Coin[" << i << "] Rect: (" << coinRect[i].x << ", " << coinRect[i].y << ", " << coinRect[i].w << ", " << coinRect[i].h << ")" << std::endl;*/
        if (mario->checkMarioCollision(coinRect[i]))
        {
            //std::cout << "+1 coin" << std::endl;
			coinSound->play();
            // Reset the position of the if it collided with Mario
            score += 50;
            scoreText->loadFromRenderedText(convertIntToString(score), *scoreFont, {255, 255, 255, 255});
            coins[i]->reset();
        }
    }
	// Update the high score
	hiScore = std::max(hiScore, score);
	hiScoreText->loadFromRenderedText(convertIntToString(hiScore), *scoreFont, { 255, 255, 0 });

	//if the player's health is 0, the game is over
	if (mario->getHealth() == 0)
	{
		isGameOver = true;
	}
}

void Game::render()
{
    // Clear screen
    window->clear();

    // Render everything
    background->render(0, 0);
    scoreText->render(SCREEN_WIDTH / 2, 0);
	hiScoreText->render(0, 0);
    ground->render(0, GROUND);
	instructionText->render(0, 640);
    for (int i = 0; i < NUM_COINS; i++)
    {
        coins[i]->render();
    }
	mario->renderHealthBar(window->getRenderer());
    mario->render();

	if (isGameOver)
	{
        gameOver();
	}
    
    window->update();
}

void Game::run()
{
    while (!(keyboard->getKey(KEY_ESC) || event->getEvent()))
    {
        update();
        render();
        SDL_Delay(16); // 1000ms / 60frames ~ 16ms/frame (60fps)
    }
}

void Game::gameOver()
{
	// Avoid playing the game over sound multiple times
	if (!gameOverSoundPlayed)
	{
		bgTheme->stop();
        lostSound->play();
		gameOverSoundPlayed = true;
	}
	Font* gameOverFont = new Font(FONT_PATH, FONT_GAMEOVER_SIZE);
	gameOverFont->loadFromFile(FONT_PATH, FONT_GAMEOVER_SIZE);
	gameOverText = new Texture(window->getRenderer());
	gameOverText->loadFromRenderedText("Game Over", *gameOverFont, { 255, 255, 255, 255 });
	gameOverText->render(SCREEN_WIDTH / 5, SCREEN_HEIGHT / 3);
	isGameOver = true;
}

void Game::resetGame()
{
	// Reset the game
	bgTheme->play();
	score = 0;
	scoreText->loadFromRenderedText(convertIntToString(score), *scoreFont, { 255, 255, 255, 255 });
	mario->resetMario();
	for (int i = 0; i < NUM_COINS; i++)
	{
		coins[i]->reset();
	}
	isGameOver = false;
	gameOverSoundPlayed = false;
}

void Game::cleanup()
{
	delete bgTheme;
	delete coinSound;
	delete lostSound;
    delete keyboard;
    delete event;
    delete background;
    delete ground;
    delete scoreText;
	delete hiScoreText;
    delete gameOverText;
	delete instructionText;
    delete scoreFont;
	delete gameOverFont;
	delete instructionFont;
    for (int i = 0; i < NUM_COINS; i++)
    {
        delete coins[i];
    }
    delete mario;
    delete window;
}