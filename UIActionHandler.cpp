#include "iostream"
#include "UIActionHandler.h"
#include "Utility.h"
#include "UI.h"
#include "Game.h"

UIActionHandler::~UIActionHandler()
{
    this->ui = nullptr;
}

Game* UIActionHandler::newGame()
{
    std::vector<std::string> playerNames = std::vector<std::string>();

    prettyPrint("Starting a New Game", PrettyPrint::BOTH);

    prettyPrintUIPrompt("Enter a name for player 1");
    playerNames.push_back(ui->getUserStringInput());

    prettyPrintUIPrompt("Enter a name for player 2");
    playerNames.push_back(ui->getUserStringInput());

	return new Game(playerNames);
}

Game* UIActionHandler::loadGame()
{
    prettyPrintUIPrompt("Enter the filename from which load a game");
    std::string fileName = ui->getUserStringInput();
	Game* game = new Game({ "A", "B" });
    game->loadGame(fileName);
	return game;
}

void UIActionHandler::printCredits()
{
    
    prettyPrint("This game was designed and developed by these awesome people", PrettyPrint::BOTH);

    prettyPrint("Name: Faraz Akbari", PrettyPrint::OVERLINE);
    prettyPrint("Student ID: S3754395");
    prettyPrint("Email: s3754395@student.rmit.edu.au", PrettyPrint::UNDERLINE);

    prettyPrint("Name: Micheal Trinh", PrettyPrint::OVERLINE);
    prettyPrint("Student ID: S3780212");
    prettyPrint("Email: s3780212@student.rmit.edu.au", PrettyPrint::UNDERLINE);

    prettyPrint("Name: Manav Gadhoke", PrettyPrint::OVERLINE);
    prettyPrint("Student ID: S3783375");
    prettyPrint("Email: s3783375@student.rmit.edu.au", PrettyPrint::UNDERLINE);

	ui->printMenu();
}

void UIActionHandler::quit()
{
    prettyPrint("Goodbye", PrettyPrint::BOTH);
    exit(EXIT_SUCCESS);
}