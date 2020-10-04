#include "iostream"
#include "LinkedList.h"
#include "UI.h"
#include "Tilebag.h"
#include "Types.h"
#include "Game.h"

int main(int argc, char** argv) {
    // Used to store turns made by players.
    LinkedList<std::string>* turns = new LinkedList<std::string>();
    Game* game = new Game();
    
    for(int i = 0; i < argc; ++i) {
        std::string s;
        s = argv[i];
        if(s.compare("-t") == 0) {
            game->testingMode(argv[i + 1]);
        }
    }

	Tilebag* tilebag = new Tilebag();
	tilebag->drawTile(TILE_BLACK);
    // UI* ui = new UI();
    // ui->printMenu();
    
    // while (true){
    //     // Check if  a valid selection was made

    //     if(ui->dispatchMenuAction(ui->getUserIntInput())){
    //         break;
    //     }

    //     // If not, ask for an input again
    // }

    return EXIT_SUCCESS;
}