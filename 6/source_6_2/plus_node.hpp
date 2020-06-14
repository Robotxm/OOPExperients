/**
 * Experiment 6
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Definition of PlusNode
 */

#ifndef _PLUS_NODE
#define _PLUS_NODE

#include "binary_operator_node.hpp"

class PlusNode : public BinaryOperatorNode
{
public:
    PlusNode(ExpressionNode *left, ExpressionNode *right)
        : BinaryOperatorNode(Lexer::TokenValue::PLUS, left, right) {}

    double Eval() const { return left_->Eval() + right_->Eval(); }
    const char *GetTypeName() const { return "Plus"; }
};

#endif
