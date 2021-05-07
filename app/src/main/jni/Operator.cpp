#include "Operator.h"

Operator::Operator(const char &_element)
        : symbol{ (OperatorEnum)_element }
{
    switch(symbol)
    {
        case ADD:
            operation = add;
            break;
        case SUBTRACT:
            operation = subtract;
            break;
        case MULTIPLY:
            operation = multiply;
            break;
        case DIVIDE:
            operation = divide;
            break;
        default:
            operation = NULL;
    }
}

std::string Operator::to_string() const
{
    switch(symbol)
    {
        case ADD:
            return "+";
        case SUBTRACT:
            return "-";
        case MULTIPLY:
            return "*";
        case DIVIDE:
            return "/";
        default:
            return "";
    }
}

float Operator::run_operation(const Operand &operand1, const Operand &operand2)
{
    return operation(operand1, operand2);
}

float Operator::add(const Operand &operand1, const Operand &operand2)
{
    return operand1.get_value() + operand2.get_value();
}

float Operator::subtract(const Operand &operand1, const Operand &operand2)
{
    return operand1.get_value() - operand2.get_value();
}

float Operator::multiply(const Operand &operand1, const Operand &operand2)
{
    return operand1.get_value() * operand2.get_value();
}

float Operator::divide(const Operand &operand1, const Operand &operand2)
{
    return operand1.get_value() / operand2.get_value();
}