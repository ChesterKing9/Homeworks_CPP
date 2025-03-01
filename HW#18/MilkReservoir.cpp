#include "MilkReservoir.h"
#include <iostream>
#include <algorithm>

const float MilkReservoir::MaxVolume = 1.0f;

MilkReservoir::MilkReservoir() : volume(0.0f), milkIsFresh(true), m_Operation(0) {
    startTime = std::chrono::steady_clock::now();
}

void MilkReservoir::showOperations()
{
    std::cout << "\n--- Current milk level: " << getVolume() << "l out of " << MaxVolume << "l max ---\n";
    std::cout << "1. Empty reservoir\n";
    std::cout << "2. Fill up with milk\n";
    std::cout << "3. Back to main\n";
}

void MilkReservoir::receiveInput()
{
    std::cout << "Choice: ";
    std::cin >> m_Operation;
}

void MilkReservoir::update()
{
    switch (m_Operation)
    {
    case 1:
        volume = 0.0f;
        milkIsFresh = false;
        break;
    case 2:
    {
        float newVolume = 0.0f;
        std::cout << "Filling...";
        std::cout << "How much have you filled up? (Max: " << MaxVolume << "l) ";
        std::cin >> newVolume;

        volume = std::min(newVolume, MaxVolume);
        milkIsFresh = true;
        startTime = std::chrono::steady_clock::now();

        std::cout << std::endl;
        break;
    }
    case 3:
    default:
        break;
    }
}

void MilkReservoir::fill(float volume)
{
    this->volume = volume;
    milkIsFresh = true;
    startTime = std::chrono::steady_clock::now();
}

void MilkReservoir::useMilk(float volume)
{
    if (milkIsFresh) {
        if (this->volume >= volume) {
            this->volume -= volume;
        }
        else {
            std::cout << "Not enough milk available.\n";
        }
    }
    else {
        std::cout << "Milk has gone bad, please refill.\n";
    }
}

float MilkReservoir::getVolume() const
{
    return volume;
}

bool MilkReservoir::checkFreshness(int freshnessDurationSeconds) const
{
    auto currentTime = std::chrono::steady_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();
    return duration <= freshnessDurationSeconds;
}
