/**
 * Experiment 6
 * Problem 2
 *
 * Author: Robotxm
 * Date: 2020-05-23
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
          cout << endl
               << "Fully parenthesized notation:" << endl;
          expression.PrintByInOrder();
          cout << endl
               << "Postfix notation:" << endl;
          expression.PrintByPostOrder();
          cout << endl
               << "Syntax Tree: " << endl;
          expression.PrintTree();
          cout << endl
               << "Result:" << endl;
          double value = expression.Eval();
          cout << value << endl;
     }
     catch (exception &e)
     {
          cout << e.what() << endl;
     }

     return 0;
}
