/**
 * Experiment 4
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-05-11
 * Description: Main file to test code
 */

#include <iostream>
#include <ctime>
#include "date.hpp"

using namespace std;

int main()
{
     try
     {
          // Set default date
          time_t now = std::time(0);
          tm *ltm = std::localtime(&now);
          Date::SetDefaultDate(1900 + ltm->tm_year, Date::Month(1 + ltm->tm_mon), ltm->tm_mday);

          int year, month, day;
          cin >> year >> month >> day;
          Date t(year, Date::Month(month), day);
          cout << "Add 1 day, 1 month and 1 year: " << endl
               << t.AddDay(1).AddMonth(1).AddYear(1) << endl;
          cout << "Differenctial day(s) between new date and 2020-5-16: " << endl
               << t.Diff(Date(2020, Date::MAY, 16)) << endl;
          cout << "Weekday of new date:" << endl
               << t.GetWeekday() << endl;
          cout << "Last day of month of the date:" << endl
               << t.GetLastDayInMonth() << endl;
     }
     catch (exception &e)
     {
          cout << e.what() << endl;
     }

     return 0;
}