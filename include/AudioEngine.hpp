#pragma once
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#ifndef AUDIO_ENGINE_HPP
#define AUDIO_ENGINE_HPP

class AudioEngine {
public:
    AudioEngine();
    ~AudioEngine();

    bool loadFile(const std::string& filePath);
    void play();
    
    // analysis occurs here
    float getLoudestMomentTime(float& outMaxAmplitude);
    void printAnalysis() const;

private:
    sf::SoundBuffer buffer;
    sf::Sound sound;
};

#endif
