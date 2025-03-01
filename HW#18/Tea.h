#pragma once

#include "DrinkProgram.h"

class Tea : public DrinkProgram
{
public:
	using DrinkProgram::DrinkProgram;
};

class BlackTea : public Tea 
{
public:
	BlackTea(CoffeeMachine& context) : Tea(context) {}
	void showInfo() const override {}
	DrinkProgramStatus prepare() override;
};

class GreenTea : public Tea
{
public:
	GreenTea(CoffeeMachine& context) : Tea(context) {}
	void showInfo() const override {}
	DrinkProgramStatus prepare() override;
};

class TeaWithMilk : public Tea {
public:
	TeaWithMilk(CoffeeMachine& context) : Tea(context) {}
	void showInfo() const override {}
	DrinkProgramStatus prepare() override;
};