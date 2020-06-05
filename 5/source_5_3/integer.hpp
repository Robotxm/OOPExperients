/**
 * Experiment 5
 * Problem 3
 *
 * Author: Robotxm
 * Date: 2020-05-26
 * Description: Implementation of Integer
 */

#ifndef _INTEGER_HPP
#define _INTEGER_HPP

#include <string>

class Integer
{
public:
    explicit Integer(int value = 0) : value_(value){};
    Integer(const Integer &value) : value_(value.value_){};
    explicit Integer(const char *s);
    explicit Integer(const std::string &s);

    /**
     * Parse an integer from a string 
     */
    static Integer Parse(const std::string &s);

    /**
     * Parse an integer from a string 
     */
    static Integer Parse(const char *s);

    /**
     * Return an int32 representation of current Integer 
     */
    int GetValue() { return value_; }

    /**
     * Compare this instance to another instance, returning an int32 that
     * indicates the relationship.
     * @return 0 if the values are equal
     *         Negative number if value_ is less than value
     *         Positive number if value_ is more than value
     *         null is considered to be less than any instance, hence returns positive number
     */
    int CompareTo(Integer &value);

    Integer &operator=(const Integer &value);
    Integer &operator=(int value);
    operator std::string() const;
    operator int() const;
    friend Integer operator+(Integer a, Integer b);
    friend Integer operator+(Integer a);
    friend Integer &operator++(Integer &value);
    friend Integer operator++(Integer &value, int);
    friend Integer &operator+=(Integer &value, Integer &diff);
    friend Integer operator-(Integer a, Integer b);
    friend Integer operator-(Integer a);
    friend Integer &operator--(Integer &value);
    friend Integer operator--(Integer &value, int);
    friend Integer &operator-=(Integer &value, Integer &diff);
    friend Integer operator*(Integer a, Integer b);
    friend Integer &operator*=(Integer &value, Integer &diff);
    friend Integer operator/(Integer a, Integer b);
    friend Integer &operator/=(Integer &value, Integer &diff);
    friend bool operator>(Integer a, Integer b);
    friend bool operator>=(Integer a, Integer b);
    friend bool operator==(Integer a, Integer b);
    friend bool operator!=(Integer a, Integer b);
    friend bool operator<(Integer a, Integer b);
    friend bool operator<=(Integer a, Integer b);
    friend std::istream &operator>>(std::istream &s, Integer &a);
    friend std::ostream &operator<<(std::ostream &s, const Integer &a);

private:
    int value_;
};

#endif
