/**
 * Experiment 5
 * Problem 3
 *
 * Author: Robotxm
 * Date: 2020-05-26
 * Description: Declaration of Integer
 */

#include <sstream>
#include <iostream>
#include "integer.hpp"
#include "exception.hpp"

Integer::Integer(const char *s)
{
    value_ = Integer::Parse(s).value_;
}

Integer::Integer(const std::string &s)
{
    value_ = Integer::Parse(s).value_;
}

Integer Integer::Parse(const std::string &s)
{
    return Parse(s.c_str());
}

Integer Integer::Parse(const char *s)
{
    if (s == nullptr)
        throw ArgumentNullException("Value cannot be null.");

    // Store current character
    char c;
    // Skip all whitespaces
    do
    {
        c = *s++;
    } while (isspace(c));
    // Check if negative
    bool is_negative = false;
    if (c == '-')
    {
        is_negative = true;
        c = *s++; // Move to the 'real' number part
    }
    else if (c == '+') // Skip plus
        c = *s++;

    // Check base
    int base = 0;
    if (c == '0' && (tolower(*s) == 'x')) // Hex
    {
        c = s[1];
        base = 16;
        s += 2;
    }
    else
        base = (c == '0' ? 8 : 10); // If c is '0', the string given will be parsed as an octal number

    // max_result and max_result_remainder are used to check if number overflows
    // The max_result is the limit set to the maximum or minimum (depends on number given) value of int32
    int max_result = is_negative ? INT_MIN : INT_MAX;
    // The last digit of limit value
    int max_result_remainder = max_result % (unsigned int)base;
    // Remove the last digit from max_result for future usage
    max_result /= (unsigned int)base;

    // Start to parse number
    int result = 0;
    bool is_overflowed = false; // It is negative when overflows
    do
    {
        // Process each digit
        if (isdigit(c))
            c -= '0';
        else if (isalpha(c)) // Find letter which represents number, in this problem it is used for hex
            c -= isupper(c) ? 'A' - 10 : 'a' - 10;
        else // Illegal character
            throw FormatException("Input string was not in a correct format.");
        if (c >= base) // Illegal digit
            throw FormatException("Input string was not in a correct format.");

        // Check overflow
        // If current result is larger than limit of max_result,
        // or current result equals to max_result but the last digit which will be appended to current result is larger than max_result_remainder,
        // the result is considered as an overflowed number
        // And, if overflow occurs when base is not 16, the conversion will be interrupted
        if ((is_overflowed || result > max_result || (result == max_result && c > max_result_remainder)))
            throw OverflowException("Value was either too large or too small for an int32.");

        is_overflowed = false;
        result *= base;
        result += c;
    } while (c = *s++);

    if (is_negative)
        return Integer(-result);
    else
        return Integer(result);
}

int Integer::CompareTo(Integer &value)
{
    if (value_ > value.value_)
        return 1;
    if (value_ < value.value_)
        return -1;
    return 0;
}

Integer &Integer::operator=(const Integer &value)
{
    value_ = value.value_;
    return *this;
}

Integer &Integer::operator=(int value)
{
    value_ = value;
    return *this;
}

Integer::operator std::string() const
{
    std::stringstream ss;
    ss << value_;
    return ss.str();
}

Integer::operator int() const
{
    return value_;
}

Integer operator+(Integer a, Integer b)
{
    return Integer(a.value_ + b.value_);
}

Integer operator+(Integer a)
{
    return a;
}

Integer &operator++(Integer &value)
{
    value.value_++;
    return value;
}

Integer operator++(Integer &value, int)
{
    Integer t = value;
    value.value_++;
    return t;
}

Integer &operator+=(Integer &value, Integer &diff)
{
    value.value_ += diff.value_;
    return value;
}

Integer operator-(Integer a, Integer b)
{
    return Integer(a.value_ - b.value_);
}

Integer operator-(Integer a)
{
    return Integer(-a.value_);
}

Integer &operator--(Integer &value)
{
    value.value_--;
    return value;
}

Integer operator--(Integer &value, int)
{
    Integer t = value;
    value.value_--;
    return t;
}

Integer &operator-=(Integer &value, Integer &diff)
{
    value.value_ -= diff.value_;
    return value;
}

Integer operator*(Integer a, Integer b)
{
    return Integer(a.value_ * b.value_);
}

Integer &operator*=(Integer &value, Integer &diff)
{
    value.value_ *= diff.value_;
    return value;
}

Integer operator/(Integer a, Integer b)
{
    return Integer(a.value_ / b.value_);
}

Integer &operator/=(Integer &value, Integer &diff)
{
    value.value_ /= diff.value_;
    return value;
}

bool operator>(Integer a, Integer b)
{
    return a.CompareTo(b) == 1;
}

bool operator>=(Integer a, Integer b)
{
    return a.CompareTo(b) >= 0;
}

bool operator==(Integer a, Integer b)
{
    return a.CompareTo(b) == 0;
}

bool operator!=(Integer a, Integer b)
{
    return a.CompareTo(b) != 0;
}

bool operator<(Integer a, Integer b)
{
    return a.CompareTo(b) == -1;
}

bool operator<=(Integer a, Integer b)
{
    return a.CompareTo(b) <= 0;
}

std::istream &operator>>(std::istream &s, Integer &a)
{
    int i;
    s >> i;
    a = Integer(i);
    return s;
}

std::ostream &operator<<(std::ostream &s, const Integer &a)
{
    s << a.value_;
    return s;
}
