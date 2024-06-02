#include "AbstractFactory.h"
#include <iostream>

void RadiantHero::use() {
    std::cout << "Using Radiant Hero" << std::endl;
}

void DireHero::use() {
    std::cout << "Using Dire Hero" << std::endl;
}

AbstractHero* RadiantFactory::createHero() {
    return new RadiantHero();
}

AbstractHero* DireFactory::createHero() {
    return new DireHero();
}
