class Mosaic;

class Player {
    public:
        // Constructor/Deconstructor
        Player(std::string name);
        ~Player();

        // Getters/Setters
        std::string getName();
        Mosaic* getMosaic();

        void setName(std::string name);
        void setMosaic(Mosaic* mosaic);

        // Prints out the stored data on selected players mosaic
        void displayMosaic();

    private:
        std::string name;
        Mosaic* mosaic;
};