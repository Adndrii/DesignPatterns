#ifndef PROXY_H
#define PROXY_H

#include <iostream>

class Hero {
public:
    virtual ~Hero() {}
    virtual void Attack() const = 0;
};

class AntiMage : public Hero {
public:
    void Attack() const override {
        std::cout << "Anti-Mage: Mana Void\n";
    }
};

class HeroProxy : public Hero {
private:
    Hero* real_hero_;

    bool CheckAccess() const {
        std::cout << "Proxy: Checking access prior to firing a real attack.\n";
        return true;
    }

    void LogAccess() const {
        std::cout << "Proxy: Logging the time of attack.\n";
    }

public:
    HeroProxy(Hero* real_hero) : real_hero_(real_hero) {}

    ~HeroProxy() {
        delete real_hero_;
    }

    void Attack() const override {
        if (CheckAccess()) {
            real_hero_->Attack();
            LogAccess();
        }
    }
};

#endif // PROXY_H
