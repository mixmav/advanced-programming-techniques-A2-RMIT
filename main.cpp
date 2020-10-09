#include "iostream"
#include "LinkedList.h"
#include "UI.h"
#include "Tilebag.h"
#include "Types.h"
#include "Game.h"

int main(int argc, char** argv) {
    // Used to store turns made by players.
    
	Game* game = nullptr;
	bool isTesting = false;
    for (int i = 0; i < argc; ++i) 
	{
        std::string s;
        s = argv[i];
        if(s.compare("-t") == 0) 
		{
			isTesting = true;
			game = new Game({ "A", "B" });
            game->testingMode(argv[i + 1]);
        }
    }

    UI* ui = new UI();
    ui->printMenu();
    
	if (!isTesting)
	{
		// Get the Game object from UI handler based on user choice.
		while (!(game = ui->dispatchMenuAction(ui->getUserIntInput()))) ;
	}

	while (!game->isGameOver())
	{	
		PlayHandResult hand = ui->promptPlayerHand(game, false);
		while (game->playHand(hand.factory, hand.tile, hand.row))
			hand = ui->promptPlayerHand(game, true);

		if (game->concludeRound())
			ui->displayRoundScores(game);
	}

    return EXIT_SUCCESS;
}