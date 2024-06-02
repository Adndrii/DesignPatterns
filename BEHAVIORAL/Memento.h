#ifndef MEMENTO_H
#define MEMENTO_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <sstream>

class Memento {
public:
    virtual ~Memento() {}
    virtual std::string GetName() const = 0;
    virtual std::string date() const = 0;
    virtual std::string state() const = 0;
};

class ConcreteHeroState : public Memento {
private:
    std::string state_;
    std::string date_;

public:
    ConcreteHeroState(std::string state) : state_(state) {
        std::time_t now = std::time(0);
        char buf[26];
        ctime_s(buf, sizeof(buf), &now);
        this->date_ = buf;
    }

    std::string state() const override {
        return this->state_;
    }

    std::string GetName() const override {
        return this->date_ + " / (" + this->state_.substr(0, 9) + "...)";
    }

    std::string date() const override {
        return this->date_;
    }
};

class Hero {
private:
    std::string state_;

    std::string GenerateRandomString(int length = 10) {
        const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        int stringLength = sizeof(alphanum) - 1;

        std::string random_string;
        for (int i = 0; i < length; i++) {
            random_string += alphanum[std::rand() % stringLength];
        }
        return random_string;
    }

public:
    Hero(std::string state) : state_(state) {
        std::cout << "Hero: My initial state is: " << this->state_ << "\n";
    }

    void UseAbility() {
        std::cout << "Hero: Using an ability.\n";
        this->state_ = this->GenerateRandomString(30);
        std::cout << "Hero: and my state has changed to: " << this->state_ << "\n";
    }

    Memento* Save() {
        return new ConcreteHeroState(this->state_);
    }

    void Restore(Memento* memento) {
        this->state_ = memento->state();
        std::cout << "Hero: My state has changed to: " << this->state_ << "\n";
    }
};

class Caretaker {
private:
    std::vector<Memento*> mementos_;
    Hero* hero_;

public:
    Caretaker(Hero* hero) : hero_(hero) {}

    ~Caretaker() {
        for (auto m : mementos_) delete m;
    }

    void Backup() {
        std::cout << "\nCaretaker: Saving Hero's state...\n";
        this->mementos_.push_back(this->hero_->Save());
    }

    void Undo() {
        if (!this->mementos_.size()) {
            return;
        }
        Memento* memento = this->mementos_.back();
        this->mementos_.pop_back();
        std::cout << "Caretaker: Restoring state to: " << memento->GetName() << "\n";
        this->hero_->Restore(memento);
    }

    void ShowHistory() const {
        std::cout << "Caretaker: Here's the list of mementos:\n";
        for (Memento* memento : this->mementos_) {
            std::cout << memento->GetName() << "\n";
        }
    }
};

#endif // MEMENTO_H
