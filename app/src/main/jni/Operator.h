#ifndef MOBILEAPPPROJECT_OPERATOR_H
#define MOBILEAPPPROJECT_OPERATOR_H

#include <iostream>
#include <functional>

#include "Operand.h"

class Operator : public ExpressionElement
{
private:
    enum OperatorEnum : char
    {
        ADD = 43, SUBTRACT = 45, MULTIPLY = 42, DIVIDE = 47
    };

    char symbol;
    std::function<float(const Operand&, const Operand&)> operation;

public:
    Operator(const char &_element);

public:
    std::string to_string() const;
    float run_operation(const Operand &operand1, const Operand &operand2);

private:
    static float add(const Operand &operand1, const Operand &operand2);
    static float subtract(const Operand &operand1, const Operand &operand2);
    static float multiply(const Operand &operand1, const Operand &operand2);
    static float divide(const Operand &operand1, const Operand &operand2);
};

#endif //MOBILEAPPPROJECT_OPERATOR_H
