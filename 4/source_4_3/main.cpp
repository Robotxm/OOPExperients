/**
 * Experiment 4
 * Problem 3
 *
 * Author: Robotxm
 * Date: 2020-05-13
 * Description: Entry of application
 */

#include <iostream>
#include <exception>
#include <cmath>
#include "expr.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    try
    {
        string expression_str;
        cin >> expression_str;
        Expr expression(expression_str.c_str());
        cout << "Prefix notation:" << endl;
        expression.PrintByPreOrder();
        cout << "Fully parenthesized notation:" << endl;
        expression.PrintByInOrder();
        cout << "Postfix notation:" << endl;
        expression.PrintByPostOrder();
        cout << "Result:" << endl;
        cout << expression.Eval() << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
