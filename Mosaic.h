#include "Types.h"
#define MOSAIC_DIM 5

class Mosaic {
    public:
        // Constructor/Deconstructor
        Mosaic();
        ~Mosaic();

        char getStorage(int row, int col);
        char getGrid(int row, int col);
        char getBrokenTile(int i);
        
        void setStorage(Tile colour, int row, int col);
        void setGrid(Tile colour, int row, int col);
        void setBrokenTile(Tile tile, int i);

        // Fill 2D arrays with chars
        void initArrays();

    private:
    char** storage;
    char** grid;
    char* brokenTiles;
};