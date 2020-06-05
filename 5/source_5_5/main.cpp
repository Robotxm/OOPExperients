/**
 * Experiment 5
 * Problem 4
 *
 * Author: Robotxm
 * Date: 2020-05-27
 * Description: Definition of Ptr_to_T
 */

#include <iostream>
#include <string>
#include "ptr_to_t.hpp"

using namespace std;

int main()
{
    try
    {
        string arr[] = {"hahah", "hehehe", "haha ha2"};
        Ptr_to_T<string> ptr(arr, 3, 0);
        cout << boolalpha << "First element of ptr: " << *ptr << endl;
        cout << "Change the first element to ""haha- test 233"": ";
        *ptr = "haha- test 233";
        cout << *ptr << endl;
        ++(++ptr);
        cout << "Length of last element: " << (*ptr).size() << endl;
        cout << "*(++ptr) (exception expected): ";
        cout << *(++ptr) << endl;
    }
    catch (exception &e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}