/**
 * Experiment 5
 * Problem 3
 *
 * Author: Robotxm
 * Date: 2020-05-26
 * Description: Declaration of Double
 */

#ifndef _DOUBLE_HPP
#define _DOUBLE_HPP

#include <string>

class Double
{
public:
    explicit Double(double value = 0.0) : value_(value){};
    Double(const Double &value) : value_(value.value_){};
    explicit Double(const char *s);
    explicit Double(const std::string &s);

    /**
     * Parse a Double from a string 
     */
    static Double Parse(const std::string &s);

    /**
     * Parse a Double from a string 
     */
    static Double Parse(const char *s);

    /**
     * Return an double representation of current Double 
     */
    double GetValue() { return value_; }

    /**
     * Compare this instance to another instance, returning an int32 that
     * indicates the relationship.
     * @return 0 if the values are equal
     *         Negative number if value_ is less than value
     *         Positive number if value_ is more than value
     *         null is considered to be less than any instance, hence returns positive number
     */
    int CompareTo(Double &value);

    Double &operator=(const Double &value);
    Double &operator=(double value);
    operator std::string() const;
    operator double() const;
    friend Double operator+(Double a, Double b);
    friend Double operator+(Double a);
    friend Double &operator++(Double &value);
    friend Double operator++(Double &value, int);
    friend Double &operator+=(Double &value, Double &diff);
    friend Double operator-(Double a, Double b);
    friend Double operator-(Double a);
    friend Double &operator--(Double &value);
    friend Double operator--(Double &value, int);
    friend Double &operator-=(Double &value, Double &diff);
    friend Double operator*(Double a, Double b);
    friend Double &operator*=(Double &value, Double &diff);
    friend Double operator/(Double a, Double b);
    friend Double &operator/=(Double &value, Double &diff);
    friend bool operator>(Double a, Double b);
    friend bool operator>=(Double a, Double b);
    friend bool operator==(Double a, Double b);
    friend bool operator!=(Double a, Double b);
    friend bool operator<(Double a, Double b);
    friend bool operator<=(Double a, Double b);
    friend std::istream &operator>>(std::istream &s, Double &a);
    friend std::ostream &operator<<(std::ostream &s, const Double &a);

private:
    double value_;
};

#endif
