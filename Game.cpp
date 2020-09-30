#include "Game.h"

// Faraz
bool Game::playRound(int factory, Tile tile, int bag)
{
	Factory* f = factories.at(factory);
	Player* player = players.at(activePlayer);

	std::vector<Tile> tiles = f->pullTiles(tile, factories.at(0));
	if (tiles.size() == 0)
		return false;
	
	// TODO: play

	activePlayer = getNextPlayerIndex();
	return true;
	//int activeIndex = (activePlayer + players.size() - firstPlayer) % players.size(); (getNextPlayer)
}

// Manav


// Micheal
int Game::getTurn() {
    return turn;
}

LinkedList<Factory> Game::getFactories() {
    return factories;
}

bool Game::isGameOver() {
    for(int i = 0; i < 2; ++i) {
        Player* player = players.at(activePlayer);
        Mosaic* mosaic = player->getMosaic();
        for(int row = 0; row < MOSAIC_DIM; ++row) {
            Tile tile = mosaic->getPattern(row, 0);
            for(int col = 0; col < MOSAIC_DIM; ++col) {
                if(mosaic->getPattern(row, col) != tile) {
                   col = MOSAIC_DIM; 
                }
                if(col == MOSAIC_DIM - 1) {
                    return true;
                }
            }
        }
    }
    return false;
}