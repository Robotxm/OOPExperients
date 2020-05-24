/**
 * Experiment 4
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-12
 * Description: Declaration of Tnode and its functions
 */

#ifndef _tnode_hpp
#define _tnode_hpp

#include <string>

class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();

    /**
     * Insert a word to the tree
     * If the word exists, increase its count
     */
    void Insert(const std::string &word);

    /**
     * Print the tree by pre-order with indent 
     */
    void Print(unsigned int indent);

    /**
     * Print the tree by in-order 
     */
    void Print();

private:
    class Tnode
    {
    public:
        std::string word;
        Tnode *left;
        Tnode *right;
        int count;

        // Initialize
        Tnode() : word(""), count(1), left(nullptr), right(nullptr) {}
        
        /**
         * Print current node 
         */
        void Print();
    } * root_;
};

#endif
