#ifndef CHAINOFRESPONSIBILITY_H
#define CHAINOFRESPONSIBILITY_H

#include <iostream>
#include <vector>

class Handler {
public:
    virtual Handler* SetNext(Handler* handler) = 0;
    virtual std::string Handle(std::string request) = 0;
};

class AbstractHandler : public Handler {
private:
    Handler* next_handler_;

public:
    AbstractHandler() : next_handler_(nullptr) {}

    Handler* SetNext(Handler* handler) override {
        this->next_handler_ = handler;
        return handler;
    }

    std::string Handle(std::string request) override {
        if (this->next_handler_) {
            return this->next_handler_->Handle(request);
        }
        return {};
    }
};

class HeroHandler : public AbstractHandler {
public:
    std::string Handle(std::string request) override {
        if (request == "Mana") {
            return "Hero: I'll use " + request + ".\n";
        }
        else {
            return AbstractHandler::Handle(request);
        }
    }
};

class TowerHandler : public AbstractHandler {
public:
    std::string Handle(std::string request) override {
        if (request == "Attack") {
            return "Tower: I'll " + request + " the enemy.\n";
        }
        else {
            return AbstractHandler::Handle(request);
        }
    }
};

class CreepHandler : public AbstractHandler {
public:
    std::string Handle(std::string request) override {
        if (request == "Gold") {
            return "Creep: I'll give " + request + " to the player.\n";
        }
        else {
            return AbstractHandler::Handle(request);
        }
    }
};

#endif // CHAINOFRESPONSIBILITY_H
