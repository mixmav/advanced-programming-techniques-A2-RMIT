#include "Game.h"
#include "Mosaic.h"

// Faraz
int* Game::getEndgameScores()
{
	int* scores = new int[players.size()];
	for (int i = 0; i < players.size(); i++)
		scores[i] = getScore(i);
	return scores;
}

int Game::getScore(int player)
{
	Player* p = players.at(player);
	Mosaic* mos = p->getMosaic();
	int score = 0;

	// Calculate bonus: Horizontal fill
	for (int i = 0; i < MOSAIC_DIM; i++)
	{
		bool bonus = true;
		for (int j = 0; j < MOSAIC_DIM; j++)
			bonus &= mos->getStorage(i, j);
		
		if (bonus)
			score += 2;
	}

	// Calculate bonus: Vertical fill
	for (int i = 0; i < MOSAIC_DIM; i++)
	{
		bool bonus = true;
		for (int j = 0; j < MOSAIC_DIM; j++)
			bonus &= mos->getStorage(j, i);
		
		if (bonus)
			score += 7;
	}

	// TODO: bonus for filled colours

	// Calculate bonus: Crosspoints and regular tiles
	for (int y = 0; y < MOSAIC_DIM; y++)
		for (int x = 0; x < MOSAIC_DIM; x++)
			if (mos->getStorage(y, x) != TILE_NONE)
			{
				score++;
				if (((x + 1 < MOSAIC_DIM && mos->getStorage(y, x + 1) != TILE_NONE) ||
					(x - 1 >= 0 && mos->getStorage(y, x - 1) != TILE_NONE)) &&
					((y + 1 < MOSAIC_DIM && mos->getStorage(y + 1, x) != TILE_NONE) ||
					(y - 1 >= 0 && mos->getStorage(y + 1, x) != TILE_NONE)))
					score++;
			}

	// Calculate broken tiles
	score -= mos->getBrokenTile(0) != TILE_NONE ? 0 : 1;
	score -= mos->getBrokenTile(1) != TILE_NONE ? 0 : 1;
	score -= mos->getBrokenTile(2) != TILE_NONE ? 0 : 2;
	score -= mos->getBrokenTile(3) != TILE_NONE ? 0 : 2;
	score -= mos->getBrokenTile(4) != TILE_NONE ? 0 : 2;
	score -= mos->getBrokenTile(5) != TILE_NONE ? 0 : 3;
	score -= mos->getBrokenTile(6) != TILE_NONE ? 0 : 3;
}

int Game::getNextPlayerIndex()
{
	return (activePlayer + players.size() - firstPlayer) % players.size();
}

int Game::findFirstPlayerIndex()
{
	int index = 0;
	for (LinkedList<Player>::Iterator p = players.begin(); p.hasNext(); p.next())
	{
		// TODO: THIS NEEDS TO CHANGE
		for (int i = 0; i < BROKEN_TILES_SIZE; i++)
			if (p.get()->getMosaic()->getBrokenTile(i) == TILE_FIRST_PLAYER)
				return index;
		index++;
	}
	return 0;
}

bool Game::playRound(int factory, Tile tile, int row)
{
	Factory* f = factories.at(factory);
	Player* player = players.at(activePlayer);
	Mosaic* mos = player->getMosaic();

	// Try getting all the similar tiles from the factory, if none exist, the play is incorrect.
	std::vector<Tile> tiles = f->pullTiles(tile, factories.at(0));
	if (tiles.size() == 0)
		return false;
	
	// The tiles can only be fitted in a row with empty slots, no different tiles on the pattern, and no same tiles on the wall.
	if (mos->getGrid(row, 0) != TILE_NONE && mos->getGrid(row, 0) != tile && mos->getGrid(row, row) != TILE_NONE)
		return false;

	if (tiles.back() == TILE_FIRST_PLAYER)
	{
		mos->addBrokenTile((Tile)TILE_FIRST_PLAYER);
		tiles.pop_back();
	}

	// Move to the first empty slot in the row, keep adding tiles, when out of space, add to broken tiles.
	int offset = 0;
	for (offset = 0; mos->getGrid(row, offset) != TILE_NONE; offset++) ;
	for (int i = 0; i < tiles.size(); i++)
	{
		if (i + offset < MOSAIC_DIM)
			mos->setGrid(tile, row, i + offset);
		else
			mos->addBrokenTile(tile);
	}

	// Move to the next player if the round is still active. Reaching the first player means we proceed to the next round.
	int nextPlayer = getNextPlayerIndex();
	if (nextPlayer == firstPlayer)
	{
		nextPlayer = firstPlayer = findFirstPlayerIndex();
		turn++;
	}
	activePlayer = nextPlayer;
	return true;
}
// Manav


// Micheal
    
    