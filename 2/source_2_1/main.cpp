/**
 * Experiment 2
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-04-22
 */

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
            cout << "Hello, " << argv[i] << "!" << endl;
    }

    return 0;
}