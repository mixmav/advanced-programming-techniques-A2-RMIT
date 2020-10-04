#include <string>

class Mosaic;

class Player {
    public:
        // Constructor/Deconstructor
        Player(std::string name);
        ~Player();

        // Deep Copy Constructor
        Player(const Player& other);

        // Move Constructor
        Player(const Player&& other);

        // Getters/Setters
        std::string getName();
        Mosaic* getMosaic();
		int getScore();

        void setName(std::string name);
        void setMosaic(Mosaic* mosaic);
		void addScore(int score);

        // Prints out the stored data on selected players mosaic
        void displayMosaic();

    private:
        std::string name;
        Mosaic* mosaic;
		int score;
};