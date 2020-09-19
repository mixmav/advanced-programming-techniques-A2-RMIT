#include "iostream"

#include "UI.h"
#include "Utility.h"

void UI::printMenu(){
    prettyPrint("Welcome to Azul!", PrettyPrint::UNDERLINE);
    prettyPrint("Menu", PrettyPrint::UNDERLINE);

    const std::vector<std::string> menuOptions = { "New Game", "Load Game", "Credits", "Quit" };

    prettyPrintList(menuOptions);
}