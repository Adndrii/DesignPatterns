#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>

class Command {
public:
    virtual ~Command() {}
    virtual void Execute() const = 0;
};

class AbilityCommand : public Command {
private:
    std::string ability_;

public:
    explicit AbilityCommand(std::string ability) : ability_(ability) {}

    void Execute() const override {
        std::cout << "Using Ability: " << ability_ << std::endl;
    }
};

class Hero {
public:
    void UseAbility(const std::string& ability) {
        std::cout << "Hero uses ability: " << ability << std::endl;
    }
};

class HeroAbilityCommand : public Command {
private:
    Hero* hero_;
    std::string ability_;

public:
    HeroAbilityCommand(Hero* hero, std::string ability) : hero_(hero), ability_(ability) {}

    void Execute() const override {
        hero_->UseAbility(ability_);
    }
};

class CommandInvoker {
private:
    Command* command_;

public:
    ~CommandInvoker() {
        delete command_;
    }

    void SetCommand(Command* command) {
        command_ = command;
    }

    void ExecuteCommand() const {
        if (command_) {
            command_->Execute();
        }
        else {
            std::cout << "No command set." << std::endl;
        }
    }
};

#endif // COMMAND_H
