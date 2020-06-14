/**
 * Experiment 6
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Definition of PositiveSignNode
 */

#ifndef _POSITIVE_SIGN_NODE
#define _POSITIVE_SIGN_NODE

#include "unary_operator_node.hpp"

class PositiveSignNode : public UnaryOperatorNode
{
public:
    PositiveSignNode(ExpressionNode *child) : UnaryOperatorNode(Lexer::TokenValue::PLUS, child) {}

    double Eval() const { return child_->Eval(); }
    const char *GetTypeName() const { return "Positive Sign"; }
};

#endif
