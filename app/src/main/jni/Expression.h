#ifndef MOBILEAPPPROJECT_EXPRESSION_H
#define MOBILEAPPPROJECT_EXPRESSION_H

#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>

#include "Operand.h"
#include "Operator.h"

class Expression
{
private:
    std::vector<ExpressionElement*> expression;
    std::string infix_expression;

    const char* DELIMITERS = "+-*/";

public:
    Expression(const std::string &str_expression);
    float get_result();
    std::string to_string() const;
    std::string to_string_prefix_notation() const;
    bool check_if_min_fraction() const;
};

#endif //MOBILEAPPPROJECT_EXPRESSION_H
