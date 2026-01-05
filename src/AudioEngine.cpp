#include "AudioEngine.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>

AudioEngine::AudioEngine() 
{
}

AudioEngine::~AudioEngine() 
{
}

void AudioEngine::play() 
{
    sound.play();
}
// -------------------------------
bool AudioEngine::loadFile(const std::string& filePath) 
{
    if (!buffer.loadFromFile(filePath)) 
    {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return false;
    }
    sound.setBuffer(buffer);
    return true;
}

float AudioEngine::getLoudestMomentTime(float& outMaxAmplitude) 
{
    const sf::Int16* samples = buffer.getSamples();
    std::size_t totalSamples = buffer.getSampleCount();
    unsigned int sampleRate = buffer.getSampleRate();
    unsigned int channels = buffer.getChannelCount();

    float maxAmplitude = 0.0f;
    std::size_t maxIndex = 0;

    for (std::size_t i = 0; i < totalSamples; ++i) 
    {
        float absValue = std::abs(samples[i]) / 32768.0f; 
        if (absValue > maxAmplitude) 
        {
            maxAmplitude = absValue;
            maxIndex = i;
        }
    }

    outMaxAmplitude = maxAmplitude;
    if (channels == 0 || sampleRate == 0) return 0.0f;
    return (float)(maxIndex / channels) / sampleRate;
}

void AudioEngine::printAnalysis() const 
{
    unsigned int sampleRate = buffer.getSampleRate();
    unsigned int channels = buffer.getChannelCount();
    std::size_t totalSamples = buffer.getSampleCount();
    
    std::cout << "=== AUDIO ANALYSIS (SFML) ===\n";
    std::cout << "Total Samples: " << totalSamples << "\n";
    std::cout << "Sample Rate: " << sampleRate << " Hz\n";
    std::cout << "Channels: " << channels << "\n";
}
