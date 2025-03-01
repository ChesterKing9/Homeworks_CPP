#pragma once

enum class DrinkType
{
    Espresso,
    Cappuccino
};

enum class DrinkProgramStatus
{
    Success = 0,
    LowWater,
    LowMilk,
    CleanNeeded,    //Not implemented
};


class DrinkProgram
{
public:
    DrinkProgram(DrinkType type, class CoffeeMachine& context); //forward declaration of CoffeeMachine class, to not include header here, only in .cpp

    void showInfo();
    DrinkProgramStatus prepare();

private:
    DrinkType m_drinkType;

    const float EsspressoVolume = 0.05f;
    const float CappuccinoWaterVolume = 0.1f;
    const float CappuccinoMilkVolume = 0.1f;

    class CoffeeMachine& m_context; //Aggregation, Drink program doesn't own CoffeeMachine

    DrinkProgramStatus prepareEspresso();
    DrinkProgramStatus prepareCappuccino();
};