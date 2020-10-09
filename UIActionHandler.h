#ifndef UIACTIONHANDLER_HEADER
#define UIACTIONHANDLER_HEADER

#include "UI.h"
#include "Game.h"

class UIActionHandler {
    public :
		~UIActionHandler();

		// Starts a new game
		Game* newGame();

		// Loads a game from a save file
		Game* loadGame();

		// Prints the name of the developers
		void printCredits();

		// Exits the game
		void quit();
	
	private:
		UI* ui = new UI();
};
#endif