/**
 * Experiment 6
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Definition of MinusNode
 */

#ifndef _MINUS_NODE
#define _MINUS_NODE

#include "binary_operator_node.hpp"

class MinusNode : public BinaryOperatorNode
{
public:
    MinusNode(ExpressionNode *left, ExpressionNode *right)
        : BinaryOperatorNode(Lexer::TokenValue::MINUS, left, right) {}

    double Eval() const { return left_->Eval() - right_->Eval(); }
    const char *GetTypeName() const { return "Minus"; }
};

#endif
