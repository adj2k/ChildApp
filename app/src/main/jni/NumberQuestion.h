#ifndef MOBILEAPPPROJECT_NUMBERQUESTION_H
#define MOBILEAPPPROJECT_NUMBERQUESTION_H

#include "Question.h"
#include "Expression.h"
#include "Constants.h"

namespace game
{
    class NumberQuestion : public Question
    {
    private:
        Expression* expression;

    public:
        NumberQuestion(const size_t& _age_range);
        std::string get_question() const;
        bool check_answer(const std::string &answer);
        std::string get_5_to_7_question() const;
        std::string get_7_to_8_question() const;
        std::string get_8_to_10_question() const;
        bool check_if_min_fraction() const;
    };
}

#endif //MOBILEAPPPROJECT_NUMBERQUESTION_H
