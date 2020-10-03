#include "iostream"
#include "Tilebag.h"

Tilebag::Tilebag(){
	// Tile* tile = TILE_BLACK;
	// tiles.push_back(tile);
}

Tilebag::~Tilebag(){

}

Tile Tilebag::drawTile(){
	return tiles.at(tiles.size());
}

void Tilebag::addTile(Tile tile){
	tiles.insert(tile*, tiles.size() + 1);
}