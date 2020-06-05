/**
 * Experiment 5
 * Problem 3
 *
 * Author: Robotxm
 * Date: 2020-05-26
 * Description: Implementation of Double
 */

#include <sstream>
#include <iostream>
#include <cmath>
#include "double.hpp"
#include "exception.hpp"

Double::Double(const char *s)
{
    value_ = Double::Parse(s).value_;
}

Double::Double(const std::string &s)
{
    value_ = Double::Parse(s).value_;
}

Double Double::Parse(const std::string &s)
{
    return Parse(s.c_str());
}

Double Double::Parse(const char *s)
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
    int integer = 0;
    double dec = 0.0;
    int exp = -1;
    // Process integer part
    do
    {
        if (isdigit(c))
            c -= '0';
        else
            throw FormatException("Input string was not in a correct format.");
        integer *= 10;
        integer += c;
    } while ((c = *s++) != '.');
    // Process decimal part
    c = *s++;
    do
    {
        if (isdigit(c))
            c -= '0';
        else
            throw FormatException("Input string was not in a correct format.");
        dec += c * std::pow(10, exp);
        exp--;
    } while (c = *s++);

    return Double(integer + dec);
}

int Double::CompareTo(Double &value)
{
    if (value_ > value.value_)
        return 1;
    if (value_ < value.value_)
        return -1;
    return 0;
}

Double &Double::operator=(const Double &value)
{
    value_ = value.value_;
    return *this;
}

Double &Double::operator=(double value)
{
    value_ = value;
    return *this;
}

Double::operator std::string() const
{
    std::stringstream ss;
    ss << value_;
    return ss.str();
}

Double::operator double() const
{
    return double(value_);
}

Double operator+(Double a, Double b)
{
    return Double(a.value_ + b.value_);
}

Double operator+(Double a)
{
    return a;
}

Double &operator++(Double &value)
{
    value.value_++;
    return value;
}

Double operator++(Double &value, int)
{
    Double t = value;
    value.value_++;
    return t;
}

Double &operator+=(Double &value, Double &diff)
{
    value.value_ += diff.value_;
    return value;
}

Double operator-(Double a, Double b)
{
    return Double(a.value_ - b.value_);
}

Double operator-(Double a)
{
    return Double(-a.value_);
}

Double &operator--(Double &value)
{
    value.value_--;
    return value;
}

Double operator--(Double &value, int)
{
    Double t = value;
    value.value_--;
    return t;
}

Double &operator-=(Double &value, Double &diff)
{
    value.value_ -= diff.value_;
    return value;
}

Double operator*(Double a, Double b)
{
    return Double(a.value_ * b.value_);
}

Double &operator*=(Double &value, Double &diff)
{
    value.value_ *= diff.value_;
    return value;
}

Double operator/(Double a, Double b)
{
    return Double(a.value_ / b.value_);
}

Double &operator/=(Double &value, Double &diff)
{
    value.value_ /= diff.value_;
    return value;
}

bool operator>(Double a, Double b)
{
    return a.CompareTo(b) == 1;
}

bool operator>=(Double a, Double b)
{
    return a.CompareTo(b) >= 0;
}

bool operator==(Double a, Double b)
{
    return a.CompareTo(b) == 0;
}

bool operator!=(Double a, Double b)
{
    return a.CompareTo(b) != 0;
}

bool operator<(Double a, Double b)
{
    return a.CompareTo(b) == -1;
}

bool operator<=(Double a, Double b)
{
    return a.CompareTo(b) <= 0;
}

std::istream &operator>>(std::istream &s, Double &a)
{
    int i;
    s >> i;
    a = Double(i);
    return s;
}

std::ostream &operator<<(std::ostream &s, const Double &a)
{
    s << a.value_;
    return s;
}
