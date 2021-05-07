#include "NumbersGame.h"

namespace game
{
    NumbersGame::NumbersGame(const size_t _age_range, const size_t _game_type)
        : Game{ _age_range, _game_type, new NumberQuestion{ _age_range } } {}

    void NumbersGame::start_game()
    {
        // Needs implementation

    }

    void NumbersGame::next_question(const bool &correct)
    {
        delete curr_question;
        curr_question = new NumberQuestion{age_range};
        if (correct)
            results->increment_correct_questions();
        else
            results->increment_incorrect_questions();
    }
}