#ifndef MOSAIC_HEADER
#define MOSAIC_HEADER

#include "Types.h"
#include <vector>

class Mosaic {
    public:
        // Constructor/Deconstructor
        Mosaic();
        ~Mosaic();

        // Deep Copy Constructor
        Mosaic(const Mosaic& other);

        // Getters/Setters
        Tile getPattern(int row, int col);
        Tile getWall(int row, int col);
        Tile getBrokenTile(int i);
		int getBrokenTileCount();
        
        void setPattern(Tile colour, int row, int col);
        void setWall(Tile colour, int row, int col);
        void setBrokenTile(Tile tile, int i);

        // Add new broken tile to next slot
        void addBrokenTile(Tile tile);

        // Remove specified broken tile
        void removeBrokenTile(Tile tile);

		// Remove broken tile at said index
		void removeBrokenTile(int index);

    private:
        // Allocate memory for 1D arrays
        Tile** pattern = new Tile*[MOSAIC_DIM];
        Tile** wall  = new Tile*[MOSAIC_DIM];
        std::vector<Tile> brokenTiles;

        // Allocate memory for 2D arrays
        void allocMem();

        // Fill 2D arrays with chars
        void initArrays();
};

#endif