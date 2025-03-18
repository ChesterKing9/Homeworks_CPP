#include "Monster.h"
#include <iostream>
#include "Game.cpp"

void UI::printMonsterInfo(Monster* monster) {
    std::cout << monster->getFullInfo() << std::endl;
}