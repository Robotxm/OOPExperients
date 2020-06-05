/**
 * Experiment 5
 * Problem 4
 *
 * Author: Robotxm
 * Date: 2020-05-27
 * Description: Implementation of Vec4
 */

#include "vec4.hpp"

double &Vec4::operator[](const int idx)
{
    if (idx < 0 || idx > 3)
        throw IndexOutOfRangeException("Index was outside the bounds of the array.");
    return items_[idx];
}

double Vec4::operator[](const int idx) const
{
    if (idx < 0 || idx > 3)
        throw IndexOutOfRangeException("Index was outside the bounds of the array.");
    return items_[idx];
}

Vec4 Vec4::operator+(const Vec4 &x) const
{
    Vec4 result = *this;
    result += x;
    return result;
}

Vec4 Vec4::operator+(const double x) const
{
    Vec4 result = *this;
    result += x;
    return result;
}

Vec4 Vec4::operator-(const Vec4 &x) const
{
    Vec4 result = *this;
    result -= x;
    return result;
}

Vec4 Vec4::operator-(const double x) const
{
    Vec4 result = *this;
    result -= x;
    return result;
}

Vec4 Vec4::operator*(const Vec4 &x) const
{
    Vec4 result = *this;
    result *= x;
    return result;
}

Vec4 Vec4::operator*(const double x) const
{
    Vec4 result = *this;
    result *= x;
    return result;
}

Vec4 Vec4::operator/(const Vec4 &x) const
{
    Vec4 result = *this;
    result /= x;
    return result;
}

Vec4 Vec4::operator/(const double x) const
{
    Vec4 result = *this;
    result /= x;
    return result;
}

Vec4 &Vec4::operator+=(const Vec4 &x)
{
    for (int i = 0; i < 4; i++)
        items_[i] += x.items_[i];
    return *this;
}

Vec4 &Vec4::operator+=(const double x)
{
    for (int i = 0; i < 4; i++)
        items_[i] += x;
    return *this;
}

Vec4 &Vec4::operator-=(const Vec4 &x)
{
    for (int i = 0; i < 4; i++)
        items_[i] -= x.items_[i];
    return *this;
}

Vec4 &Vec4::operator-=(const double x)
{
    for (int i = 0; i < 4; i++)
        items_[i] -= x;
    return *this;
}

Vec4 &Vec4::operator*=(const Vec4 &x)
{
    for (int i = 0; i < 4; i++)
        items_[i] *= x.items_[i];
    return *this;
}

Vec4 &Vec4::operator*=(const double x)
{
    for (int i = 0; i < 4; i++)
        items_[i] *= x;
    return *this;
}

Vec4 &Vec4::operator/=(const Vec4 &x)
{
    for (int i = 0; i < 4; i++)
        items_[i] /= x.items_[i];
    return *this;
}

Vec4 &Vec4::operator/=(const double x)
{
    for (int i = 0; i < 4; i++)
        items_[i] /= x;
    return *this;
}

Vec4 &Vec4::operator=(const Vec4 &x)
{
    for (int i = 0; i < 4; i++)
        items_[i] = x.items_[i];
    return *this;
}

Vec4 operator+(const double x, const Vec4 &y)
{
    return y + x;
}

Vec4 operator-(const double x, const Vec4 &y)
{
    Vec4 result;
    for (int i = 0; i < 4; i++)
        result[i] = x - y.items_[i];
    return result;
}

Vec4 operator*(const double x, const Vec4 &y)
{
    return y * x;
}

Vec4 operator/(const double x, const Vec4 &y)
{
    Vec4 result;
    for (int i = 0; i < 4; i++)
        result[i] = x / y.items_[i];
    return result;
}

std::istream &operator>>(std::istream &input, Vec4 &x)
{
    for (int i = 0; i < 4; i++)
    {
        double v;
        input >> v;
        x.items_[i] = v;
    }
    return input;
}

std::ostream &operator<<(std::ostream &output, const Vec4 &x)
{
    output << '[';
    for (int i = 0; i < 4; i++)
    {
        output << x.items_[i];
        if (i < 3)
            output << ", ";
    }
    output << ']';
    return output;
}
