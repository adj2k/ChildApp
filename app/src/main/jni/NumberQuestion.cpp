#include "NumberQuestion.h"

namespace game
{
    NumberQuestion::NumberQuestion(const size_t &_age_range)
        : Question{ _age_range }
    {
        std::string str_expression = "";
        switch(age_range)
        {
        case AGE_RANGE_5_TO_7:
            str_expression = get_5_to_7_question();
            break;
        case AGE_RANGE_7_to_8:
            str_expression = get_7_to_8_question();
            break;
        case AGE_RANGE_8_TO_10:
            str_expression = get_8_to_10_question();
            break;
        default:
            str_expression = "20+20";
        }
        expression = new Expression{ str_expression };
    }

    std::string NumberQuestion::get_question() const
    {
        return expression->to_string();
    }

    bool NumberQuestion::check_answer(const std::string &answer)
    {
        float correct = expression->get_result();
        Expression answer_exp{ answer };
//        if (answer_exp.check_if_min_fraction())
//            return false;
        float attempt = answer_exp.get_result();
        return (correct/attempt > 0.99 && correct/attempt < 1.01);
    }

    std::string NumberQuestion::get_5_to_7_question() const
    {
        std::srand(time(0));
        std::ostringstream result;
        float operand1 = std::rand() % 101;
        float operand2 = std::rand() % (int)operand1+1;
        char _operator = (std::rand() % 2) ? '+' : '-';
        result << operand1;
        result << _operator;
        result << operand2;
        return result.str();
    }

    std::string NumberQuestion::get_7_to_8_question() const
    {
        std::srand(time(0));
        float operand1;
        float operand2;
        char _operator;
        if (std::rand() % 2) // Addition and Subtraction
        {
            operand1 = std::rand() % 100001;
            operand2 = std::rand() % (int)operand1+1;
            _operator = (std::rand() % 2) ? '+' : '-';
        }
        else
        {
            operand1 = (std::rand() % 10) * (std::rand() % 10 + 1);
            operand2 = std::rand() % 10;
            _operator = (std::rand() % 2) ? '*' : '/';
        }
        std::ostringstream result;

        result << operand1;
        result << _operator;
        result << operand2;
        return result.str();
    }

    std::string NumberQuestion::get_8_to_10_question() const
    {
        float operand1;
        float operand2;
        char _operator;

        if (rand() % 2)
        {
            operand1 = (std::rand() % 1000);
            operand2 = std::rand() % 1000;
            _operator = '*';
        } else
        {
            operand1 = (std::rand() % 1000);
            operand2 = std::rand() % 100;
            _operator = '/';
        }

        std::ostringstream result;

        result << operand1;
        result << _operator;
        result << operand2;
        return result.str();
    }

    bool NumberQuestion::check_if_min_fraction() const
    {
        return expression->check_if_min_fraction();
    }
}