
#include "LinkedList.h"
#include "Player.h"
#include "Factory.h"
#include "Types.h"
#include <vector>
#include "Mosaic.h"

#define NO_FACTORIES 5


class Game {
    public:
    // Faraz
    int getNextPlayerIndex();
	bool playRound(int factory, Tile tile, int bag);

    // Manav


    // Micheal
    // Returns the current turn.
    int getTurn();
    // Checks each player's Mosaics' storage for the game over condition, being a player having a full row.
    bool isGameOver();
    // Returns the list of factories.
    LinkedList<Factory> getFactories();
    
    private:
    // Faraz
    LinkedList<Player> players;
    LinkedList<Factory> factories;

    int turn;
    int activePlayer;
    int firstPlayer;

    // Manav


    // Micheal
    
};