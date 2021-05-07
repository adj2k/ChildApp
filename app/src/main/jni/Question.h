#ifndef MOBILEAPPPROJECT_QUESTION_H
#define MOBILEAPPPROJECT_QUESTION_H

#include <iostream>
#include <vector>

namespace game
{
    class Question
    {
    protected:
        const size_t age_range;
    public:
        Question(const size_t &_age_range);

        virtual std::string get_question() const = 0;
        virtual bool check_answer(const std::string &answer) = 0;
    };
}



#endif //MOBILEAPPPROJECT_QUESTION_H
