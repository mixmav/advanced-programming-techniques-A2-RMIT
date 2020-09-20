#include "iostream"
#include "UIActionHandler.h"
#include "Utility.h"
#include "UI.h"

void UIActionHandler::newGame(){
    UI* ui = new UI();
    
    prettyPrint("Starting a New Game", PrettyPrint::BOTH);

    prettyPrintUIPrompt("Enter a name for player 1");
    std::cout << ui->getUserStringInput();
}

void UIActionHandler::loadGame(){
    
    //Load a game from a save file (possibly needs to access console args)

}

void UIActionHandler::printCredits(){
    
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
}

void UIActionHandler::quit(){
    prettyPrint("Goodbye", PrettyPrint::BOTH);
    exit(EXIT_SUCCESS);
}