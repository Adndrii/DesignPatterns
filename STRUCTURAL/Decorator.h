#ifndef DECORATOR_H
#define DECORATOR_H

#include <iostream>
#include <string>

class Ability {
public:
    virtual ~Ability() {}
    virtual std::string Operation() const = 0;
};

class BasicAbility : public Ability {
public:
    std::string Operation() const override {
        return "Basic Ability";
    }
};

class Decorator : public Ability {
protected:
    Ability* ability_;

public:
    Decorator(Ability* ability) : ability_(ability) {}
    std::string Operation() const override {
        return ability_->Operation();
    }
};

class EnhancedAbility : public Decorator {
public:
    EnhancedAbility(Ability* ability) : Decorator(ability) {}
    std::string Operation() const override {
        return "Enhanced Ability (" + Decorator::Operation() + ")";
    }
};

#endif // DECORATOR_H
