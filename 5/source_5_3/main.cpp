/**
 * Experiment 5
 * Problem 3
 *
 * Author: Robotxm
 * Date: 2020-05-26
 * Description: Entry of application
 */

#include <iostream>
#include "integer.hpp"
#include "double.hpp"

using namespace std;

int main()
{
    try
    {
        Integer a;
        cin >> a;
        cout << "Integer a: " << a << endl;
        cout << "Compare a with 526: " << a << (a > 526 ? ">" : (a == 526 ? "=" : "<")) << 526 << endl;
        cout << "Value of a++: " << a++ << endl;
        cout << "Now a is: " << a << endl;
        cout << "Value of --a: " << --a << endl;
        cout << "Now a is: " << a << endl;
        cout << "a + Integer(233) = " << a + Integer(233) << endl;
        cout << "a - 512 = " << a - 512 << endl;
        cout << "a * 128.812 = " << a * 128.812 << endl;
        cout << "a / Double(4.5) = " << a / Double(4.5) << endl;
        
        Double b;
        cin >> b;
        cout << "Double b: " << b << endl;
        cout << "Compbre b with 5.25: " << b << (b > 5.25 ? ">" : (b == 5.25 ? "=" : "<")) << 5.25 << endl;
        cout << "Value of b++: " << b++ << endl;
        cout << "Now b is: " << b << endl;
        cout << "Value of --b: " << --b << endl;
        cout << "Now b is: " << b << endl;
        cout << "b + Double(78.33) = " << b + Double(78.33) << endl;
        cout << "b - 512 = " << b - 512 << endl;
        cout << "b * 128.812 = " << b * 128.812 << endl;
        cout << "b / Integer(4) = " << b / Integer(4) << endl;
    }
    catch (exception &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
