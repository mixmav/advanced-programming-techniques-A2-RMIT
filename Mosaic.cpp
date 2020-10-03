#include "Mosaic.h"

Mosaic::Mosaic() {
    allocMem();
    initArrays();
}

Mosaic::~Mosaic() {
    for(int row = 0; row < MOSAIC_DIM; ++row) {
        delete[] pattern[row];
        delete[] wall[row];
    }
    delete[] pattern;
    delete[] wall;
    delete[] brokenTiles;
    pattern = nullptr;
    wall = nullptr;
    brokenTiles = nullptr;
}

Mosaic::Mosaic(const Mosaic& other) {
    allocMem();
    for(int row = 0; row < MOSAIC_DIM; ++row) {
        for(int col = 0; col < MOSAIC_DIM; ++col) {
            pattern[row][col] = Tile(other.pattern[row][col]);
            wall[row][col] = Tile(other.wall[row][col]);
        }
    }
    for(int i = 0; i < BROKEN_TILES_SIZE; ++i) {
        brokenTiles[i] = Tile(other.brokenTiles[i]);
    }
}

Tile Mosaic::getPattern(int row, int col) {
    return pattern[row][col];
}

Tile Mosaic::getWall(int row, int col) {
    return wall[row][col];
}

Tile Mosaic::getBrokenTile(int i) {
    return brokenTiles[i];
}

void Mosaic::setPattern(Tile colour, int row, int col) {
    pattern[row][col] = colour;
}

void Mosaic::setWall(Tile colour, int row, int col) {
    wall[row][col] = colour;
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
            brokenTiles[i] = TILE_NULL;
            for(int j = i; j < BROKEN_TILES_SIZE; ++j) {
                brokenTiles[j] = brokenTiles[j + 1];
            }
            i = BROKEN_TILES_SIZE;
        }
    }
}

void Mosaic::allocMem() {
    for(int i = 0; i < MOSAIC_DIM; ++i) {
        this->pattern[i] = new Tile[MOSAIC_DIM];
        this->wall[i] = new Tile[MOSAIC_DIM];
    }
}

void Mosaic::initArrays() {
    for(int row = 0; row < MOSAIC_DIM; ++row) {
        for(int col = 0; col < MOSAIC_DIM; ++col) {
            if(MOSAIC_DIM - col <= row + 1) {
                this->pattern[row][col] = TILE_NONE;
            } else {
                this->pattern[row][col] = TILE_SPACE;
            }
        }
    }
    for(int row = 0; row < MOSAIC_DIM; ++row) {
        for(int col = 0; col < MOSAIC_DIM; ++col) {
            this->wall[row][col] = TILE_NONE;
        }
    }
}