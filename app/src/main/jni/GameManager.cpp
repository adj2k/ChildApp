#include "GameManager.h"

namespace game
{
    GameManager::GameManager(const size_t& age_range, const size_t& game_type)
    : selected_age_range{ age_range }, selected_game_type{ game_type }, game{ nullptr }
    {}

    void GameManager::start_game()
    {
        if (!selected_game_type)
            game = new NumbersGame{ selected_age_range, selected_game_type};
        else
            game = new LettersGame{ selected_age_range, selected_game_type};
    }

    void GameManager::end_game()
    {
        // Send results to stats handler
        game->results;
        delete game;
        game = NULL;
    }

    void GameManager::set_age_range(const size_t& age_range)
    {
        if (age_range < AGE_RANGE_5_TO_7 || age_range > AGE_RANGE_8_TO_10)
            selected_age_range = AGE_RANGE_5_TO_7;
        else
            selected_age_range = age_range;
    }

    void GameManager::set_game_type(const size_t& game_type)
    {
        if (game_type < NUMBERS_GAME || game_type > LETTERS_GAME)
            selected_game_type = NUMBERS_GAME;
        else
            selected_game_type = game_type;
    }
}