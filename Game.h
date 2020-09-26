
#include "LinkedList.h"
#include "Player.h"
#include "Factory.h"
#include "Types.h"
#include <vector>


class Game {
    public:
    // Faraz
    int getNextPlayerIndex();
	bool playRound(int factory, Tile tile, int bag);

	private:
		LinkedList<Player> players;
		LinkedList<Factory> factories;

		int turn;
		int activePlayer;
		int firstPlayer;

    // Manav


    // Micheal
    
    
    private:
    // Faraz


    // Manav


    // Micheal
    
    
};