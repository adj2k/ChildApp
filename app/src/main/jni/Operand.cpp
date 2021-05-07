#include "Operand.h"

Operand::Operand(const float &value)
        : element{ value }
{}

float Operand::get_value() const
{
    return element;
}

std::string Operand::to_string() const
{
    std::ostringstream oss;
    oss << element;
    return oss.str();
}