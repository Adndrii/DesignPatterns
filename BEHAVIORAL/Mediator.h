#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <iostream>
#include <string>
#include <vector>

class BaseComponent;

class Mediator {
public:
    virtual void Notify(BaseComponent* sender, std::string event) const = 0;
};

class BaseComponent {
protected:
    Mediator* mediator_;

public:
    BaseComponent(Mediator* mediator = nullptr) : mediator_(mediator) {}
    void set_mediator(Mediator* mediator) {
        this->mediator_ = mediator;
    }
};

class HeroComponent : public BaseComponent {
public:
    using BaseComponent::BaseComponent;
};

class RadiantHero : public HeroComponent {
public:
    using HeroComponent::HeroComponent;

    void Attack() {
        std::cout << "Radiant Hero attacks.\n";
        this->mediator_->Notify(this, "Attack");
    }

    void Defend() {
        std::cout << "Radiant Hero defends.\n";
        this->mediator_->Notify(this, "Defend");
    }
};

class DireHero : public HeroComponent {
public:
    using HeroComponent::HeroComponent;

    void CastSpell() {
        std::cout << "Dire Hero casts a spell.\n";
        this->mediator_->Notify(this, "CastSpell");
    }

    void Retreat() {
        std::cout << "Dire Hero retreats.\n";
        this->mediator_->Notify(this, "Retreat");
    }
};

class Dota2Mediator : public Mediator {
private:
    RadiantHero* radiantHero_;
    DireHero* direHero_;

public:
    Dota2Mediator(RadiantHero* rh, DireHero* dh) : radiantHero_(rh), direHero_(dh) {
        this->radiantHero_->set_mediator(this);
        this->direHero_->set_mediator(this);
    }

    void Notify(BaseComponent* sender, std::string event) const override {
        if (event == "Attack") {
            std::cout << "Mediator reacts to Radiant attack and triggers Dire to cast spell:\n";
            this->direHero_->CastSpell();
        }
        if (event == "Retreat") {
            std::cout << "Mediator reacts to Dire retreat and triggers Radiant to defend:\n";
            this->radiantHero_->Defend();
        }
    }
};

#endif // MEDIATOR_H
