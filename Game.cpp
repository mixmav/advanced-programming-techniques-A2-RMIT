#include "Game.h"
#include "Mosaic.h"
#include <string>
#include <vector>

// Faraz
void Game::applyEndgameBonuses()
{
	for (LinkedList<Player>::Iterator i = players->begin(); i.hasNext(); i.next())
	{
		Player* p = i.get();
		Mosaic* m = p->getMosaic();
		int score = 0;

		// Calculate bonus: Horizontal fill
		for (int i = 0; i < MOSAIC_DIM; i++)
		{
			bool bonus = true;
			for (int j = 0; j < MOSAIC_DIM; j++)
				bonus &= m->getWall(i, j) != TILE_NONE;
			
			if (bonus)
				score += 2;
		}

		// Calculate bonus: Vertical fill
		for (int i = 0; i < MOSAIC_DIM; i++)
		{
			bool bonus = true;
			for (int j = 0; j < MOSAIC_DIM; j++)
				bonus &= m->getWall(j, i) != TILE_NONE;
			
			if (bonus)
				score += 7;
		}

		for (int i = 0; i < MOSAIC_DIM; i++)
		{
			bool bonus = true;
			for (int j = 0; j < MOSAIC_DIM; j++)
				bonus &= m->getWall(j, (i + j) % MOSAIC_DIM) != TILE_NONE;

			if (bonus)
				score += 10;
		}
	}
}

/*int Game::getScore(int player)
{
	Player* p = players.at(player);
	Mosaic* mos = p->getMosaic();
	int score = 0;

	// Calculate bonus: Horizontal fill
	for (int i = 0; i < MOSAIC_DIM; i++)
	{
		bool bonus = true;
		for (int j = 0; j < MOSAIC_DIM; j++)
			bonus &= mos->getWall(i, j);
		
		if (bonus)
			score += 2;
	}

	// Calculate bonus: Vertical fill
	for (int i = 0; i < MOSAIC_DIM; i++)
	{
		bool bonus = true;
		for (int j = 0; j < MOSAIC_DIM; j++)
			bonus &= mos->getWall(j, i);
		
		if (bonus)
			score += 7;
	}

	// TODO: bonus for filled colours
}*/

Game::Game(std::vector<std::string> players)
{
	int factoryCount;
	switch (players.size())
	{
		case 2:
			factoryCount = 6;
			break;
		case 3:
			factoryCount = 8;
			break;
		case 4:
			factoryCount = 10;
			break;
		default:
			throw 0;
	}

	this->players = new LinkedList<Player>();
	for (int i = 0; i < players.size(); i++)
		this->players->push_back(new Player(players.at(i)));

	this->tilebag = new Tilebag();
	this->factories = new LinkedList<Factory>();
	this->factories->push_back(new Factory());
	for (int i = 1; i < factoryCount; i++)
		this->factories->push_back(new Factory(tilebag->drawTiles(4)));
}

Game::~Game()
{
	delete factories;
	delete players;
	delete tilebag;
}

int Game::getNextPlayerIndex()
{
	return (activePlayer + players->size() - firstPlayer) % players->size();
}

int Game::findFirstPlayerIndex()
{
	int index = 0;
	for (LinkedList<Player>::Iterator p = players->begin(); p.hasNext(); p.next())
	{
		// TODO: THIS NEEDS TO CHANGE
		for (int i = 0; i < BROKEN_TILES_SIZE; i++)
			if (p.get()->getMosaic()->getBrokenTile(i) == TILE_FIRST_PLAYER)
				return index;
		index++;
	}
	return 0;
}

int Game::getScoreForTile(Mosaic* mosaic, int row, int col)
{
	int scoreX = 0, scoreY = 0;
	for (int x = col; x < MOSAIC_DIM && mosaic->getWall(row, x) != TILE_NONE; x++)
		scoreX++;
	for (int x = col - 1; x >= 0 && mosaic->getWall(row, x) != TILE_NONE; x--)
		scoreX++;
	for (int y = row; y < MOSAIC_DIM && mosaic->getWall(y, col) != TILE_NONE; y++)
		scoreY++;
	for (int y = col - 1; y >= 0 && mosaic->getWall(y, col) != TILE_NONE; y--)
		scoreY++;

	if (scoreX == 1 || scoreY == 1)
		return scoreX + scoreY - 1;
	else
		return scoreX + scoreY;
}

