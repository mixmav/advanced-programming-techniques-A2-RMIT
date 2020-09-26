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
    
    