/**
 * Experiment 2
 * Problem 4
 * 
 * Author: Robotxm
 * Date: 2020-04-23
 * Description: Implementation of Date
 */

#include "date.hpp"
#include <ctime>

Date::Date()
{
    // Use time_t and tm to get current date of system
    time_t now = std::time(0);
    tm *ltm = std::localtime(&now);
    this->year_ = 1900 + ltm->tm_year;
    this->month_ = 1 + ltm->tm_mon;
    this->day_ = ltm->tm_mday;
}

Date::Date(int y, int m, int d)
{
    this->year_ = y;
    this->month_ = m;
    this->day_ = d;
    // Validate and correct
    if (this->year_ < 1970)
        this->year_ = 1970;
    int days_of_month[12] = {31, IsLeap() ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (this->month_ < 1)
        this->year_ = 1;
    else if (this->month_ > 12)
        this->month_ = 12;
    if (this->day_ < 1)
        this->day_ = 1;
    else if (this->day_ > days_of_month[this->month_ - 1])
        this->day_ = days_of_month[this->month_ - 1];
}

bool Date::IsLeap()
{
    return (this->year_ % 4 == 0 && this->year_ % 100 != 0 || this->year_ % 400 == 0);
}

void Date::AddDay(int d)
{
    int days_of_month[12] = {31, IsLeap() ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (d >= 0) // Add
    {
        this->day_ += d;                                    // Add all days
        while (this->day_ > days_of_month[this->month_ - 1]) // Process carry
        {
            this->day_ -= days_of_month[this->month_ - 1];
            this->month_++;         // Next month
            if (this->month_ == 13) // Next year
            {
                this->month_ = 1;
                this->year_++;
            }
            days_of_month[1] = IsLeap() ? 29 : 28;
        }
    }
    else // Subtract
    {
        d = -d;
        this->day_ -= d;
        while (this->day_ < 1)
        {
            this->month_--;        // Last month
            if (this->month_ == 0) // Last year
            {
                this->month_ = 12;
                this->year_--;
            }
            this->day_ += days_of_month[this->month_ - 1];
            days_of_month[1] = IsLeap() ? 29 : 28;
        }
    }
}

void Date::AddMonth(int m)
{
    this->month_ += m;
    if (m >= 0)
    {
        while (this->month_ > 12)
        {
            this->month_ -= 12;
            this->year_++; // Next year
        }
    }
    else
    {
        while (this->month_ < 1)
        {
            this->month_ += 12;
            this->year_--; // Last year
        }
    }

    // Validate day
    int days_of_month[12] = {31, IsLeap() ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (this->day_ > days_of_month[this->month_ - 1])
        this->day_ = days_of_month[this->month_ - 1];
}

void Date::AddYear(int y)
{
    this->year_ += y;
    // Set correct day for February if not leap
    if (!IsLeap() && this->month_ == 2 && this->day_ > 28)
        this->day_ = 28;
}

int Date::GetWeekday()
{
    // Use Zeller algorithm
    int m = this->month_ <= 2 ? (this->month_ + 12) : this->month_; // Correct when month is smaller than 2
    int d = this->day_;
    int y = (this->month_ <= 2 ? (this->year_ - 1) : this->year_) % 100;
    int c = (this->month_ <= 2 ? (this->year_ - 1) : this->year_) / 100;
    int w = (y + y / 4 + c / 4 - 2 * c + (13 * (m + 1) / 5) + d - 1) % 7;
    if (w < 0) // Correct when result is negative
        w += 7;
    return w;
}

Date Date::GetNextMonday()
{
    // Get current weekday
    int weekday = GetWeekday();
    // Create a new Date from current Date
    Date t(year_,month_,day_);
    if (weekday == 0)
        t.AddDay(1);
    else
        t.AddDay(8 - weekday);
    return t;
}

std::ostream &operator<<(std::ostream &out, const Date &date)
{
    out << date.year_ << "-" << date.month_ << "-" << date.day_;
    return out;
}
