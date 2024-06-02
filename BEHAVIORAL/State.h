#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <typeinfo>

class HeroContext;

class HeroState {
protected:
    HeroContext* context_;

public:
    virtual ~HeroState() {}

    void set_context(HeroContext* context) {
        this->context_ = context;
    }

    virtual void Attack() = 0;
    virtual void UseAbility() = 0;
};

class HeroContext {
private:
    HeroState* state_;

public:
    HeroContext(HeroState* state) : state_(nullptr) {
        this->TransitionTo(state);
    }

    ~HeroContext() {
        delete state_;
    }

    void TransitionTo(HeroState* state) {
        std::cout << "HeroContext: Transition to " << typeid(*state).name() << ".\n";
        if (this->state_ != nullptr)
            delete this->state_;
        this->state_ = state;
        this->state_->set_context(this);
    }

    void RequestAttack() {
        this->state_->Attack();
    }

    void RequestAbility() {
        this->state_->UseAbility();
    }
};

// Concrete State classes representing different hero states
class MeleeState : public HeroState {
public:
    void Attack() override;

    void UseAbility() override {
        std::cout << "MeleeState uses a melee ability.\n";
    }
};

class RangedState : public HeroState {
public:
    void Attack() override {
        std::cout << "RangedState attacks from a distance.\n";
    }

    void UseAbility() override {
        std::cout << "RangedState uses a ranged ability.\n";
        std::cout << "RangedState wants to change the state of the hero.\n";
        this->context_->TransitionTo(new MeleeState);
    }
};

void MeleeState::Attack() {
    std::cout << "MeleeState attacks up close.\n";
    std::cout << "MeleeState wants to change the state of the hero.\n";
    this->context_->TransitionTo(new RangedState);
}

#endif // STATE_H
