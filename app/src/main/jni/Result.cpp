#include "Result.h"

Result::Result()
    : total_questions{ 0 }, correct_questions{ 0 }, incorrect_questions{ 0 } {}

size_t Result::get_total_questions() const
{
    return total_questions;
}

size_t Result::get_correct_questions() const
{
    return correct_questions;
}

size_t Result::get_incorrect_questions() const
{
    return incorrect_questions;
}

float Result::calculate_grade() const
{
    return (float)correct_questions / (float)total_questions;
}

void Result::increment_correct_questions()
{
    ++correct_questions;
    ++total_questions;
}

void Result::increment_incorrect_questions()
{
    ++incorrect_questions;
    ++total_questions;
}