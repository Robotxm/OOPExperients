/**
 * Experiment 5
 * Problem 4
 *
 * Author: Robotxm
 * Date: 2020-05-27
 * Description: Entry of application
 */

#include <iostream>
#include "vec4.hpp"

using namespace std;

int main()
{
    try
    {
        Vec4 vec_a, vec_b;
        cin >> vec_a >> vec_b;
        cout << "vec_a = " << vec_a << endl
             << "vec_b = " << vec_b << endl
             << "Last elemenet of vec_a = " << vec_a[3] << endl
             << "vec_a + vec_b = " << vec_a + vec_b << endl
             << "vec_a - vec_b = " << vec_a - vec_b << endl
             << "vec_a * vec_b = " << vec_a * vec_b << endl
             << "vec_a / vec_b = " << vec_a / vec_b << endl
             << "vec_a + 2.2 = " << vec_a + 2.2 << endl
             << "vec_a - 2.2 = " << vec_a - 2.2 << endl
             << "vec_a * 2.2 = " << vec_a * 2.2 << endl
             << "vec_a / 2.2 = " << vec_a / 2.2 << endl
             << "2.2 + vec_a = " << 2.2 + vec_a << endl
             << "2.2 - vec_a = " << 2.2 - vec_a << endl
             << "2.2 * vec_a = " << 2.2 * vec_a << endl
             << "2.2 / vec_a = " << 2.2 / vec_a << endl;
    }
    catch (exception &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
