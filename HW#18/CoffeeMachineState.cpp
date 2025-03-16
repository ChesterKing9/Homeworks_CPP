#include "CoffeeMachineState.h"
#include "CoffeeMachine.h"

void SleepState::showMenu(CoffeeMachine& machine) {
    std::cout << "1. POWER ON\n";
}

void SleepState::receiveInput(CoffeeMachine& machine) {
    int choice;
    std::cin >> choice;
    if (choice == 1) {
        machine.setState(new MainMenuState());
    }
}

void SleepState::update(CoffeeMachine& machine) {}

void MainMenuState::showMenu(CoffeeMachine& machine) {
    std::cout << "\n1. Prepare Drink\n2. Access Water Reservoir\n3. Access Milk Reservoir\n4. Power Off\n";
}

void MainMenuState::receiveInput(CoffeeMachine& machine) {
    int choice;
    std::cin >> choice;
    switch (choice) {
    case 1:
        machine.setState(new DrinkSelectionState());
        break;
    case 2:
        machine.accessWaterReservoir();
        break;
    case 3:
        machine.accessMilkReservoir();
        break;
    case 4:
        machine.setState(new SleepState());
        break;
    }
}

void MainMenuState::update(CoffeeMachine& machine) {}

void DrinkSelectionState::showMenu(CoffeeMachine& machine) {
    machine.showListOfDrinks();
}

void DrinkSelectionState::receiveInput(CoffeeMachine& machine) {
    machine.selectDrink();
}

void DrinkSelectionState::update(CoffeeMachine& machine) {
    machine.prepareDrink();
    machine.setState(new MainMenuState());
}
