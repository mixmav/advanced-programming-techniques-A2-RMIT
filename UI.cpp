#include "iostream"

#include "UI.h"
#include "UIActionHandler.h"
#include "Utility.h"

void UI::printMenu(){
    
    prettyPrint("Welcome to Azul!", PrettyPrint::UNDERLINE);
    prettyPrint("Menu", PrettyPrint::UNDERLINE);

    const std::vector<std::string> menuOptions = {
        "New Game",
        "Load Game",
        "Credits",
        "Quit"
    };

    prettyPrintList(menuOptions);
}


int UI::getUserIntInput(){
    int input;
	bool valid = false;

    while (!valid)
	{
		valid = true;

		std::cout << "> ";
		std::cin >> input;

		if (std::cin.eof())
		{
			return 4; //Quit
		}
		

		if(std::cin.fail())
		{
            // IO error
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Please enter a number!" << std::endl;

			valid = false; //try again
		}
	}

    return input;
}

bool UI::dispatchMenuAction(int input){
    UIActionHandler* uiActionHandler = new UIActionHandler();

	switch (input)
	{
        case 1: { 
            //New Game
            
			uiActionHandler->newGame();
            
			return true;
        };
        case 2: {
            //Load Game

			uiActionHandler->loadGame();

            return true;
        };
        case 3: {
            //Credits

			uiActionHandler->printCredits();

            return true;
        };
        case 4: {
            //Quit

			uiActionHandler->quit();

            return true;
        };

        default: {
            // Invalid selection, return false
			prettyPrint("Invalid selection, let's try again!", PrettyPrint::BOTH);
            return false;
        }
	}
}