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