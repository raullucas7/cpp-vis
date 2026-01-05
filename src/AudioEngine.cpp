#include "AudioEngine.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>

AudioEngine::AudioEngine() {
}

AudioEngine::~AudioEngine() {
}

void AudioEngine::play() {
    sound.play();
}
// -------------------------------
bool AudioEngine::loadFile(const std::string& filePath) {
    if (!buffer.loadFromFile(filePath)) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return false;
    }
    sound.setBuffer(buffer);
    return true;
}