bool Game::concludeRound()
{
	// Check for end-of-round: when all factories are dry
	for (LinkedList<Factory>::Iterator i = factories->begin(); i.hasNext(); i.next())
		if (i.get()->getTiles().size())
			return false;

	// Commit patterns to walls and calculate positive scores
	for (LinkedList<Player>::Iterator i = players->begin(); i.hasNext(); i.next())
	{
		Player* p = i.get();
		Mosaic* m = p->getMosaic();
		for (int y = 0; y < MOSAIC_DIM; y++)
		{
			Tile t = m->getPattern(y, 0);
			if (t != TILE_NONE)
			{
				int x = 0;
				for (; x < MOSAIC_DIM && DEFAULT_TILES[y][x] != t; x++) ;
				m->setWall(t, y , x);
				m->setPattern(TILE_NONE, y, 0);
				p->addScore(getScoreForTile(m, y, x));

				for (int j = 1; j < MOSAIC_DIM && m->getPattern(y, j) != TILE_NONE; j++)
				{
					tilebag->addTile(m->getPattern(y, j));
					m->setPattern(TILE_NONE, y, j);
				}
			}
		}

		int broken = 0;
		broken -= m->getBrokenTile(0) != TILE_NONE ? 0 : 1;
		broken -= m->getBrokenTile(1) != TILE_NONE ? 0 : 1;
		broken -= m->getBrokenTile(2) != TILE_NONE ? 0 : 2;
		broken -= m->getBrokenTile(3) != TILE_NONE ? 0 : 2;
		broken -= m->getBrokenTile(4) != TILE_NONE ? 0 : 2;
		broken -= m->getBrokenTile(5) != TILE_NONE ? 0 : 3;
		broken -= m->getBrokenTile(6) != TILE_NONE ? 0 : 3;
		p->addScore(broken);
	}

	if (activePlayer == firstPlayer)
	{
		activePlayer = firstPlayer = findFirstPlayerIndex();
		round++;
	}
}

bool Game::playHand(int factory, Tile tile, int row)
{
	Factory* f = factories->at(factory);
	Player* player = players->at(activePlayer);
	Mosaic* mos = player->getMosaic();

	// Try getting all the similar tiles from the factory, if none exist, the play is incorrect.
	std::vector<Tile> tiles = f->pullTiles(tile, factories->at(0));
	if (tiles.size() == 0)
		return false;
	
	// The tiles can only be fitted in a row with empty slots, no different tiles on the pattern, and no same tiles on the wall.
	if (mos->getPattern(row, 0) != TILE_NONE && mos->getPattern(row, 0) != tile && mos->getPattern(row, row) != TILE_NONE)
		return false;

	if (tiles.back() == TILE_FIRST_PLAYER)
	{
		mos->addBrokenTile((Tile)TILE_FIRST_PLAYER);
		tiles.pop_back();
	}

	// Move to the first empty slot in the row, keep adding tiles, when out of space, add to broken tiles.
	int offset = 0;
	for (offset = 0; mos->getPattern(row, offset) != TILE_NONE; offset++) ;
	for (int i = 0; i < tiles.size(); i++)
	{
		if (i + offset < MOSAIC_DIM)
			mos->setPattern(tile, row, i + offset);
		else
			mos->addBrokenTile(tile);
	}

	// Move to the next player.
	activePlayer = getNextPlayerIndex();
	return true;
}


// Manav

Player Game::getActivePlayer(){
	return activePlayer;
}

Player Game::getNextPlayer(){
	return players.at(getNextPlayerIndex());
}

// Micheal
int Game::getRound() {
    return round;
}

Factory** Game::getFactories() {
    return factories->toArray();
}

bool Game::isGameOver() {
	// iterates through players.
    for(int i = 0; i < 2; ++i) {
        Player* player = players->at(activePlayer);
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

void Game::loadGame(std::string fileName) {
	std::string string;
	LinkedList<Tile>* newTilebag = new LinkedList<Tile>();
    std::vector<char> tiles;
    std::vector<std::vector<std::string>> turns;
	std::ifstream file(fileName);
	if(file.is_open()) {
		// Loops through save file as input.
		while(file >> string) {
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
					file >> string;
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
		std::cout << "Azul game successfully loaded" << std::endl;
	} else {
		std::cout << "No file by the name: " << fileName << std::endl;
	}
}

void Game::testingMode(std::string fileName) {
	loadGame(fileName);
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