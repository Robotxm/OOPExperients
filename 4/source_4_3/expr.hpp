/**
 * Experiment 4
 * Problem 3
 * 
 * Author: Robotxm
 * Date: 2020-05-13
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

    /**
     * Calculate the value of current expression
     */
    double Eval();

    /**
     * Print the expressiong using prefix notation
     */
    void PrintByPreOrder() { std::cout << root_->ToStringByPreOrder() << std::endl; }

    /**
     * Print the fully parenthesized expression
     */
    void PrintByInOrder() { std::cout << root_->ToStringByInOrder() << std::endl; }

    /**
     * Print the expressiong using postfix notation
     */
    void PrintByPostOrder() { std::cout << root_->ToStringByPostOrder() << std::endl; }

private:
    ExpressionNode *root_;
};

#endif
