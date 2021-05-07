#ifndef MOBILEAPPPROJECT_OPERAND_H
#define MOBILEAPPPROJECT_OPERAND_H

#include <iostream>
#include <sstream>

#include "ExpressionElement.h"

class Operand : public ExpressionElement
{
private:
    float element;

public:
    Operand(const float &value);
    float get_value() const;
    std::string to_string() const;
};

#endif //MOBILEAPPPROJECT_OPERAND_H
