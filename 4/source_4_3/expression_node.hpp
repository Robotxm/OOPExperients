/**
 * Experiment 4
 * Problem 3
 * 
 * Author: Robotxm
 * Date: 2020-05-13
 * Description: Declaration of ExpressionNode
 */

#ifndef _EXPRESSION_NODE_HPP_
#define _EXPRESSION_NODE_HPP_

#include "lexer.hpp"

class ExpressionNode
{
public:
    ExpressionNode(Lexer::TokenValue token, ExpressionNode *left, ExpressionNode *right, double value = 0)
    {
        token_ = token;
        left_ = left;
        right_ = right;
        value_ = value;
    }
    ~ExpressionNode()
    {
        delete left_;
        delete right_;
    }

    /**
     * Get value of tree whose root is current node
     */
    double GetValue() const;

    /**
     * Get left child of current node
     */
    ExpressionNode *GetLeftChild() const { return left_; }

    /**
     * Get right child of current node
     */
    ExpressionNode *GetRightChild() const { return right_; }

    /**
     * Return a string which represents an arithmetic expression with pre-order
     */
    std::string ToStringByPreOrder() const;

    /**
     * Return a string which represents an arithmetic expression with in-order
     */
    std::string ToStringByInOrder() const;

    /**
     * Return a string which represents an arithmetic expression with post-order
     */
    std::string ToStringByPostOrder() const;

private:
    Lexer::TokenValue token_;
    double value_;
    ExpressionNode *left_, *right_;
};

#endif
