class UI {
    public :
        //Print the main menu
        void printMenu();

        //Gets the user input as an integer and returns it to whatever's calling it
        int getUserIntInput();

        //Gets the user input as a string and returns it to whatever's calling it
        std::string getUserStringInput();

        //Dispatches the corresponding menu action based on the input
        //Returns false if an invalid selection was made
        bool dispatchMenuAction(int input);
};