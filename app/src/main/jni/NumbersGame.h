#ifndef MOBILEAPPPROJECT_NUMBERSGAME_H
#define MOBILEAPPPROJECT_NUMBERSGAME_H

#include "Game.h"
#include "NumberQuestion.h"

namespace game
{
    class NumbersGame : public Game
    {
    public:
        // Constructor, takes a age range and a Result* object
        NumbersGame(const size_t _age_range, const size_t _game_type);
        // Starts the game, leading to it asking you questions and keeping track of the amount of questions answered, and correct and incorrect answers
        void start_game();
        void next_question(const bool &correct);
    };
}


#endif //MOBILEAPPPROJECT_NUMBERSGAME_H