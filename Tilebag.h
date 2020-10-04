#ifndef TILEBAG_HEADER
#define TILEBAG_HEADER

#include "Types.h"
#include "LinkedList.h"

class Tilebag {
    public :
        Tilebag();
		~Tilebag();

		// Draws tile from the front of the queue.
		Tile drawTile();

		// Draws a set amount of tiles from the front of the queue.
		Tile* drawTiles(int count);

		// Add tile to the back of the queue.
		void addTile(Tile tile);

	protected:			
		LinkedList<Tile>* tiles;
};


#endif