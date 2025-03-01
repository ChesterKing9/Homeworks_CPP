#include <iostream>
#include <vector>

#include "CoffeeMachine.h"
#include "DrinkProgram.h"

int main()
{
    CoffeeMachine machine;

    machine.initDefaultDrinks();    //available drinks

    while (machine.IsBooted())
    {
        machine.showMenu();
        machine.receiveInput();
        machine.update();
    }

    return 0;
}