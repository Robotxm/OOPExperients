/**
 * Experiment 2
 * Problem 4
 * 
 * Author: Robotxm
 * Date: 2020-04-23
 * Description: Main file to test code
 */

#include <iostream>
#include "date.hpp"

using namespace std;

int main()
{
    Date t(2020, 5, 14);
    cout << t.GetNextMonday() << endl;

    return 0;
}