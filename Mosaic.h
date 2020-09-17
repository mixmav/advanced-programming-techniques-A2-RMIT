#include "Tiles.h"
#define MOSAIC_DIM 5

class Mosaic {
    public:
        // Constructor/Deconstructor
        Mosaic();
        ~Mosaic();

        // Getters/Setters
        char getStorage(int row, int col);
        char getGrid(int row, int col);
        char getBrokenTile(int i);
        
        void setStorage(Tiles colour, int row, int col);
        void setGrid(Tiles colour, int row, int col);
        void setBrokenTile(Tiles tile, int i);

        // Fill 2D arrays with chars
        void initArrays();

    private:
    char** storage;
    char** grid;
    char* brokenTiles;
};