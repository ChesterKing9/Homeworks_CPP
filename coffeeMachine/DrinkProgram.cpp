#include "DrinkProgram.h"
#include "CoffeeMachine.h"
#include "MilkReservoir.h"
#include <chrono>
#include <thread>

DrinkProgram::DrinkProgram(DrinkType type, CoffeeMachine& context) :
    m_drinkType(type),
    m_context(context) {
}

void DrinkProgram::showInfo()
{
    switch (m_drinkType)
    {
    case DrinkType::Espresso:
        std::cout << "Espresso!";
        break;
    case DrinkType::Cappuccino:
        std::cout << "Cappuccino!";
        break;
    default:
        break;
    }
}

DrinkProgramStatus DrinkProgram::prepare()
{
    switch (m_drinkType)
    {
    case DrinkType::Espresso:
    {
        return prepareEspresso();
    }
    case DrinkType::Cappuccino:
    {
        return prepareCappuccino();
    }
    default:
        break;
    };

    return DrinkProgramStatus::Success;
}

DrinkProgramStatus DrinkProgram::prepareEspresso()
{
    const double EspressoVolume = 0.05; 

    if (m_context.m_waterReservoir.getVolume() < EspressoVolume)
    {
        std::cout << "Low water level!" << std::endl;
        return DrinkProgramStatus::LowWater;
    }

    m_context.m_waterReservoir.useWater(EspressoVolume);

    std::cout << "\n\nGrrr ";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "\nPreparing... Espresso... ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 5; i > 3; i--)
    {
        std::cout << i << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "..Hanging... ";
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "DONE!\n\n";

    return DrinkProgramStatus::Success;
}

DrinkProgramStatus DrinkProgram::prepareCappuccino()
{
    const double CappuccinoWaterVolume = 0.1;
    const double CappuccinoMilkVolume = 0.1;

    if (m_context.m_waterReservoir.getVolume() < CappuccinoWaterVolume)
    {
        return DrinkProgramStatus::LowWater;
    }

    if (m_context.m_milkReservoir.getVolume() < CappuccinoMilkVolume)
    {
        
        return DrinkProgramStatus::LowMilk;
    }

    m_context.m_waterReservoir.useWater(CappuccinoWaterVolume);
    m_context.m_milkReservoir.useMilk(CappuccinoMilkVolume);

    std::cout << "\n\nGrrr ";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "\nPreparing... Cappuccino... ";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for (int i = 5; i > 3; i--)
    {
        std::cout << i << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ".";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "..Hanging... ";
    std::this_thread::sleep_for(std::chrono::seconds(3));

    std::cout << "DONE!\n\n";

    return DrinkProgramStatus::Success;
}
