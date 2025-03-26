#include "Background.h"

Background::Background(SDL_Renderer* renderer, const std::string& path)
    : t{ renderer }
{
    t.loadFromFile(path);
}

void Background::render() {
    t.render(0, 0);
}

