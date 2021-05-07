#ifndef MOBILEAPPPROJECT_EXPRESSIONELEMENT_H
#define MOBILEAPPPROJECT_EXPRESSIONELEMENT_H

#include <iostream>
#include <sstream>

class ExpressionElement
{
public:
    virtual std::string to_string() const = 0;
};

#endif //MOBILEAPPPROJECT_EXPRESSIONELEMENT_H
