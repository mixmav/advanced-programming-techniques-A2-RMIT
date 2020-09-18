#include "Types.h"
#define MOSAIC_DIM 5
#define BROKEN_TILES_SIZE 7

class Mosaic {
    public:
        // Constructor/Deconstructor
        Mosaic();
        ~Mosaic();

        // Getters/Setters
        char getStorage(int row, int col);
        char getGrid(int row, int col);
        char getBrokenTile(int i);
        
        void setStorage(Tile colour, int row, int col);
        void setGrid(Tile colour, int row, int col);
        void setBrokenTile(Tile tile, int i);

        // Fill 2D arrays with chars
        void initArrays();

        // Add new broken tile to next slot
        void addBrokenTile(Tile tile);

        // Remove specified broken tile
        void removeBrokenTile(Tile tile);

    private:
        char** storage;
        char** grid;
        char* brokenTiles;
};