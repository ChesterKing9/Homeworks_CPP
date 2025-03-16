#include "Reservoir.h"
#include <iostream>
#include <algorithm>

void WaterReservoir::showOperations() {
    std::cout << "\n--- Water level: " << getVolume() << "L ---\n";
    std::cout << "1. Fill up\n2. Back to main\n";
}

void WaterReservoir::receiveInput() {
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        fill(2.0f);
    }
}

void WaterReservoir::update() {}
void WaterReservoir::fill(float volume) { m_Volume = std::min(volume, 2.0f); }
void WaterReservoir::use(float volume) { m_Volume = std::max(0.0f, m_Volume - volume); }
void WaterReservoir::refill() {
    fill(2.0f);
    std::cout << "Water reservoir refilled!\n";
}

void MilkReservoir::showOperations() {
    std::cout << "\n--- Milk level: " << getVolume() << "L ---\n";
    std::cout << "1. Fill up\n2. Back to main\n";
}

void MilkReservoir::receiveInput() {
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        fill(1.0f);
    }
}

void MilkReservoir::update() {}
void MilkReservoir::fill(float volume) { m_Volume = std::min(volume, 1.0f); }
void MilkReservoir::use(float volume) { m_Volume = std::max(0.0f, m_Volume - volume); }
void MilkReservoir::refill() {
    fill(1.0f);
    std::cout << "Milk reservoir refilled!\n";
}

void CoffeeGrainsContainer::showOperations() {
    std::cout << "\n--- Coffee grains: " << getVolume() << "g ---\n";
    std::cout << "1. Refill\n2. Back to main\n";
}

void CoffeeGrainsContainer::receiveInput() {
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        fill(100.0f);
    }
}

void CoffeeGrainsContainer::update() {}
void CoffeeGrainsContainer::fill(float volume) { m_Grains = std::min(volume, 100.0f); }
void CoffeeGrainsContainer::use(float volume) { m_Grains = std::max(0.0f, m_Grains - volume); }
void CoffeeGrainsContainer::refill() {
    fill(100.0f);
    std::cout << "Coffee grains container refilled!\n";
}
