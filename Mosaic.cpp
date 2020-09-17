#include "Mosaic.h"

Mosaic::Mosaic() {
    // Allocate memory for 1D arrays
    int brokenTilesSize = 7;
    this->storage = new char*[MOSAIC_DIM];
    this->grid = new char*[MOSAIC_DIM];
    this->brokenTiles = new char[brokenTilesSize];
    // Allocate memory for 2D arrays
    for(int i = 0; i < MOSAIC_DIM; ++i) {
        this->storage[i] = new char[MOSAIC_DIM];
        this->grid[i] = new char[MOSAIC_DIM];
    }
    initArrays();
}

Mosaic::~Mosaic() {
    for(int row = 0; row < MOSAIC_DIM; ++row) {
        delete[] storage[row];
        delete[] grid[row];
    }
    delete[] storage;
    delete[] grid;
    delete[] brokenTiles;
    storage = nullptr;
    grid = nullptr;
    brokenTiles = nullptr;
}

char Mosaic::getStorage(int row, int col) {
    return storage[row][col];
}

char Mosaic::getGrid(int row, int col) {
    return grid[row][col];
}

char Mosaic::getBrokenTile(int i) {
    return brokenTiles[i];
}

void Mosaic::setStorage(Tile colour, int row, int col) {
    storage[row][col] = colour;
}

void Mosaic::setGrid(Tile colour, int row, int col) {
    grid[row][col] = colour;
}

void Mosaic::setBrokenTile(Tile tile, int i) {
    brokenTiles[i] = tile;
}

void Mosaic::initArrays() {
    for(int row = 0; row < MOSAIC_DIM; ++row) {
        for(int col = 0; col < MOSAIC_DIM; ++col) {
            if(MOSAIC_DIM - col <= row + 1) {
                this->storage[row][col] = NO_TILE;
            } else {
                this->storage[row][col] = ' ';
            }
        }
    }
    for(int row = 0; row < MOSAIC_DIM; ++row) {
        for(int col = 0; col < MOSAIC_DIM; ++col) {
            this->grid[row][col] = NO_TILE;
        }
    }
}