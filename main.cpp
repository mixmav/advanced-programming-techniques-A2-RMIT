#include "iostream"
#include "UI.h"

int main(int argc, char** argv) {
    
    UI* ui = new UI();
    ui->printMenu();

    ui->dispatchMenuAction(ui->getUserIntInput());

    return EXIT_SUCCESS;
}