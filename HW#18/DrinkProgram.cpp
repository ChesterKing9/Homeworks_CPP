#include "CoffeeMachine.h"
#include "DrinkProgram.h"
#include <iostream>


void CoffeeMachine::initDefaultDrinks() {
    m_recipes.push_back(new Espresso(*this));
    m_recipes.push_back(new Cappuccino(*this));
    m_recipes.push_back(new BlackTea(*this));
    m_recipes.push_back(new GreenTea(*this));
    m_currentState = new SleepState();
}

void CoffeeMachine::setState(CoffeeMachineState* newState) {
    delete m_currentState;
    m_currentState = newState;
}

void CoffeeMachine::showMenu() {
    m_currentState->showMenu(*this);
}

void CoffeeMachine::receiveInput() {
    m_currentState->receiveInput(*this);
}

void CoffeeMachine::update() {
    m_currentState->update(*this);
}

void CoffeeMachine::showListOfDrinks() {
    std::cout << "\nAvailable Drinks:\n";
    for (size_t i = 0; i < m_recipes.size(); ++i) {
        std::cout << i + 1 << ". ";
        m_recipes[i]->showInfo();
        std::cout << "\n";
    }
}

void CoffeeMachine::selectDrink() {
    int choice;
    std::cout << "Select a drink: ";
    std::cin >> choice;
    if (choice > 0 && choice <= static_cast<int>(m_recipes.size())) {
        m_SelectedDrink = m_recipes[choice - 1];
        prepareDrink();
    }
}

void CoffeeMachine::prepareDrink() {
    if (!m_SelectedDrink) return;
    DrinkProgramStatus status = m_SelectedDrink->prepare();
    if (status == DrinkProgramStatus::LowWater) {
        std::cout << "LOW WATER! Please refill the container.\n";
    }
}

void CoffeeMachine::accessWaterReservoir() {
    m_waterReservoir.showOperations();
}

void CoffeeMachine::accessMilkReservoir() {
    m_milkReservoir.showOperations();
}
