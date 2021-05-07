#include <iostream>

namespace game
{
    // Source of how age ranges were determined: https://www.knomadix.com/what-math-fundamentals-should-every-child-have-mastered-by-age-ten/#:~:text=They%20should%20be%20able%20to%20recognize%20and%20write%20each%20number,the%20curriculum%2C%20using%20small%20numbers.

    // Addition and subtraction w/ small numbers
    // Homonyms
    #define AGE_RANGE_5_TO_7 0
    // Decimal and multiplication and division
    // Synonyms and antonyms
    #define AGE_RANGE_7_to_8 1 
    // Fractions and multi-digit multiplication and division(long division)
    // Find letters alternative
    #define AGE_RANGE_8_TO_10 2

    // Integrally represents the numbers game type
    #define NUMBERS_GAME 0
    // Integrally represents the letters game type
    #define LETTERS_GAME 1
}