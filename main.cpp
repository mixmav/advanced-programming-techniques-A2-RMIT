#include "iostream"
#include "UI.h"
#include "Tilebag.h"
#include "Types.h"

int main(int argc, char** argv) {
    
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