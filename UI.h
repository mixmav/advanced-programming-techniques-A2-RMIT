#ifndef UI_HEADER
#define UI_HEADER
#include "Game.h"
#include "Types.h"
class UI {
    public :
        //Print the main menu
        void printMenu();

        //Gets the user input as an integer and returns it to whatever's calling it
        int getUserIntInput();

        //Gets the user input as a string and returns it to whatever's calling it
        std::string getUserStringInput();

        //Dispatches the corresponding menu action based on the input
        //Returns false if an invalid selection was made
        Game* dispatchMenuAction(int input);

		
		PlayHandResult promptPlayerHand(Game* game, bool retry);

		void displayRoundScores(Game* game);
};

#endif