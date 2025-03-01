#pragma once

#include "DrinkProgram.h"

class Coffee : public DrinkProgram
{
public:
	using DrinkProgram::DrinkProgram;
};

class Espresso : public Coffee {
public:
	Espresso(CoffeeMachine& context) : Coffee(context) {}

	void showInfo() const override {}
	DrinkProgramStatus prepare() override;	
};

class Cappuccino : public Coffee {
public:
	Cappuccino(CoffeeMachine& context) : Coffee(context) {}
	void showInfo() const override {}
	DrinkProgramStatus prepare() override;
};