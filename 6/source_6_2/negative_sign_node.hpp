/**
 * Experiment 6
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Definition of NegativeSignNode
 */

#ifndef _NEGATIVE_SIGN_NODE
#define _NEGATIVE_SIGN_NODE

#include "unary_operator_node.hpp"

class NegativeSignNode : public UnaryOperatorNode
{
public:
    NegativeSignNode(ExpressionNode *child) : UnaryOperatorNode(Lexer::TokenValue::MINUS, child) {}

    double Eval() const { return -child_->Eval(); }
    const char *GetTypeName() const { return "Negative Sign"; }
};

#endif
