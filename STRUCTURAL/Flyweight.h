#ifndef FLYWEIGHT_H
#define FLYWEIGHT_H

#include <iostream>
#include <string>
#include <unordered_map>

struct SharedState {
    std::string type_;
    std::string role_;

    SharedState(const std::string& type, const std::string& role)
        : type_(type), role_(role) {}

    friend std::ostream& operator<<(std::ostream& os, const SharedState& ss) {
        return os << "[ Type: " << ss.type_ << ", Role: " << ss.role_ << " ]";
    }
};

struct UniqueState {
    std::string name_;
    std::string attribute_;

    UniqueState(const std::string& name, const std::string& attribute)
        : name_(name), attribute_(attribute) {}

    friend std::ostream& operator<<(std::ostream& os, const UniqueState& us) {
        return os << "[ Name: " << us.name_ << ", Attribute: " << us.attribute_ << " ]";
    }
};

class Flyweight {
private:
    SharedState* shared_state_;

public:
    Flyweight(const SharedState* shared_state) : shared_state_(new SharedState(*shared_state)) {}
    Flyweight(const Flyweight& other) : shared_state_(new SharedState(*other.shared_state_)) {}
    ~Flyweight() { delete shared_state_; }

    SharedState* shared_state() const { return shared_state_; }

    void Operation(const UniqueState& unique_state) const {
        std::cout << "Flyweight: Displaying shared " << *shared_state_ << " and unique " << unique_state << " state.\n";
    }
};

class FlyweightFactory {
private:
    std::unordered_map<std::string, Flyweight> flyweights_;

    std::string GetKey(const SharedState& ss) const {
        return ss.type_ + "_" + ss.role_;
    }

public:
    FlyweightFactory(std::initializer_list<SharedState> share_states) {
        for (const SharedState& ss : share_states) {
            flyweights_.insert(std::make_pair(GetKey(ss), Flyweight(&ss)));
        }
    }

    Flyweight GetFlyweight(const SharedState& shared_state) {
        std::string key = GetKey(shared_state);
        if (flyweights_.find(key) == flyweights_.end()) {
            std::cout << "FlyweightFactory: Creating new flyweight.\n";
            flyweights_.insert(std::make_pair(key, Flyweight(&shared_state)));
        }
        else {
            std::cout << "FlyweightFactory: Reusing existing flyweight.\n";
        }
        return flyweights_.at(key);
    }

    void ListFlyweights() const {
        size_t count = flyweights_.size();
        std::cout << "\nFlyweightFactory: Total number of flyweights: " << count << std::endl;
        for (const auto& pair : flyweights_) {
            std::cout << pair.first << std::endl;
        }
    }
};

#endif // FLYWEIGHT_H
