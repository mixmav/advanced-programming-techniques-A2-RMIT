#include "Mosaic.h"
#include <vector>

Mosaic::Mosaic() {
    allocMem();
    initArrays();
	brokenTiles = std::vector<Tile>();
}

Mosaic::~Mosaic() {
    for(int row = 0; row < MOSAIC_DIM; ++row) {
        delete[] pattern[row];
        delete[] wall[row];
    }
    delete[] pattern;
    delete[] wall;
    brokenTiles.clear();
	delete &brokenTiles;
    pattern = nullptr;
    wall = nullptr;
}

Mosaic::Mosaic(const Mosaic& other) {
    allocMem();
    for(int row = 0; row < MOSAIC_DIM; ++row) {
        for(int col = 0; col < MOSAIC_DIM; ++col) {
            pattern[row][col] = Tile(other.pattern[row][col]);
            wall[row][col] = Tile(other.wall[row][col]);
        }
    }
    
	brokenTiles = std::vector<Tile>(other.brokenTiles);
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

int Mosaic::getBrokenTileCount() {
	return brokenTiles.size();
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
    brokenTiles.push_back(tile);
}

void Mosaic::removeBrokenTile(int index) {
    brokenTiles.erase(brokenTiles.begin() + index);
}

void Mosaic::removeBrokenTile(Tile tile) {
    for (std::vector<Tile>::iterator i = brokenTiles.begin(); i < brokenTiles.end(); i++)
		if (*i == tile)
			brokenTiles.erase(i);
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