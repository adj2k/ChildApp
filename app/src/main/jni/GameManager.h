#ifndef MOBILEAPPPROJECT_GAMEMANAGER_H
#define MOBILEAPPPROJECT_GAMEMANAGER_H

#include <iostream>

#include "Result.h"
#include "NumbersGame.h"
#include "LettersGame.h"
#include "Constants.h"

namespace game
{
    class GameManager
    {
    private:
        size_t selected_age_range; // The current age range selected by the user, defaults to the lowest age range
        size_t selected_game_type; // The current game type selected by the user, defaults to the numbers game type
    public:
        Game* game;
    public:
        // Constructor that takes in an age range and a game type
        GameManager(const size_t& age_range = AGE_RANGE_5_TO_7, const size_t& game_type = NUMBERS_GAME);
        // Starts the game by creating a NumbersGame or LettersGame objects, using the selecte age range as a parameter and gives it a Result object to keep track of the user's performance
        void start_game();
        // Ends the current game and sends the results to the Stats classes
        void end_game();
        // Sets the selected age range to the one selected by the user
        void set_age_range(const size_t& age_range);
        // Displats the game types available on the screen
        void set_game_type(const size_t& game_type);
    };
}

#endif //MOBILEAPPPROJECT_GAMEMANAGER_H