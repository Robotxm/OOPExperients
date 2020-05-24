/**
 * Experiment 4
 * Problem 1
 *
 * Author: Robotxm
 * Date: 2020-05-11
 * Description: Declaration of Date
 */

#ifndef _date_hpp
#define _date_hpp

#include <iostream>
#include <string>
#include <tuple>
#include <exception>

class Date
{
public:
    enum Month
    {
        DEFAULT,
        JANUARY,
        FEBRUARY,
        MARCH,
        APRIL,
        MAY,
        JUNE,
        JULY,
        AUGUST,
        SEPTEMBER,
        OCTUBER,
        NOVEMBER,
        DECEMBER
    };

    /**
     * Construct a new Date with specific date
     * Default value will be used to fill in field which is not specified
     */
    Date(int y = 0, Month m = DEFAULT, int d = 0);

    /**
     * Add (d > 0) or subtract (d < 0) days from given Date
     */
    Date& AddDay(int d);

    /**
     * Add (d > 0) or subtract (d < 0) months from given Date
     */
    Date& AddMonth(int m);

    /**
     * Add (d > 0) or subtract (d < 0) years from given Date
     */
    Date& AddYear(int y);

    /**
     * Return day of current Date
     */
    int GetDay() const;

    /**
     * Return month of current Date
     */
    Month GetMonth() const;

    /**
     * Return year of current Date
     */
    int GetYear() const;

    /**
     * Return days current Date and specified date
     */
    int Diff(const Date& date) const;

    /**
     * Determine whether current year is leap year
     */
    operator std::string() const;

    /**
     * Determine whether current year is leap year
     */
    bool IsLeap() const;

    /**
     * Determine whether specified year is leap year
     */
    static bool IsLeap(int y);

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
     * Return the last day of month of current Date
     */
    Date GetLastDayInMonth() const;
    
    /**
     * Set default date for all Date instances
     */
    static void SetDefaultDate(int y, Month m, int d);

    /**
     * This exception will be thrown when an illegal date is provided
     */
    class BadDateException : public std::exception
    {
    public:
        BadDateException(std::string msg) : message_("Bad Date: " + msg) {}

        virtual const char* what() const throw() { return message_.c_str(); }

    private:
        std::string message_;
    };

private:
    static Date default_date_;
    int days_after_origin_;

    /**
     * Return a tuple which contains year, month and day of current Date
     */
    std::tuple<int, Month, int> GetDate() const;

    friend std::ostream& operator<<(std::ostream& out, const Date& date);
    friend int operator-(const Date& date1, const Date& date2);
};

#endif
