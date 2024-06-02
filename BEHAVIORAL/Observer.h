#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <list>
#include <string>

class IObserver {
public:
    virtual ~IObserver() {}
    virtual void Update(const std::string& message_from_subject) = 0;
};

class ISubject {
public:
    virtual ~ISubject() {}
    virtual void Attach(IObserver* observer) = 0;
    virtual void Detach(IObserver* observer) = 0;
    virtual void Notify() = 0;
};

class Game : public ISubject {
public:
    virtual ~Game() {
        std::cout << "The game has ended.\n";
    }

    void Attach(IObserver* observer) override {
        players_.push_back(observer);
    }

    void Detach(IObserver* observer) override {
        players_.remove(observer);
    }

    void Notify() override {
        for (auto* player : players_) {
            player->Update(message_);
        }
    }

    void CreateMessage(const std::string& message = "Empty") {
        this->message_ = message;
        Notify();
    }

    void ShowPlayerCount() const {
        std::cout << "There are " << players_.size() << " players in the game.\n";
    }

private:
    std::list<IObserver*> players_;
    std::string message_;
};

class Player : public IObserver {
public:
    Player(Game& game) : game_(game) {
        this->game_.Attach(this);
        std::cout << "Player " << ++Player::player_count_ << " has joined the game.\n";
        this->player_number_ = Player::player_count_;
    }

    virtual ~Player() {
        std::cout << "Player " << this->player_number_ << " has left the game.\n";
    }

    void Update(const std::string& message_from_game) override {
        message_from_game_ = message_from_game;
        ShowMessage();
    }

    void LeaveGame() {
        game_.Detach(this);
        std::cout << "Player " << player_number_ << " has left the game.\n";
    }

    void ShowMessage() const {
        std::cout << "Player " << this->player_number_ << " received message: " << this->message_from_game_ << "\n";
    }

private:
    std::string message_from_game_;
    Game& game_;
    static int player_count_;
    int player_number_;
};

int Player::player_count_ = 0;

#endif // OBSERVER_H
