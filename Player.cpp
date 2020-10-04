#include <iostream>
#include "Player.h"
#include "Mosaic.h"
#include "Types.h"

Player::Player(std::string name) {
    this->name = name;
    mosaic = new Mosaic();
	score = 0;
}

Player::~Player() {
    delete mosaic;
    mosaic = nullptr;
}

Player::Player(const Player& other) :
    name(other.name), score(other.score)
{
    mosaic = new Mosaic(*other.mosaic);
}

std::string Player::getName() {
    return this->name;
}

Mosaic* Player::getMosaic() {
    return this->mosaic;
}

void Player::setName(std::string name) {
    this->name = name;
}

void Player::setMosaic(Mosaic* mosaic) {
    this->mosaic = mosaic;
}

void Player::displayMosaic() {
    std::cout << "Mosaic for " << this->name << ": " << std::endl; 
    for(int row = 0; row < MOSAIC_DIM; ++row) {
        std::cout << row + 1 << ": ";
        for(int col = 0; col < MOSAIC_DIM; ++col) {
            std::cout << char(mosaic->getPattern(row, col)) << " ";
        }
        std::cout << "|| ";
        for(int col = 0; col < MOSAIC_DIM; ++col) {
            std::cout << char(mosaic->getWall(row, col)) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "broken: ";
    for(int i = 0; i < BROKEN_TILES_SIZE; ++i) {
        std::cout << char(mosaic->getBrokenTile(i)) << " ";
    }
    std::cout << std::endl;
}

int Player::getScore()
{
	return score;
}

void Player::addScore(int score)
{
	this->score += score;
}