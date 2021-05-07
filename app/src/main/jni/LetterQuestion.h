#ifndef MOBILEAPPPROJECT_LETTERQUESTION_H
#define MOBILEAPPPROJECT_LETTERQUESTION_H

#include "Question.h"

namespace game
{
    class LetterQuestion : public Question
    {
        LetterQuestion(const size_t &_age_range);
        std::string get_question() const;
        bool check_answer(const std::string &answer);
    };
}

#endif //MOBILEAPPPROJECT_LETTERQUESTION_H
