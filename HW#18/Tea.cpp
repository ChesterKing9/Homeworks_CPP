#include "Tea.h"
#include "CoffeeMachine.h"
#include "MilkReservoir.h"
#include <iostream>
#include "WaterReservoir.h"
#include <chrono>
#include <thread>

void BlackTea::showInfo() const
{
	std::cout << "Black Tea!";
}

DrinkProgramStatus BlackTea::prepare()
{
	const double BlackTeaVolume = 0.05;
	if (m_context.m_waterReservoir.getVolume() < BlackTeaVolume)
	{
		std::cout << "Low water level!" << std::endl;
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

DrinkProgramStatus GreenTea::prepare()
{
	const double BlackTeaVolume = 0.05;
	if (m_context.m_waterReservoir.getVolume() < BlackTeaVolume)
	{
		std::cout << "Low water level!" << std::endl;
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

DrinkProgramStatus TeaWithMilk::prepare()
{
	const double TeaWithMilkVolume = 0.05;
	const double TeaWithMilkMilkVolume = 0.02;
	if (m_context.m_waterReservoir.getVolume() < TeaWithMilkVolume)
	{
		std::cout << "Low water level!" << std::endl;
		return DrinkProgramStatus::LowWater;
	}
	if (m_context.m_milkReservoir.getVolume() < TeaWithMilkMilkVolume)
	{

		return DrinkProgramStatus::LowMilk;
	}
	m_context.m_waterReservoir.useWater(TeaWithMilkVolume);
	m_context.m_milkReservoir.useMilk(TeaWithMilkMilkVolume);

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