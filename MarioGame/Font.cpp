#include "Font.h"
#include "Exception.h"

// Constructor
Font::Font()
    : gFont{ nullptr } {
}

// Constructor with path and size
Font::Font(const std::string& path, int size)
    : Font()
{
    loadFromFile(path, size);
}

// Deconstructor
Font::~Font()
{
    free();
}

// Load font from file
void Font::loadFromFile(const std::string& path, int size)
{
    free();

    gFont = TTF_OpenFont(path.c_str(), size);
    if (gFont == nullptr) {
        logErrorAndExit("Failed to load font! SDL_ttf Error: ", TTF_GetError());
    }
}

// Free the font
void Font::free()
{
    if (gFont != nullptr) {
        TTF_CloseFont(gFont);
    }
}