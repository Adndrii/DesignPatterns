#include "Prototype.h"
#include <iostream>

AntiMagePrototype::AntiMagePrototype(const std::string& name) : name(name) {}

HeroPrototype* AntiMagePrototype::clone() const {
    return new AntiMagePrototype(*this);
}

void AntiMagePrototype::use() const {
    std::cout << "Using Anti-Mage Prototype: " << name << std::endl;
}

CrystalMaidenPrototype::CrystalMaidenPrototype(const std::string& name) : name(name) {}

HeroPrototype* CrystalMaidenPrototype::clone() const {
    return new CrystalMaidenPrototype(*this);
}

void CrystalMaidenPrototype::use() const {
    std::cout << "Using Crystal Maiden Prototype: " << name << std::endl;
}
