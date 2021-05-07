#ifndef MOBILEAPPPROJECT_LETTERSGAME_H
#define MOBILEAPPPROJECT_LETTERSGAME_H

#include "Game.h"
#include "LetterQuestion.h"

namespace game
{
    class LettersGame : public Game
    {
    public:
        // Constructor, takes a age range and a Result* object
        LettersGame(const size_t _age_range, const size_t &_game_type);
        // Starts the game, leading to it asking you questions and keeping track of the amount of questions answered, and correct and incorrect answers
        void start_game();
        void next_question(const bool &correct);
    };
}




#endif //MOBILEAPPPROJECT_LETTERSGAME_H
