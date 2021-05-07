#include "Game.h"

namespace game
{
    Game::Game(const size_t& _age_range, const size_t& _game_type, Question *_curr_question)
    : age_range{ _age_range }, game_type{ _game_type }, results{ new Result{} }, curr_question{ _curr_question } {}

    std::string Game::get_game_details() const
    {
        std::ostringstream oss;
        oss << "Age Range: ";
        switch (age_range)
        {
        case AGE_RANGE_5_TO_7:
            oss << "5-7";
            break;
        case AGE_RANGE_7_to_8:
            oss << "7-8";
            break;
        case AGE_RANGE_8_TO_10:
            oss << "8-10";
            break;
        }
        oss << ", Game Type: ";
        switch (game_type)
        {
        case NUMBERS_GAME:
            oss << "Numbers";
            break;
        case LETTERS_GAME:
            oss << "Letters";
            break;
        }

        return oss.str();
    }
}