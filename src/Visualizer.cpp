#include "Visualizer.hpp"
#include <iostream>

Visualizer::Visualizer() 
{
    windowsize = 1024;
    waveform.setPrimitiveType(sf::LineStrip);
    waveform.resize(windowsize);
}

Visualizer::~Visualizer() 
{
}

void Visualizer::run() 
{
    window.create(sf::VideoMode(800, 600), "CPP-Vis");
    window.setFramerateLimit(60);

    if (!AudioEngine.loadFile(filePath)) 
    {
        return;
    }

    AudioEngine.play();

    while (window.isOpen())
    {
        EventProcess();
        update();
        render();
    }
}

void Visualizer::render() 
{
    window.create(800, 600);
    window.setFramerateLimit(60);
    
}

void::update() 
{

}

void::EventProcess()
{
    
}