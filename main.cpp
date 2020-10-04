#include "iostream"
#include "LinkedList.h"
#include "UI.h"
#include "Tilebag.h"
#include "Types.h"
#include "Game.h"

int main(int argc, char** argv) {
    // Used to store turns made by players.
    // LinkedList<std::string>* turns = new LinkedList<std::string>();
    std::vector<std::string> names = {"A", "B"};
    Game* game = new Game(names);
    
    for(int i = 0; i < argc; ++i) {
        std::string s;
        s = argv[i];
        if(s.compare("-t") == 0) {
            game->testingMode(argv[i + 1]);
        }
    }

    UI* ui = new UI();
    ui->printMenu();
    
    while (true){
        // Check if  a valid selection was made

        if(ui->dispatchMenuAction(ui->getUserIntInput(), game)){
            break;
        }

        // If not, ask for an input again
    }

    return EXIT_SUCCESS;
}