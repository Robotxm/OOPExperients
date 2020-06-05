/**
 * Experiment 5
 * Problem 4
 *
 * Author: Robotxm
 * Date: 2020-05-27
 * Description: Declaration of Vec4
 */

#ifndef _VEC4_HPP
#define _VEC4_HPP

#include <iostream>
#include <exception>

class Vec4
{
public:
    Vec4() : items_{0} {}
    Vec4(double comp0, double comp1, double comp2, double comp3) : items_{comp0, comp1, comp2, comp3} {}
    Vec4(const Vec4 &obj) : items_{obj.items_[0], obj.items_[1], obj.items_[2], obj.items_[3]} {}

    double &operator[](const int idx);
    double operator[](const int idx) const;

    Vec4 operator+(const Vec4 &x) const;
    Vec4 operator+(const double x) const;
    Vec4 operator-(const Vec4 &x) const;
    Vec4 operator-(const double x) const;
    Vec4 operator*(const Vec4 &x) const;
    Vec4 operator*(const double x) const;
    Vec4 operator/(const Vec4 &x) const;
    Vec4 operator/(const double x) const;
    Vec4 &operator+=(const Vec4 &x);
    Vec4 &operator+=(const double x);
    Vec4 &operator-=(const Vec4 &x);
    Vec4 &operator-=(const double x);
    Vec4 &operator*=(const Vec4 &x);
    Vec4 &operator*=(const double x);
    Vec4 &operator/=(const Vec4 &x);
    Vec4 &operator/=(const double x);
    Vec4 &operator=(const Vec4 &x);

    friend Vec4 operator+(const double x, const Vec4 &y);
    friend Vec4 operator-(const double x, const Vec4 &y);
    friend Vec4 operator*(const double x, const Vec4 &y);
    friend Vec4 operator/(const double x, const Vec4 &y);
    friend std::istream &operator>>(std::istream &input, Vec4 &x);
    friend std::ostream &operator<<(std::ostream &output, const Vec4 &x);

    /**
     * This exception will be thrown when index specified is out of bounds
     */
    class IndexOutOfRangeException : public std::exception
    {
    public:
        IndexOutOfRangeException(std::string msg) : message_(msg) {}

        virtual const char *what() const throw() { return message_.c_str(); }

    private:
        std::string message_;
    };

private:
    double items_[4];
};

#endif
