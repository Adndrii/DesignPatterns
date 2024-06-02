#include "FactoryMethod.h"
#include <iostream>

void AntiMage::showHero() {
    std::cout << "Hero: Anti-Mage" << std::endl;
}

void CrystalMaiden::showHero() {
    std::cout << "Hero: Crystal Maiden" << std::endl;
}

Hero* AntiMageFactory::createHero() {
    return new AntiMage();
}

Hero* CrystalMaidenFactory::createHero() {
    return new CrystalMaiden();
}
