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
			bonus &= mos->getPattern(i, j);
		
		if (bonus)
			score += 2;
	}

	// Calculate bonus: Vertical fill
	for (int i = 0; i < MOSAIC_DIM; i++)
	{
		bool bonus = true;
		for (int j = 0; j < MOSAIC_DIM; j++)
			bonus &= mos->getPattern(j, i);
		
		if (bonus)
			score += 7;
	}

	// TODO: bonus for filled colours

	// Calculate bonus: Crosspoints and regular tiles
	for (int y = 0; y < MOSAIC_DIM; y++)
		for (int x = 0; x < MOSAIC_DIM; x++)
			if (mos->getPattern(y, x) != TILE_NONE)
			{
				score++;
				if (((x + 1 < MOSAIC_DIM && mos->getPattern(y, x + 1) != TILE_NONE) ||
					(x - 1 >= 0 && mos->getPattern(y, x - 1) != TILE_NONE)) &&
					((y + 1 < MOSAIC_DIM && mos->getPattern(y + 1, x) != TILE_NONE) ||
					(y - 1 >= 0 && mos->getPattern(y + 1, x) != TILE_NONE)))
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
	if (mos->getWall(row, 0) != TILE_NONE && mos->getWall(row, 0) != tile && mos->getWall(row, row) != TILE_NONE)
		return false;

	if (tiles.back() == TILE_FIRST_PLAYER)
	{
		mos->addBrokenTile((Tile)TILE_FIRST_PLAYER);
		tiles.pop_back();
	}

	// Move to the first empty slot in the row, keep adding tiles, when out of space, add to broken tiles.
	int offset = 0;
	for (offset = 0; mos->getWall(row, offset) != TILE_NONE; offset++) ;
	for (int i = 0; i < tiles.size(); i++)
	{
		if (i + offset < MOSAIC_DIM)
			mos->setWall(tile, row, i + offset);
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
int Game::getTurn() {
    return turn;
}

LinkedList<Factory> Game::getFactories() {
    return factories;
}

bool Game::isGameOver() {
	// iterates through players.
    for(int i = 0; i < 2; ++i) {
        Player* player = players.at(activePlayer);
        Mosaic* mosaic = player->getMosaic();
		// iterates through each row for the current player's mosaic.
        for(int row = 0; row < MOSAIC_DIM; ++row) {
            Tile tile = mosaic->getPattern(row, 0);
			// Checks if entire row is full.
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

void Game::saveGame(std::string fileName, LinkedList<std::string> turns) {
    std::ofstream file;
    file.open(fileName);
	LinkedList<Tile>* initialTilebag = tilebag->getInitailTilebag();
    // Writes initial tilebag.
	file << "<";
	for(int i = 0; i < initialTilebag->size() - 1; ++i) {
		file << initialTilebag->at(i);
		if(i < initialTilebag->size() - 1) {
			file << ", ";
		}
	}
	file << ">";
	// Writes player names.
    for(int i = 0; i < 2; ++i) {
        Player* player = players.at(i);
        file << player->getName() << std::endl;
    }
	// Writes all turns made.
	for(int i = 0; i < turns.size() - 1; ++i) {
		file << turns.at(i);
		if(i < turns.size() - 1) {
			file << std::endl;
		}
	}
    file.close();
	std::cout << "Game successfully saved to '" << fileName << "'" << std::endl;
}

void Game::loadGame() {
	std::string string;
	LinkedList<Tile>* newTilebag = new LinkedList<Tile>();
    std::vector<char> tiles;
    std::vector<std::vector<std::string>> turns;
	// Loops through save file as input.
    while(std::cin >> string) {
        if(string.compare(0, 4, "turn") != 0) {
			// Removes front '<' character.
            if(string.compare(0, 1, "<") == 0) {
                string.erase(0, 1);
            }
			// Removes ',' and '>' at end.
            string.pop_back();
            tiles.push_back(*string.c_str());    
        } else {
            std::vector<std::string> turn;
            std::string string;
			// Loops through the 3 args.
            for(int i = 0; i < 3; ++i) {
                std::cin >> string;
                turn.push_back(string);
            }
            turns.push_back(turn);
        }
    }
	// Converts chars to Tiles.
	int i = 0;
    for(char tile : tiles) {
		Tile* t = new Tile(static_cast<Tile>(tile));
		newTilebag->insert(t, i);
		++i;
    }
	tilebag->replaceTilebag(newTilebag);
	// Execute saved turns.
	for(std::vector<std::string> turn : turns) {
		playRound(std::stoi(turn[0]), static_cast<Tile>(*turn[1].c_str()), std::stoi(turn[2]));
	}
}

void Game::testingMode() {
	loadGame();
	// Lists the factories and Tiles within.
	std::cout << "Factories:" << std::endl;
	for(int factNum = 0; factNum <= NO_FACTORIES; ++factNum) {
		Factory* factory = factories.at(factNum);
		std::cout << factNum << ": ";
		std::vector<Tile> tiles = factory->getTiles();
		for(Tile tile : tiles) {
			std::cout << tile << " ";
		}
		std::cout << std::endl;
	}
	// Displays each player's score and mosaics.
	for(int i = 0; i < 2; ++i) {
		Player* player = players.at(i);
		std::cout << "Score for Player " << player->getName() << ": " << getScore(i) << std::endl;
		player->displayMosaic();
	}
}