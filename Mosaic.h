#include "Types.h"
#define MOSAIC_DIM 5
#define BROKEN_TILES_SIZE 7

class Mosaic {
    public:
        // Constructor/Deconstructor
        Mosaic();
        ~Mosaic();

        // Deep Copy Constructor
        Mosaic(const Mosaic& other);

        // Getters/Setters
        char getStorage(int row, int col);
        char getGrid(int row, int col);
        char getBrokenTile(int i);
        
        void setStorage(Tile colour, int row, int col);
        void setGrid(Tile colour, int row, int col);
        void setBrokenTile(Tile tile, int i);

        // Add new broken tile to next slot
        void addBrokenTile(Tile tile);

        // Remove specified broken tile
        void removeBrokenTile(Tile tile);

        // Allocate memory for 2D arrays
        void allocMem();

        // Fill 2D arrays with chars
        void initArrays();

    private:
        // Allocate memory for 1D arrays
        char** storage = new char*[MOSAIC_DIM];
        char** grid  = new char*[MOSAIC_DIM];
        char* brokenTiles  = new char[BROKEN_TILES_SIZE];
};