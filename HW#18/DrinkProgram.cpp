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
    case DrinkType::GreenTea:
        std::cout << "Green Tea!";
        break;
    case DrinkType::BlackTea:
        std::cout << "Black Tea!";
        break;
    case DrinkType::TeaWithMilk:
        std::cout << "Tea With Milk!";
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
    case DrinkType::GreenTea:
    {
        return prepareGreenTea();
    }
    case DrinkType::BlackTea:
    {
        return prepareBlackTea();
    }
    case DrinkType::TeaWithMilk:
    {
        return prepareTeaWithMilk();
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
    const double CappuccinoWaterVolume = 0.05;
    const double CappuccinoMilkVolume = 0.02;

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

DrinkProgramStatus DrinkProgram::prepareGreenTea()
{
	const double GreenTeaVolume = 0.05;
	if (m_context.m_waterReservoir.getVolume() < GreenTeaVolume)
	{
		return DrinkProgramStatus::LowWater;
	}
	m_context.m_waterReservoir.useWater(GreenTeaVolume);

	std::cout << "\n\nGrrr ";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << ".";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << ".";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << ".";
	std::this_thread::sleep_for(std::chrono::seconds(1));

	std::cout << "\nPreparing... Green Tea... ";
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

DrinkProgramStatus DrinkProgram::prepareBlackTea()
{
	const double BlackTeaVolume = 0.05;
	if (m_context.m_waterReservoir.getVolume() < BlackTeaVolume)
	{
		return DrinkProgramStatus::LowWater;
	}

	m_context.m_waterReservoir.useWater(BlackTeaVolume);
	std::cout << "\n\nGrrr ";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << ".";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << ".";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << ".";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "\nPreparing... Black Tea... ";
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

DrinkProgramStatus DrinkProgram::prepareTeaWithMilk()
{
    const double TeaWithMilkWaterVolume = 0.05;
    const double TeaWithMilkMilkVolume = 0.02;

    if (m_context.m_waterReservoir.getVolume() < TeaWithMilkWaterVolume)
    {
        return DrinkProgramStatus::LowWater;
    }

    if (m_context.m_milkReservoir.getVolume() < TeaWithMilkMilkVolume)
    {

        return DrinkProgramStatus::LowMilk;
    }

    m_context.m_waterReservoir.useWater(TeaWithMilkWaterVolume);
    m_context.m_milkReservoir.useMilk(TeaWithMilkMilkVolume);

    std::cout << "\n\nGrrr ";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "\nPreparing... TeaWithMilk... ";
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
