// Everything below this, is going to be defined only 1 time
#ifndef TILEBAG_HEADER
#define TILEBAG_HEADER

#include "Types.h"
#include "LinkedList.h"

class Tilebag {
    public :
        Tilebag();
		~Tilebag();


		// Draws tile from the front  of the queue
		Tile drawTile();

		// Add tile to the back of the queue
		void addTile(Tile tile);


		protected:			
			LinkedList<Tile> tiles;
};


#endif