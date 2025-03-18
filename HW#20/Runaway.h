#pragma once
#include <string>
#include <vector>
#include "Munchkin.h"

class Runaway {
public:
    virtual void apply(Munchkin* munchkin) = 0;
    virtual std::string getFullInfo() const { return "Unknown runaway effect."; }
};

class Runaway_LevelDowngrade : public Runaway {
public:
    Runaway_LevelDowngrade(int level) : m_levelToDowngrade(level) {}
    void apply(Munchkin* munchkin) override { munchkin->updateLevelBy(-m_levelToDowngrade); }
    std::string getFullInfo() const override { return "Level is dropped by " + std::to_string(m_levelToDowngrade); }
private:
    int m_levelToDowngrade;
};

class Runaway_ItemEquipedRemoval : public Runaway {
public:
    void apply(Munchkin* munchkin) override {
        if (!munchkin->getItems().empty()) {
            munchkin->removeItemEquipped();
        }
    }
    std::string getFullInfo() const override { return "Loses one equipped item."; }
};

class Runaway_ModifierFromHandRemoval : public Runaway {
public:
    void apply(Munchkin* munchkin) override {
        if (!munchkin->getModifiers().empty()) {
            munchkin->removeModifierFromHand();
        }
    }
    std::string getFullInfo() const override { return "Loses one card from hand."; }
};

class Runaway_BiggestBonusCardRemoval : public Runaway {
public:
    void apply(Munchkin* munchkin) override {
        munchkin->removeBiggestBonusItem();
    }
    std::string getFullInfo() const override { return "Loses the most powerful equipped item."; }
};