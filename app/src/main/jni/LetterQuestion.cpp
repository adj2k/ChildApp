#include "LetterQuestion.h"

namespace game
{
    LetterQuestion::LetterQuestion(const size_t &_age_range)
        : Question{ _age_range }
    {

    }

    std::string LetterQuestion::get_question() const
    {
        return "";
    }

    bool LetterQuestion::check_answer(const std::string &answer)
    {
        return true;
    }
}