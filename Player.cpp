#include <iostream>
#include "Player.h"
#include "Mosaic.h"

Player::Player(std::string name) {
    this->name = name;
    mosaic = new Mosaic();
}

Player::~Player() {
    delete mosaic;
    mosaic = nullptr;
}

std::string Player::getName() {
    return this->name;
}

Mosaic Player::getMosaic() {
    return *this->mosaic;
}

void Player::setName(std::string name) {
    this->name = name;
}

void Player::setMosaic(Mosaic mosaic) {
    *this->mosaic = mosaic;
}

void Player::displayMosaic() {
    int brokenTilesSize = 7;
    std::cout << "Mosaic for " << this->name << ": " << std::endl; 
    for(int row = 0; row < MOSAIC_DIM; ++row) {
        std::cout << row + 1 << ": ";
        for(int col = 0; col < MOSAIC_DIM; ++col) {
            std::cout << mosaic->getStorage(row, col) << " ";
        }
        std::cout << "|| ";
        for(int col = 0; col < MOSAIC_DIM; ++col) {
            std::cout << mosaic->getGrid(row, col) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "broken: ";
    for(int i = 0; i < brokenTilesSize; ++i) {
        std::cout << mosaic->getBrokenTile(i) << " ";
    }
    std::cout << std::endl;
}