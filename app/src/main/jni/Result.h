#ifndef MOBILEAPPPROJECT_RESULT_H
#define MOBILEAPPPROJECT_RESULT_H

#include <cstdlib>

struct Result
{
private:
    size_t total_questions; // Total number of questions the user has answered
    size_t correct_questions; // The total number of questions answered correctly
    size_t incorrect_questions; // The total number of questions answered incorrectly
public:
    // Default constructor, defaults all values to 0
    Result();

    // Returns the total number of questions that have had an answer submitted to
    size_t get_total_questions() const;
    // Returns the total number of questions guessed correctly
    size_t get_correct_questions() const;
    // Returns the total number of questions guessed incorrectly
    size_t get_incorrect_questions() const;
    // Returns the current grade of the current game
    float calculate_grade() const;

    // Increments the number of correct questions and also increments the total number of questions
    void increment_correct_questions();
    // Increments the number of incorrect questions and also increments the total number of questions
    void increment_incorrect_questions();
};


#endif //MOBILEAPPPROJECT_RESULT_H
