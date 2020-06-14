/**
 * Experiment 6
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Definition of DivisionNode
 */

#ifndef _DIVISION_NODE
#define _DIVISION_NODE

#include "binary_operator_node.hpp"

class DivisionNode : public BinaryOperatorNode
{
public:
    DivisionNode(ExpressionNode *left, ExpressionNode *right)
        : BinaryOperatorNode(Lexer::TokenValue::DIV, left, right) {}

    double Eval() const
    {
        if (right_->Eval() == 0)
            throw error::ArithmeticException("Divided by zero");
        return left_->Eval() / right_->Eval();
    }

    const char *GetTypeName() const { return "Division"; }
};

#endif
