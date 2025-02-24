#pragma once
#include "CoffeeMachine.h"
#include <iostream>

//enum class DrinkType
//{
//    Espresso,
//    Cappuccino,
//    GreenTea,
//    BlackTea,
//    TeaWithMilk
//};

enum class DrinkProgramStatus
{
    Success = 0,
    LowWater,
    LowMilk,
    CleanNeeded,    //Not implemented
};

class CoffeeMachine;


class DrinkProgram
{
public:
    virtual ~DrinkProgram() = default; 

    virtual void showInfo() const = 0;
    virtual DrinkProgramStatus prepare() = 0;

protected:
	DrinkProgram(CoffeeMachine& context) : m_context(context) {}

	CoffeeMachine& m_context;
};

