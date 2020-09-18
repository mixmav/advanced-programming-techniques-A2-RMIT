#include "Factory.h"
#include "Types.h"

Factory::Factory(Tile tiles[FACTORY_SIZE])
{
	this->tiles = std::vector<Tile>();
	for (int i = 0; i < FACTORY_SIZE; i++)
		this->tiles.push_back(tiles[i]);
}

Factory::~Factory()
{
    this->tiles.clear();
	delete &this->tiles;
}

std::vector<Tile> Factory::getTiles()
{
	return std::vector<Tile>(this->tiles);
}

std::vector<Tile> Factory::pullTiles(Tile tile, Factory* dump)
{
	std::vector<Tile> output = std::vector<Tile>();
	for (std::vector<Tile>::iterator i = tiles.begin(); i < tiles.end(); i++)
		if (*i == tile || *i == TILE_FIRST_PLAYER)
		{
			output.push_back(*i);
			tiles.erase(i);
		}

	if (output.size() != 0 && dump != nullptr)
		dump->addTiles(tiles.begin(), tiles.end());

	return output;
}

void Factory::addTiles(std::vector<Tile>::iterator tiles_start, std::vector<Tile>::iterator tiles_end)
{
	for (std::vector<Tile>::iterator i = tiles_start; i < tiles_end; i++)
		tiles.push_back(*i);
}