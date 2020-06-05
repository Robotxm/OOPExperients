/**
 * Experiment 5
 * Problem 2
 *
 * Author: Robotxm
 * Date: 2020-05-26
 * Description: Entry of application
 */

#include <iostream>
#include "string.hpp"

using namespace std;

int main()
{
    String s;
    cin >> s;
    cout << "s: " << s << endl
         << "Length of s: " << s.GetSize() << endl
         << "First character of s: " << s[0] << endl
         << "Replace first character with K: ";
    s.Write(0, 'K');
    cout << s << endl
         << "Append haha123 to s: ";
    s += "haha123";
    cout << s << endl;

    return 0;
}
