/**
 * Experiment 2
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-04-22
 * Description: Main file to test code
 */

#include <iostream>
#include "tnode.hpp"

using namespace std;

int main()
{
     // Create the root
     Tnode *root = nullptr;

     string word;
     while (cin >> word)
     {
          Insert(root, word);
     }

     // Pre-order
     cout << endl
          << "Pre-order with indent:" << endl;
     OutputTree(root, 0);
     // In-order
     cout << endl
          << "Alphabetical-order:" << endl;
     OutputTree(root);

     // Destory
     Destroy(root);
     cout << endl
          << "Tree has been destroyed" << endl;
     
     return 0;
}
