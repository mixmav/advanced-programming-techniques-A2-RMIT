class UI {
    public :
        //Print the main menu
        void printMenu();

        //Gets the user input as an integer and returns it to whatever's calling it
        int getUserIntInput();

        //Dispatches the corresponding menu action based on the input
        //Returns false if an invalid selection was made
        bool dispatchMenuAction(int input);
};