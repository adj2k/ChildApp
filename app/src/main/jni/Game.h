#ifndef MOBILEAPPPROJECT_GAME_H
#define MOBILEAPPPROJECT_GAME_H

#include <jni.h>
#include <iostream>
#include <sstream>

#include "Result.h"
#include "Constants.h"
#include "Question.h"

namespace game
{
    class Game
    {
    protected:
        const size_t age_range; // The age range that this game will create questions for
        const size_t game_type;

        const size_t numberOfQuestions = 25;

    public:
        Result *results; // This is a object that stores the user's current performance on the game on, given as a parameter on init
        Question* curr_question;

    public:
        // Constructor, takes a age range and a Result* object
        Game(const size_t &_age_range, const size_t &game_type, Question *_curr_question);
        // Starts the game, leading to it asking you questions and keeping track of the amount of questions answered, and correct and incorrect answers
        virtual void start_game() = 0;
        std::string get_game_details() const;
        virtual void next_question(const bool &correct) = 0;
    };
}

#endif //MOBILEAPPPROJECT_GAME_H
