/**
 * Experiment 2
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-04-22
 * Description: Implement functions of Tnode
 */

#include <stack>
#include <iostream>
#include "tnode.hpp"

void Insert(Tnode *&root, std::string &key)
{
    Tnode *parent = nullptr;
    Tnode *node = root;

    // Find where to insert
    while (node != nullptr)
    {
        parent = node;
        // Compare keys
        if (key > node->word)
            node = node->right;
        else if (key < node->word)
            node = node->left;
        else // key already exists
        {
            node->count++; // Increase
            return;
        }
    }

    node = new Tnode;      // Create a new node
    node->word = key;      // Set key
    if (parent == nullptr) // Empty tree
        root = node;
    else
    {
        // Connect to parent node
        if (key > parent->word)
            parent->right = node;
        else
            parent->left = node;
    }
}

void OutputTree(Tnode *&root, unsigned int indent)
{
    // Traverse tree by pre-order
    if (root)
    {
        for (int i = 0; i < indent; i++)
            std::cout << "    ";
        std::cout << root->word << ": " << root->count << std::endl;
        OutputTree(root->left, indent + 1);
        OutputTree(root->right, indent + 1);
    }
}

void OutputTree(Tnode *&root)
{
    // Traverse tree by in-order
    if (root)
    {
        OutputTree(root->left);
        std::cout << root->word << ": " << root->count << std::endl;
        OutputTree(root->right);
    }
}

void Destroy(Tnode *&root)
{
    if (root)
    {
        // Destory children
        if (root->left)
            Destroy(root->left);
        if (root->right)
            Destroy(root->right);

        delete root;
    }
}
