#ifndef BRIDGE_H
#define BRIDGE_H
#include <iostream>
#include <string>

class Hero {
public:
    virtual ~Hero() {}
    virtual std::string Ability() const = 0;
};

class QueenOfPain : public Hero {
public:
    std::string Ability() const override {
        return "Queen Of Pain: Blink\n";
    }
};

class LegionCommander : public Hero {
public:
    std::string Ability() const override {
        return "Legion Commander: Duel\n";
    }
};

#endif