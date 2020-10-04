#include "LinkedList.h"
#include "Player.h"
#include "Factory.h"
#include "Types.h"
#include <vector>
#include "Mosaic.h"
#include <iostream>
#include <fstream>
#include "Tilebag.h"

#define NO_FACTORIES 5


class Game {

    // Faraz
    public:
		// Gets the index of the next player whose turn is to play.
		int getNextPlayerIndex();

		// Searches all players for a FIRST_PLAYER tile which will determine the first player next round.
		int findFirstPlayerIndex();

		// Gets endgame scores for all players by order as of in getPlayers().
		int *getEndgameScores();

		// Gets the score of a single player.
		int getScore(int player);

		// With given factory to draw from, tile to draw from the factory, and the row to put the tiles in,
		// determines whether or not the round is playable, and if so then commits the play and proceeds to the next player.
		bool playRound(int factory, Tile tile, int row);
		
    // Manav
	//Get the active player and return the corresponding player object
	Player getActivePlayer();

	//Get the next player and return the corresponding player object
	Player getNextPlayer();


    // Micheal
    // Returns the current turn.
    int getTurn();

    // Checks each player's Mosaics' storage for the game over condition, being a player having a full row.
    bool isGameOver();
    
    // Returns the list of factories.
    LinkedList<Factory> getFactories();

    // Saves Player names, initial Tile bag and turns to file.
    void saveGame(std::string fileName, LinkedList<std::string> turns);

    // Read file and 'replay game'
    void loadGame();

    // Testing Mode.
    void testingMode();

    private:
    // Faraz
    LinkedList<Player> players;
		LinkedList<Factory> factories;

		int turn;
		int activePlayer;
		int firstPlayer;

    // Manav


    // Micheal
    Tilebag* tilebag;
};