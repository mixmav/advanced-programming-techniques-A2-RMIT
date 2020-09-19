#include "Mosaic.h"

Mosaic::Mosaic() {
    allocMem();
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

Mosaic::Mosaic(const Mosaic& other) {
    allocMem();
    for(int row = 0; row < MOSAIC_DIM; ++row) {
        for(int col = 0; col < MOSAIC_DIM; ++col) {
            storage[row][col] = char(other.storage[row][col]);
            grid[row][col] = char(other.grid[row][col]);
        }
    }
    for(int i = 0; i < BROKEN_TILES_SIZE; ++i) {
        brokenTiles[i] = char(other.brokenTiles[i]);
    }
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

void Mosaic::addBrokenTile(Tile tile) {
    for(int i = 0; i < BROKEN_TILES_SIZE; ++i) {
        if(brokenTiles[i] == '\0') {
            brokenTiles[i] = tile;
        }
    }
}

void Mosaic::removeBrokenTile(Tile tile) {
    for(int i = 0; i < BROKEN_TILES_SIZE; ++i) {
        if(brokenTiles[i] == tile) {
            brokenTiles[i] = '\0';
            for(int j = i; j < BROKEN_TILES_SIZE; ++j) {
                brokenTiles[j] = brokenTiles[j + 1];
            }
            i = BROKEN_TILES_SIZE;
        }
    }
}

void Mosaic::allocMem() {
    for(int i = 0; i < MOSAIC_DIM; ++i) {
        this->storage[i] = new char[MOSAIC_DIM];
        this->grid[i] = new char[MOSAIC_DIM];
    }
}

void Mosaic::initArrays() {
    for(int row = 0; row < MOSAIC_DIM; ++row) {
        for(int col = 0; col < MOSAIC_DIM; ++col) {
            if(MOSAIC_DIM - col <= row + 1) {
                this->storage[row][col] = TILE_NONE;
            } else {
                this->storage[row][col] = ' ';
            }
        }
    }
    for(int row = 0; row < MOSAIC_DIM; ++row) {
        for(int col = 0; col < MOSAIC_DIM; ++col) {
            this->grid[row][col] = TILE_NONE;
        }
    }
}