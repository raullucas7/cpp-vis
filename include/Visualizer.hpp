#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP
#pragma once
#include <SFML/Graphics.hpp>
#include "AudioEngine.hpp"

class Visualizer {
public:
    Visualizer();
    ~Visualizer();
    AudioEngine();

    void run(const std::string& filePath);
    void render();
    void EventProcess();
    void update();

private:
    sf::RenderWindow window;
    sf::VertexArray waveform;

    // engine instance
    AudioEngine audioEngine;
    std::size_t samplecount;
};

#endif
