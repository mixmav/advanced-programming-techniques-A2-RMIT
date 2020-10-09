#include <iostream>

#include "Types.h"
#include "UI.h"
#include "UIActionHandler.h"
#include "Utility.h"



void UI::printMenu()
{
    
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


int UI::getUserIntInput()
{
    UIActionHandler* uiActionHandler = new UIActionHandler();

    int input;
	bool valid = false;

    while (!valid)
	{
		valid = true;

		std::cout << "> ";
		std::cin >> input;

		if (std::cin.eof())
		{
            uiActionHandler->quit(); //Quit
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

std::string UI::getUserStringInput()
{
    UIActionHandler* uiActionHandler = new UIActionHandler();

    std::string input;
    bool valid = false;

    while (!valid)
	{
        valid = true;

        std::getline(std::cin >> std::ws, input);
        
        if (!std::cin) 
		{
            if(std::cin.eof()) 
			{
                uiActionHandler->quit(); //Quit game
            } 
			else 
			{
                valid = false; //Try again
            }
        }
    }
    std::cout << std::endl;
    return input;
}

Game* UI::dispatchMenuAction(int input)
{
    UIActionHandler* uiActionHandler = new UIActionHandler();

	switch (input)
	{
        case 1: { 
            //New Game

			return uiActionHandler->newGame();
        };
        case 2: {
            //Load Game

            return uiActionHandler->loadGame();
        };
        case 3: {
            //Credits

			uiActionHandler->printCredits();
            return nullptr;
        };
        case 4: {
            //Quit

			uiActionHandler->quit();
            return nullptr;
        };

        default: {
            // Invalid selection, return false
			prettyPrint("Invalid selection, let's try again!", PrettyPrint::BOTH);
            return nullptr;
        }
	}
}

PlayHandResult UI::promptPlayerHand(Game* game, bool retry)
{
	UIActionHandler* uiActionHandler = new UIActionHandler();

	Player p = game->getActivePlayer();
	if (retry)
	{
		prettyPrint("Invalid play, let's try again!", PrettyPrint::BOTH);
	}
	else
	{
		LinkedList<Factory> factories = game->getFactories();
		int i = 0;
		for (LinkedList<Factory>::Iterator n = factories.begin(); n.hasNext(); n.next())
		{
			if (i == 0)
				std::cout << "Centre: ";
			else
				std::cout << i << ": ";
			
			std::vector<Tile> tiles = n.get()->getTiles();
			for (int j = 0; j < tiles.size(); j++)
				std::cout << (char)tiles.at(j) << " ";
			std::cout << std::endl;

			i++;
		}
			
		p.displayMosaic();
	}
	
	std::cout << p.getName() << "> ";
	//std::string cmd = "";
	PlayHandResult result = PlayHandResult();
	char tempTile;
	std::cin >> result.factory >> tempTile >> result.row;
	if (std::cin.eof())
		uiActionHandler->quit();

	result.tile = (Tile)tempTile;

	return result;
}

void UI::displayRoundScores(Game* game)
{
	prettyPrint("Round " + std::to_string(game->getRound()) + " ends.", PrettyPrint::BOTH);
	for (LinkedList<Player>::Iterator i = game->getPlayers().begin(); i.hasNext(); i.next())
		prettyPrint(i.get()->getName() + ": " + std::to_string(i.get()->getScore()), i.hasNext() ? PrettyPrint::NONE : PrettyPrint::UNDERLINE);
}