#pragma once
#include <iostream>
#include <vector>
#include "DrinkProgram.h"
#include "CoffeeMachineState.h"
#include "Reservoir.h"

class CoffeeMachine {
public:
    ~CoffeeMachine();
    bool IsBooted() const { return !m_powerOffRequest; }
    void initDefaultDrinks();
    void addDrinkReceipt(DrinkProgram* program);
    void showMenu();
    void receiveInput();
    void update();
    void setState(CoffeeMachineState* newState);
    void showListOfDrinks();
    void prepareDrink();
    void selectDrink();
    void accessWaterReservoir();
    void accessMilkReservoir();
    void accessCoffeeGrainsContainer();
private:
    CoffeeMachineState* m_currentState;
    std::vector<DrinkProgram*> m_recipes;
    DrinkProgram* m_SelectedDrink = nullptr;
    Reservoir* m_waterReservoir;
    Reservoir* m_milkReservoir;
    Reservoir* m_coffeeGrainsContainer;
    int m_currentChoice = -1;
    bool m_powerOffRequest = false;
};
