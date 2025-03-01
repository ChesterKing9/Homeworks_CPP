#include "Coffee.h"
#include "DrinkProgram.h"
#include "CoffeeMachine.h"
#include "WaterReservoir.h"
#include "MilkReservoir.h"
#include <iostream>
#include <chrono>
#include <thread>

void Espresso::showInfo() const
{
	std::cout << "Espresso!";
}

DrinkProgramStatus Espresso::prepare() {
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

DrinkProgramStatus Cappuccino::prepare()
{
	const double CappuccinoWaterVolume = 0.05;
	const double CappuccinoMilkVolume = 0.02;
	if (m_context.m_waterReservoir.getVolume() < CappuccinoWaterVolume)
	{
		std::cout << "Low water level!" << std::endl;
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