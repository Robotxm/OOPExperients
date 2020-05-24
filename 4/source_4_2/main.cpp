/**
 * Experiment 4
 * Problem 2
 *
 * Author: Robotxm
 * Date: 2020-05-12
 * Description: Main file to test code
 */

#include <iostream>
#include "tree.hpp"

using namespace std;

int main()
{
    // Create a binary tree
    BinaryTree tree;

    string word;
    while (cin >> word)
    {
        tree.Insert(word);
    }

    // Pre-order
    cout << endl
        << "Pre-order with indent:" << endl;
    tree.Print(0);
    // In-order
    cout << endl
        << "Alphabetical-order:" << endl;
    tree.Print();

    return 0;

    // Deconstructor of tree will be called after return
}
