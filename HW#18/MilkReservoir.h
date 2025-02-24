#pragma once
#include <chrono>

class MilkReservoir
{
public:
    MilkReservoir();

    void showOperations();
    void receiveInput();
    void update();

    void fill(float volume);
    void useMilk(float volume);
    float getVolume() const;
    bool checkFreshness(int freshnessDurationSeconds) const;

private:
    float volume;
    bool milkIsFresh;
    int m_Operation;
    std::chrono::steady_clock::time_point startTime;

    static const float MaxVolume;
};

const float MaxVolume = 1.0f;
