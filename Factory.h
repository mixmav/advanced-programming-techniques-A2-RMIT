#ifndef FACTORY_HEADER
#define FACTORY_HEADER

#include "Types.h"
#include <vector>

#define FACTORY_SIZE 4

class Factory 
{
	public:
	// Creates an instance of Factory with given tiles.
	Factory();
    Factory(Tile tiles[FACTORY_SIZE]); 
	~Factory();
        
	// Pull all tiles of specified type from the factory and put the remaining into the dump.
	// If nullptr specified, keeps the remaining tiles.
	// If F (First Player) tile is present, picks it up as well.	
    std::vector<Tile> pullTiles(Tile tile, Factory* dump);

    // Gets all the tiles this factory posesses.
	std::vector<Tile> getTiles();

	// Adds all tiles within range into this factory.
	void addTiles(std::vector<Tile>::iterator tiles_start, std::vector<Tile>::iterator tiles_end);

	// Adds all tiles within range into this factory.
	void addTiles(Tile* tiles_start, int _size);
    
    private:
    	std::vector<Tile> tiles;
};

#endif