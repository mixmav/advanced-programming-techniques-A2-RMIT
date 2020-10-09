#ifndef TYPES_HEADER
#define TYPES_HEADER

#define MOSAIC_DIM 5
#define BROKEN_TILES_SIZE 7

// Enum list of available tiles
enum Tile {
    TILE_RED = 'R',
    TILE_YELLOW = 'Y',
    TILE_DARK_BLUE = 'B',
    TILE_LIGHT_BLUE = 'L',
    TILE_BLACK = 'U',
    TILE_FIRST_PLAYER = 'F',
    TILE_NONE = '.',
    TILE_SPACE = ' ',
    TILE_NULL = '\0'
};

// Enum list of available formatting options for Utility function PrettyPrint
struct PrettyPrint {
    enum Value {
        UNDERLINE = 'U',
        OVERLINE = 'O',
        BOTH = 'B',
        NONE = 'N'
    };
};

// Default tile setup for a regular Azul game.
// Remember it's [y][x]!
const Tile DEFAULT_TILES[5][5] =
{
	{ TILE_DARK_BLUE, TILE_YELLOW, TILE_RED, TILE_BLACK, TILE_LIGHT_BLUE, },
	{ TILE_LIGHT_BLUE, TILE_DARK_BLUE, TILE_YELLOW, TILE_RED, TILE_BLACK, },
	{ TILE_BLACK, TILE_LIGHT_BLUE, TILE_DARK_BLUE, TILE_YELLOW, TILE_RED, },
	{ TILE_RED, TILE_BLACK, TILE_LIGHT_BLUE, TILE_DARK_BLUE, TILE_YELLOW, },
	{ TILE_YELLOW, TILE_RED, TILE_BLACK, TILE_LIGHT_BLUE, TILE_DARK_BLUE, }, // splendid, uhm...
};

struct PlayHandResult
{
	int factory;
	Tile tile;
	int row;
};

#endif