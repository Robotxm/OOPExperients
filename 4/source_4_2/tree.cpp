/**
 * Experiment 4
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-12
 * Description: Implement functions of Tnode
 **/

#include "tree.hpp"
#include <stack>
#include <iostream>
#include <functional>

BinaryTree::BinaryTree()
{
    root_ = nullptr;
}

BinaryTree::~BinaryTree()
{
    std::function<void(Tnode *&)> destroy = [&destroy](Tnode *&root) -> void {
        if (root)
        {
            // Destory children
            if (root->left)
                destroy(root->left);
            if (root->right)
                destroy(root->right);

            delete root;
        }
    };

    destroy(root_);

    std::cout << std::endl
        << "Tree has been destroyed" << std::endl;
}

void BinaryTree::Insert(const std::string &key)
{
    Tnode *parent = nullptr;
    Tnode *node = root_;

    // Find where to insert
    while (node != nullptr)
    {
        parent = node;
        // Compare keys
        if (key > node->word)
            node = node->right;
        else if (key < node->word)
            node = node->left;
        else // Key already exists
        {
            node->count++; // Increase
            return;
        }
    }

    node = new Tnode;      // Create a new node
    node->word = key;      // Set key
    if (parent == nullptr) // Empty tree
        root_ = node;
    else
    {
        // Connect to parent node
        if (key > parent->word)
            parent->right = node;
        else
            parent->left = node;
    }
}

void BinaryTree::Print(unsigned int indent)
{
    std::function<void(Tnode *&, unsigned int)> print = [&print](Tnode *&root, unsigned int in) {
        // Traverse tree by pre-order
        if (root)
        {
            for (int i = 0; i < in; i++)
                std::cout << "    ";
            root->Print();
            print(root->left, in + 1);
            print(root->right, in + 1);
        }
    };

    print(root_, indent);
}

void BinaryTree::Print()
{
    std::function<void(Tnode *&)> print = [&print](Tnode *&root) {
        // Traverse tree by in-order
        if (root)
        {
            print(root->left);
            root->Print();
            print(root->right);
        }
    };

    print(root_);
}

void BinaryTree::Tnode::Print()
{
    std::cout << word << ": " << count << std::endl;
}
