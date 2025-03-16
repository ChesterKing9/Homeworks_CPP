#pragma once
#include <iostream>
#include "CoffeeMachine.h"
class CoffeeMachine;

class CoffeeMachineState {
public:
    virtual ~CoffeeMachineState() = default;
    virtual void showMenu(CoffeeMachine& machine) = 0;
    virtual void receiveInput(CoffeeMachine& machine) = 0;
    virtual void update(CoffeeMachine& machine) = 0;
};

// Sleep mode
class SleepState : public CoffeeMachineState {
public:
    void showMenu(CoffeeMachine& machine) override;
    void receiveInput(CoffeeMachine& machine) override;
    void update(CoffeeMachine& machine) override;
};

// Main menu
class MainMenuState : public CoffeeMachineState {
public:
    void showMenu(CoffeeMachine& machine) override;
    void receiveInput(CoffeeMachine& machine) override;
    void update(CoffeeMachine& machine) override;
};

// Beverege selection
class DrinkSelectionState : public CoffeeMachineState {
public:
    void showMenu(CoffeeMachine& machine) override;
    void receiveInput(CoffeeMachine& machine) override;
    void update(CoffeeMachine& machine) override;
};
