#include "Expression.h"

Expression::Expression(const std::string &str_expression)
        : infix_expression{ str_expression }
{
    if (str_expression == ""){
        expression.emplace_back(new Operand{ -1 });
        return;
    }
    for (int index = 0; index < infix_expression.length();)
        if (infix_expression.at(index) == ' ')
            infix_expression.erase(infix_expression.begin() + index);
        else
            ++index;

    const char* text = infix_expression.c_str();
    size_t size = strlen(text) + 1;
    char text_copy[size];
    memcpy(text_copy, text, sizeof(char) * size);
    char *tok = NULL;
    bool first = 1;
    while (1)
    {
        if (first)
        {
            tok = strtok(text_copy, DELIMITERS);
            first = false;
        }
        else
        {
            tok = strtok(NULL, DELIMITERS);
        }

        if (!tok)
            break;

        char temp = text[tok - text_copy + strlen(tok)];
        if (temp != '\0')
        {
            if (temp == '*' || temp == '/')
                expression.emplace_back(new Operator{ temp });
            else
                expression.emplace(expression.begin(), new Operator{ temp });
        }

        expression.emplace_back(new Operand{ (float)atof(tok) });
    }
}

float Expression::get_result()
{
    char order_of_operations[] = "*/+-";

    for (size_t order = 0; order < sizeof(order_of_operations); ++order)
    {
        for (int index = expression.size() - 1; index >= 0 && expression.size() >= 3; --index)
        {
            if (expression.at(index)->to_string()[0] == order_of_operations[order])
            {
                Operator* _operator = static_cast<Operator*>(expression.at(index));
                Operand* operand1 = static_cast<Operand*>(expression.at(index+1));
                Operand* operand2 = static_cast<Operand*>(expression.at(index+2));

                float result = _operator->run_operation(*operand1, *operand2);

                delete _operator;
                delete operand1;
                delete operand2;

                auto it = expression.erase(expression.begin() + index);
                expression.erase(expression.begin() + index);
                expression.erase(expression.begin() + index);

                expression.emplace(it, new Operand{ result });
            }
        }
    }

    Operand* result = static_cast<Operand*>(expression[0]);
    return result->get_value();
}

std::string Expression::to_string() const
{
    std::ostringstream result;
    for (const auto &it : infix_expression)
        result << it << ' ';
    return result.str();
}

std::string Expression::to_string_prefix_notation() const
{
    std::ostringstream result;
    for (auto &it : expression)
        result << it->to_string() << ' ';
    return result.str();
}

bool Expression::check_if_min_fraction() const
{
    size_t count = 0;
    for (const auto &it : expression)
    {
        if (it->to_string()[0] == '/')
        {
            float o1 = atof(expression.at(count+1)->to_string().c_str());
            float o2 = atof(expression.at(count+2)->to_string().c_str());

            size_t arr_size = ((o1 > o2) ? (int)o1 : (int)o2) + 1;

            bool o1Multiples[arr_size];
            bool o2Multiples[arr_size];

            for (size_t index = 1; index < arr_size; ++index)
            {
                o1Multiples[index] = (int)o1 % index == 0;
                o2Multiples[index] = (int)o2 % index == 0;
            }

            size_t max;
            for (size_t index = arr_size-1; index >= 1; ++index)
            {
                if (o1Multiples[index] && o2Multiples[index])
                {
                    max = index;
                }
            }
            return max == 1;
        }
        ++count;
    }
}