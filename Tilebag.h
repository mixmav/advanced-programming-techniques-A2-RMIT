
// Everything below this, is going to be defined only 1 time
#ifndef TILEBAG_HEADER
#define TILEBAG_HEADER

#include "Types.h"

class Tilebag {
    public :
        Tilebag();
		~Tilebag();


		// Draws tile from the front  of the queue
		void drawTile(Tile tile);

		// Add tile to the back of the queue
		void addTile(Tile tile);


		protected:

};


#endif