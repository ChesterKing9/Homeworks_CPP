#include "CoffeeMachine.h"
#include "DrinkProgram.h"
#include <iostream>

CoffeeMachine::CoffeeMachine()
    : m_waterReservoir(new WaterReservoir()),
    m_milkReservoir(new MilkReservoir()),
    m_coffeeGrainsContainer(new CoffeeGrainsContainer()),
    m_currentState(new SleepState()) {
}

CoffeeMachine::~CoffeeMachine() {
    for (auto* drink : m_recipes) {
        delete drink;
    }
    m_recipes.clear();
    delete m_currentState;
    delete m_waterReservoir;
    delete m_milkReservoir;
    delete m_coffeeGrainsContainer;
}

void CoffeeMachine::initDefaultDrinks() {
    m_recipes.push_back(new Espresso(*this));
    m_recipes.push_back(new Cappuccino(*this));
    m_recipes.push_back(new BlackTea(*this));
    m_recipes.push_back(new GreenTea(*this));
}

void CoffeeMachine::setState(CoffeeMachineState* newState) {
    if (m_currentState) {
        delete m_currentState;
    }
    m_currentState = newState ? newState : new SleepState();
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
        if (m_SelectedDrink) {
            prepareDrink();
        }
    }
}

DrinkProgramStatus CoffeeMachine::prepareDrink() {
    if (!m_SelectedDrink) return DrinkProgramStatus::LowWater;
    return m_SelectedDrink->prepare();
}

void CoffeeMachine::accessWaterReservoir() {
    m_waterReservoir->showOperations();
    m_waterReservoir->receiveInput();
    m_waterReservoir->update();
}

void CoffeeMachine::accessMilkReservoir() {
    m_milkReservoir->showOperations();
    m_milkReservoir->receiveInput();
    m_milkReservoir->update();
}

void CoffeeMachine::accessCoffeeGrainsContainer() {
    m_coffeeGrainsContainer->showOperations();
    m_coffeeGrainsContainer->receiveInput();
    m_coffeeGrainsContainer->update();
}
