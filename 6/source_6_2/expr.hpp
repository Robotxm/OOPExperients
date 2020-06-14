/**
 * Experiment 6
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Declaration of Expr
 */

#ifndef _EXPR_HPP
#define _EXPR_HPP

#include <iostream>
#include "parser.hpp"
#include "expression_node.hpp"

class Expr
{
public:
    Expr(const char *expression)
    {
        Parser parser;
        root_ = parser.Parse(expression);
    }
    ~Expr() { delete root_; }

    /**
     * Calculate the value of current expression
     */
    double Eval() { return root_->Eval(); }

    /**
     * Print the expression using prefix notation
     */
    void PrintByPreOrder() { std::cout << root_->ToStringByPreOrder() << std::endl; }

    /**
     * Print the fully parenthesized expression
     */
    void PrintByInOrder() { std::cout << root_->ToStringByInOrder() << std::endl; }

    /**
     * Print the expression using postfix notation
     */
    void PrintByPostOrder() { std::cout << root_->ToStringByPostOrder() << std::endl; }

    /**
     * Print the whole syntax tree of current expression
     */
    void PrintTree() { root_->PrintTree(0); }

private:
    ExpressionNode *root_;
};

#endif
