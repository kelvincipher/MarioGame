#ifndef INTRO_H
#define INTRO_H

#include "Defs.h"
#include "Texture.h"
#include "Font.h"
#include "Mainwindow.h"
#include "Background.h"

class Intro {
    const MainWindow& win;
    Background background;
    Texture title;
    Texture subtitle;

public:
    Intro(const MainWindow&);
    Intro(const Intro&) = delete;
    Intro& operator=(const Intro&) = delete;

    void render();
};

#endif // INTRO_H
