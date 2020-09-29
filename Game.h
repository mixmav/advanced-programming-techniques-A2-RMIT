#include "LinkedList.h"
#include "Player.h"
#include "Factory.h"
#include "Types.h"
#include <vector>

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


    // Micheal
    
    
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