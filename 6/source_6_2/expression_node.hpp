/**
 * Experiment 6
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Declaration of ExpressionNode
 */

#ifndef _EXPRESSION_NODE_HPP
#define _EXPRESSION_NODE_HPP

#include "lexer.hpp"

class ExpressionNode
{
public:
    ExpressionNode(Lexer::TokenValue token) : token_(token) {}
    virtual ~ExpressionNode() {}

    /**
     * Get type of current node
     */
    Lexer::TokenValue GetType() const { return token_; }

    /**
     * Return a string which represents type of node
     */
    virtual const char *GetTypeName() const = 0;

    /**
     * Get value of tree whose root is current node
     */
    virtual double Eval() const = 0;

    /**
     * Return a string which represents an arithmetic expression with pre-order
     */
    virtual std::string ToStringByPreOrder() const = 0;

    /**
     * Return a string which represents an arithmetic expression with in-order
     */
    virtual std::string ToStringByInOrder() const = 0;

    /**
     * Return a string which represents an arithmetic expression with post-order
     */
    virtual std::string ToStringByPostOrder() const = 0;

    /**
     * Print tree whose root is current node
     */
    virtual void PrintTree(int indent) const = 0;

protected:
    Lexer::TokenValue token_;
};

#endif
