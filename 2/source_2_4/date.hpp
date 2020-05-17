/**
 * Experiment 2
 * Problem 4
 * 
 * Author: Robotxm
 * Date: 2020-04-23
 * Description: Declaration of Date and its member function
 */

#ifndef _DATE_HPP
#define _DATE_HPP

#include <iostream>

struct Date
{
public:
    /**
    * Construct a new Date with current date of system 
    */
    Date();

    /**
    * Construct a new Date with specific date
    */
    Date(int y, int m, int d);

    /**
    * Add (d > 0) or subtract (d < 0) days from given Date
    */
    void AddDay(int d);

    /**
    * Add (d > 0) or subtract (d < 0) months from given Date
    */
    void AddMonth(int m);

    /**
    * Add (d > 0) or subtract (d < 0) years from given Date
    */
    void AddYear(int y);

    /**
    * Get the weekday of given Date
    * 
    * Return an integer ranged from 0 to 6
    * 0 - Sunday
    * 1 - Monday
    * 2 - Tuesday
    * 3 - Wednesday
    * 4 - Thursday
    * 5 - Friday
    * 6 - Saturday
    */
    int GetWeekday();

    /**
     * Return a new Date of next Monday of current Date object
     */
    Date GetNextMonday();

private:
    int year_;
    int month_;
    int day_;

    /**
    * Determine whether current year is leap year 
    */
    bool IsLeap();

    friend std::ostream &operator<<(std::ostream &out, const Date &date);
};

#endif
