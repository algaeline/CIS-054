#ifndef PLAYER_H
#define PLAYER_H

class Player {
    protected:
        int guess;
            
    public:
        // == Friends ==
        void play(Player &player1, Player &player2);   
        // == Constructor(s) ==
        Player();

        // == Predefined Functions ==
        bool checkForWin(int guess, int answer);

        // == Virtual Functions ==
        virtual int get_guess();
};

class HumanPlayer : public Player {
    public:
        HumanPlayer(): Player() {};
        virtual int get_guess(); // Overrides Player::get_guess()
};

class ComputerPlayer : public Player {
    public:
        ComputerPlayer(): Player() {};
        virtual int get_guess(); // Overrides Player::get_guess()
};

#endif