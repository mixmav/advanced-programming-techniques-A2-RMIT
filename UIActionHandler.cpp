#include "iostream"
#include "UIActionHandler.h"
#include "Utility.h"

void UIActionHandler::newGame(){

    //Start a new game

}

void UIActionHandler::loadGame(){
    
    //Load a game from a save file (possibly needs to access console args)

}

void UIActionHandler::printCredits(){
    
    //Print creds

}

void UIActionHandler::quit(){
    prettyPrint("Goodbye", PrettyPrint::BOTH);
    exit(EXIT_SUCCESS);
}