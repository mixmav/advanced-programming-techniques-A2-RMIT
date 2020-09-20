#include "iostream"

#include "UI.h"
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

void UI::dispatchMenuAction(int input){
	switch (input)
	{

	case 1: { 
        //New Game
		
		std::cout << "New Game";
		break;
    };
	case 2: {
        //Load Game

		std::cout << "Load Game";
		break;
    };
    case 3: {
        //Credits

		std::cout << "Credits";
		break;
    };
    case 4: {
        //Quit

		std::cout << "Quit";
		break;
    };

	default:
		std::cout << "Something else";
		break;
	}
}