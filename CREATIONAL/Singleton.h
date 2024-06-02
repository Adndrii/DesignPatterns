#ifndef SINGLETON_H
#define SINGLETON_H

class GameManager {
public:
    static GameManager& getInstance();
    void showGameStatus();

private:
    GameManager();
    ~GameManager();
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;
};

#endif // SINGLETON_H
