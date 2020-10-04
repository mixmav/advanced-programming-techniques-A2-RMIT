#ifndef GAME_HEADER
#define GAME_HEADER

#include "LinkedList.h"
#include "Player.h"
#include "Factory.h"
#include "Types.h"
#include "Tilebag.h"
#include "Mosaic.h"
#include <iostream>
#include <fstream>
#include "Tilebag.h"

#include <vector>
#include <string>

#define NO_FACTORIES 5

class Game {

    public:
    // Faraz

		// Creates an instance of Game with given player names. Factories are based on player count.
		Game(std::vector<std::string> players);
		~Game();

		// Gets the index of the next player whose turn is to play.
		int getNextPlayerIndex();

		// Searches all players for a FIRST_PLAYER tile which will determine the first player next round.
		int findFirstPlayerIndex();

		// Applies endgame score bonuses for all players.
		void applyEndgameBonuses();

		// Gets the score of a single player.
		//int getScore(int player);

		// With given factory to draw from, tile to draw from the factory, and the row to put the tiles in,
		// determines whether or not the hand is playable, and if so then commits the play and proceeds to the next player.
		bool playHand(int factory, Tile tile, int row);

		// Determines whether it's the end of round, if not, it will return false,
		// if true, it will apply patterns into the wall, calculate end-of-round scores and return residue to the bag.
		bool concludeRound();
		
    // Manav
		
		//Get the active player and return the corresponding player object
		Player getActivePlayer();

		//Get the next player and return the corresponding player object
		Player getNextPlayer();


    // Micheal
		
		// Returns the current turn.
		int getRound();

		// Checks each player's Mosaics' storage for the game over condition, being a player having a full row.
		bool isGameOver();

		// Returns the list of factories.
    	Factory** getFactories();

		// Returns the list of players.
		Player** getPlayers();
    
		// Saves Player names, initial Tile bag and turns to file.
		void saveGame(std::string fileName, LinkedList<std::string> turns);

		// Read file and 'replay game'
		void loadGame(std::string fileName);

		// Testing Mode.
		void testingMode(std::string fileName);

    private:
    // Faraz

		// Gets the score that a single tile wields when it's added to the wall.
		int getScoreForTile(Mosaic* mosaic, int row, int col);

    	LinkedList<Player>* players;
		LinkedList<Factory>* factories;
		int round;
		int activePlayer;
		int firstPlayer;

    // Manav

		Tilebag* tilebag;

    // Micheal
    
};

#endif
