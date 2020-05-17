/**
 * Experiment 2
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-04-22
 * Description: Declaration of Tnode and its functions
 */

#ifndef _TNODE_HPP
#define _TNODE_HPP

#include <string>

struct Tnode
{
    std::string word;
    int count;
    Tnode *left;
    Tnode *right;

    // Initialize
    Tnode() : word(""), count(1), left(nullptr), right(nullptr) {}
};

/**
 * Insert a word to the tree
 * If the word exists, its count will be increased
 * 
 * @param root Root of the tree
 * @param word Word to be inserted
 */
void Insert(Tnode *&root, std::string &word);

/**
 * Print the tree by pre-order with indent
 * 
 * @param root Root of the tree
 * @param indent Number of space that will be used as indent
 */
void OutputTree(Tnode *&root, unsigned int indent);

/**
 * Print the tree by in-order
 * 
 * @param root Root of the tree
 */
void OutputTree(Tnode *&root);

/**
 * Destory the tree 
 * 
 * @param root Root of the tree
 */
void Destroy(Tnode *&root);

#endif
