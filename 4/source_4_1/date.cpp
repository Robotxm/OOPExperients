/**
 * Experiment 4
 * Problem 1
 *
 * Author: Robotxm
 * Date: 2020-05-11
 * Description: Implementation of Date
 */

#include <sstream>
#include <cmath>
#include "date.hpp"

Date Date::default_date_ = Date(1970, Date::JANUARY, 1);

Date::Date(int y, Month m, int d)
{
    // Illegal year will cause an exception
    if (y < 1970)
        throw BadDateException("Date before 1970-1-1 is not supported");
    // Illegal month and day will be replaced with default value
    m = m ? m : default_date_.GetMonth();
    d = d ? d : default_date_.GetDay();
    // Validate day
    int days_of_month[12] = { 31, IsLeap(y) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (d > days_of_month[m - 1])
        throw BadDateException("Specified month has no days of " + std::to_string(d));

    days_after_origin_ = 0;
    for (int i = 1970; i < y; i++)
        days_after_origin_ += IsLeap(i) ? 366 : 365;
    for (int i = 1; i < m; i++)
        days_after_origin_ += days_of_month[i - 1];
    days_after_origin_ += d - 1;
}

Date& Date::AddDay(int d)
{
    days_after_origin_ += d;

    return *this;
}

Date& Date::AddMonth(int m)
{
    auto date = GetDate();
    int year = std::get<0>(date), month = std::get<1>(date), day = std::get<2>(date);

    month += m;
    if (m >= 0)
    {
        while (month > 12)
        {
            month -= 12;
            year++; // Next year
        }
    }
    else
    {
        while (month < 1)
        {
            month += 12;
            year--; // Last year
        }
    }

    // Validate day
    int days_of_month[12] = { 31, IsLeap(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (day > days_of_month[month - 1])
        day = days_of_month[month - 1];

    days_after_origin_ = 0;
    for (int i = 1970; i < year; i++)
        days_after_origin_ += IsLeap(i) ? 366 : 365;
    for (int i = 1; i < month; i++)
        days_after_origin_ += days_of_month[i - 1];
    days_after_origin_ += day - 1;

    return *this;
}

Date& Date::AddYear(int y)
{
    auto date = GetDate();
    int year = std::get<0>(date), month = std::get<1>(date), day = std::get<2>(date);

    year += y;
    // Set correct day for February if not leap
    if (!IsLeap() && month == 2 && day > 28)
        day = 28;

    int days_of_month[12] = { 31, IsLeap(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    days_after_origin_ = 0;
    for (int i = 1970; i < year; i++)
        days_after_origin_ += IsLeap(i) ? 366 : 365;
    for (int i = 1; i < month; i++)
        days_after_origin_ += days_of_month[i - 1];
    days_after_origin_ += day - 1;

    return *this;
}

int Date::GetDay() const
{
    return std::get<2>(GetDate());
}

Date::Month Date::GetMonth() const
{
    return Month(std::get<1>(GetDate()));
}

int Date::GetYear() const
{
    return std::get<0>(GetDate());
}

int Date::Diff(const Date& date) const
{
    return *this - date;
}

Date::operator std::string() const
{
    auto date_tuple = GetDate();
    std::stringstream ss;
    ss << std::get<0>(date_tuple) << "-" << std::get<1>(date_tuple) << "-" << std::get<2>(date_tuple);
    return ss.str();
}

bool Date::IsLeap() const
{
    return IsLeap(std::get<0>(GetDate()));
}

bool Date::IsLeap(int y)
{
    return (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
}

int Date::GetWeekday()
{
    auto date = GetDate();
    // Use Zeller algorithm
    int m = std::get<1>(date) <= 2 ? (std::get<1>(date) + 12) : std::get<1>(date); // Correct when month is smaller than 2
    int d = std::get<2>(date);
    int y = (std::get<1>(date) <= 2 ? (std::get<0>(date) - 1) : std::get<0>(date)) % 100;
    int c = (std::get<1>(date) <= 2 ? (std::get<0>(date) - 1) : std::get<0>(date)) / 100;
    int w = (y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1) % 7;
    if (w < 0) // Correct when result is negative
        w += 7;
    return w;
}

Date Date::GetLastDayInMonth() const
{
    auto date = GetDate();
    int days_of_month[12] = { 31, IsLeap() ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return Date(std::get<0>(date), std::get<1>(date), days_of_month[std::get<1>(date) - 1]);
}

void Date::SetDefaultDate(int y, Month m, int d)
{
    // Validate
    if (y < 1970)
        throw BadDateException("Date before 1970-1-1 is not supported");
    int days_of_month[12] = { 31, IsLeap(y) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (d < 1 || d > days_of_month[m - 1])
        throw BadDateException("Illegal day");

    default_date_ = Date(y, m, d);
}

std::tuple<int, Date::Month, int> Date::GetDate() const
{
    int year_of_origin = 1970, month_of_origin = 1, day_of_origin = 1;
    int days_of_month[12] = { 31, IsLeap(year_of_origin) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    day_of_origin += days_after_origin_;                       // Add all days
    while (day_of_origin > days_of_month[month_of_origin - 1]) // Process carry
    {
        day_of_origin -= days_of_month[month_of_origin - 1];
        month_of_origin++;         // Next month
        if (month_of_origin == 13) // Next year
        {
            month_of_origin = 1;
            year_of_origin++;
        }
        days_of_month[1] = IsLeap(year_of_origin) ? 29 : 28;
    }

    return std::make_tuple(year_of_origin, Date::Month(month_of_origin), day_of_origin);
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
    out << std::string(date);
    return out;
}

int operator-(const Date& date1, const Date& date2)
{
    return std::abs(date1.days_after_origin_ - date2.days_after_origin_);
}
