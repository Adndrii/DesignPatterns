#include "Adapter.h"

Hero::Hero(const std::string& name, const std::string& primaryAttribute,
    const std::string& ability1, const std::string& ability2,
    const std::string& ability3, const std::string& ultimate)
    : name(name), primaryAttribute(primaryAttribute),
    ability1(ability1), ability2(ability2), ability3(ability3), ultimate(ultimate) {}

void Hero::DisplayAbilities() const {
    std::cout << "Hero: " << name << std::endl;
    std::cout << "Primary Attribute: " << primaryAttribute << std::endl;
    std::cout << "Abilities:" << std::endl;
    std::cout << "- " << ability1 << std::endl;
    std::cout << "- " << ability2 << std::endl;
    std::cout << "- " << ability3 << std::endl;
    std::cout << "Ultimate: " << ultimate << std::endl;
}