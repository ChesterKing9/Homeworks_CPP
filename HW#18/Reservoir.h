#pragma once
#include <iostream>

class Reservoir {
public:
    virtual ~Reservoir() = default;
    virtual void showOperations() = 0;
    virtual void receiveInput() = 0;
    virtual void update() = 0;
    virtual float getVolume() const = 0;
    virtual void fill(float volume) = 0;
    virtual void use(float volume) = 0;
    virtual void refill() { std::cout << "Refill is not applicable for this reservoir.\n"; }
};

class WaterReservoir : public Reservoir {
public:
    void showOperations() override;
    void receiveInput() override;
    void update() override;
    float getVolume() const override { return m_Volume; }
    void fill(float volume) override;
    void use(float volume) override;
    void refill() override { fill(2.0f); std::cout << "Water reservoir refilled!\n"; }
private:
    float m_Volume = 2.0f;
};

class MilkReservoir : public Reservoir {
public:
    void showOperations() override;
    void receiveInput() override;
    void update() override;
    float getVolume() const override { return m_Volume; }
    void fill(float volume) override;
    void use(float volume) override;
    void refill() override { fill(1.0f); std::cout << "Milk reservoir refilled!\n"; }
private:
    float m_Volume = 1.0f;
};

class CoffeeGrainsContainer : public Reservoir {
public:
    void showOperations() override;
    void receiveInput() override;
    void update() override;
    float getVolume() const override { return m_Grains; }
    void fill(float volume) override;
    void use(float volume) override;
    void refill() override { fill(100.0f); std::cout << "Coffee grains container refilled!\n"; }
private:
    float m_Grains = 100.0f;
};
