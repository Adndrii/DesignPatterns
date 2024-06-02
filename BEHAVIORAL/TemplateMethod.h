#ifndef TEMPLATE_METHOD_H
#define TEMPLATE_METHOD_H

#include <iostream>
#include <string>


class Hero {
public:
    void TemplateMethod() const {
        this->BaseOperation1();
        this->RequiredAbility1();
        this->BaseOperation2();
        this->Hook1();
        this->RequiredAbility2();
        this->BaseOperation3();
        this->Hook2();
    }

protected:
    void BaseOperation1() const {
        std::cout << "Hero says: Preparing for battle\n";
    }
    void BaseOperation2() const {
        std::cout << "Hero says: Using abilities\n";
    }
    void BaseOperation3() const {
        std::cout << "Hero says: Battle ended\n";
    }

    virtual void RequiredAbility1() const = 0;
    virtual void RequiredAbility2() const = 0;

    virtual void Hook1() const {}
    virtual void Hook2() const {}
};

class AntiMage : public Hero {
protected:
    void RequiredAbility1() const override {
        std::cout << "Anti-Mage uses: Blink\n";
    }
    void RequiredAbility2() const override {
        std::cout << "Anti-Mage uses: Mana Void\n";
    }
};

class Axe : public Hero {
protected:
    void RequiredAbility1() const override {
        std::cout << "Axe uses: Berserker's Call\n";
    }
    void RequiredAbility2() const override {
        std::cout << "Axe uses: Culling Blade\n";
    }
    void Hook1() const override {
        std::cout << "Axe says: Overridden Hook1\n";
    }
};

#endif // TEMPLATE_METHOD_H
