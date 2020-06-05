/**
 * Experiment 5
 * Problem 1
 *
 * Author: Robotxm
 * Date: 2020-05-25
 * Description: Entry of application
 */

#include <iostream>
#include "complex.hpp"

using namespace std;

int main()
{
    Complex a, b;
    cin >> a >> b;
    cout << "a = " << a << endl
         << "b = " << b << endl
         << "a + b = " << a + b << endl
         << "a - b = " << a - b << endl
         << "a * b = " << a * b << endl
         << "a / b = " << a / b << endl
         << "Conj(a) = " << Complex::Conjugate(a) << endl
         << "Abs(b) = " << Complex::Abs(b) << endl
         << "Norm(a) = " << Complex::Norm(a) << endl
         << "Asin(b) = " << Complex::Asin(b) << endl
         << "Acos(a) = " << Complex::Acos(a) << endl
         << "Atan(b) = " << Complex::Atan(b) << endl;

    return 0;
}