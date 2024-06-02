#ifndef ADAPTER_H
#define ADAPTER_H

#include <iostream>
#include <string>

class Hero {
private:
    std::string name;
    std::string primaryAttribute;
    std::string ability1;
    std::string ability2;
    std::string ability3;
    std::string ultimate;

public:
    Hero(const std::string& name, const std::string& primaryAttribute,
        const std::string& ability1, const std::string& ability2,
        const std::string& ability3, const std::string& ultimate);

    void DisplayAbilities() const;
};

#endif //ADAPTER_H
