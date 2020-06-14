/**
 * Experiment 6
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Definition of MultiplicationNode
 */

#ifndef _MULTIPLICATION_NODE
#define _MULTIPLICATION_NODE

#include "binary_operator_node.hpp"

class MultiplicationNode : public BinaryOperatorNode
{
public:
    MultiplicationNode(ExpressionNode *left, ExpressionNode *right)
        : BinaryOperatorNode(Lexer::TokenValue::MUL, left, right) {}

    double Eval() const { return left_->Eval() * right_->Eval(); }
    const char *GetTypeName() const { return "Multiplication"; }
};

#endif
