#ifndef UIACTIONHANDLER_HEADER
#define UIACTIONHANDLER_HEADER

class UIActionHandler {
    public :
		// Starts a new game
		void newGame();

		// Loads a game from a save file
		void loadGame(Game* game);

		// Prints the name of the developers
		void printCredits();

		// Exits the game
		void quit();
	
	private:
		UI* ui = new UI();
};
#endif