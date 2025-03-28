#ifndef MUSIC_H
#define MUSIC_H

#include <SDL_mixer.h>
#include <string>

// Playing background theme (Needs looping)
class Music {
    Mix_Music* gMusic;
public:
    Music();
    Music(const std::string& path);
    ~Music();

    Music(const Music&) = delete;
    Music& operator=(const Music&) = delete;

    void play();
    void pause();
    void stop();
};

// Playing sound effect (play at once)
class Sound {
    Mix_Chunk* gChunk;
public:
    Sound();
    Sound(const std::string& path);
    ~Sound();

    Sound(const Sound&) = delete;
    Sound& operator=(const Sound&) = delete;

    void play();
};


#endif // MUSIC_H