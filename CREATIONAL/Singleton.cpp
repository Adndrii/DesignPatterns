#include "Singleton.h"
#include <iostream>

GameManager& GameManager::getInstance() {
    static GameManager instance;
    return instance;
}

GameManager::GameManager() {}

GameManager::~GameManager() {}

void GameManager::showGameStatus() {
    std::cout << "Game is running" << std::endl;
}
