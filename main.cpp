#include "iostream"
#include "UI.h"

int main(int argc, char** argv) {
    
    UI* ui = new UI();
    ui->printMenu();
    
    while (true){
        // Check if  a valid selection was made

        if(ui->dispatchMenuAction(ui->getUserIntInput())){
            break;
        }

        // If not, ask for an input again
    }

    return EXIT_SUCCESS;
}