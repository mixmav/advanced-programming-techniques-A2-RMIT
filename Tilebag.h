#ifndef TILEBAG_HEADER
#define TILEBAG_HEADER

#include "Types.h"
#include "LinkedList.h"
#include <vector>

class Tilebag {
    public:
        Tilebag();
		~Tilebag();

		// Draws tile from the front of the queue.
		Tile drawTile();

		// Draws a set amount of tiles from the front of the queue.
		Tile* drawTiles(int count);

		// Add tile to the back of the queue.
		void addTile(Tile tile);

		// Returns initialTilesCopy.
		LinkedList<Tile>* getInitailTilebag();

		// Replaces tiles in tilebag when loading game
		void replaceTilebag(LinkedList<Tile>* newTilebag);

	protected:			
		std::vector<Tile>* tiles;
		// Copy of the initial tilebag for save file. (+ idk man looks kinda redundant to me)
		LinkedList<Tile>* initialTilebag;
};


#endif