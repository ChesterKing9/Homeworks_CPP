#pragma once
#include "CoffeeMachine.h"

class DrinkProgram {
public:
    virtual ~DrinkProgram() = default;
    virtual void showInfo() const = 0;
    virtual DrinkProgramStatus prepare() = 0;
};

class Coffee : public DrinkProgram {
public:
    Coffee(CoffeeMachine& context) : m_context(context) {}
protected:
    CoffeeMachine& m_context;
};

class Espresso : public Coffee {
public:
    Espresso(CoffeeMachine& context) : Coffee(context) {}
    void showInfo() const override;
    DrinkProgramStatus prepare() override;
};

class Cappuccino : public Coffee {
public:
    Cappuccino(CoffeeMachine& context) : Coffee(context) {}
    void showInfo() const override;
    DrinkProgramStatus prepare() override;
};

class Tea : public DrinkProgram {
public:
    Tea(CoffeeMachine& context) : m_context(context) {}
protected:
    CoffeeMachine& m_context;
};

class BlackTea : public Tea {
public:
    BlackTea(CoffeeMachine& context) : Tea(context) {}
    void showInfo() const override;
    DrinkProgramStatus prepare() override;
};

class GreenTea : public Tea {
public:
    GreenTea(CoffeeMachine& context) : Tea(context) {}
    void showInfo() const override;
    DrinkProgramStatus prepare() override;
};
