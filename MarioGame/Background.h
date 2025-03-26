#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Texture.h"

#include <string>
#include <SDL.h>

class Background {
    Texture t;
public:
    Background(SDL_Renderer* renderer, const std::string& path);

    void render();
};

#endif // BACKGROUND_H