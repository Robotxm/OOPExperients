/**
 * Experiment 6
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Definition of ExpressionNode
 */

#ifndef _OPERATOR_NODE
#define _OPERATOR_NODE

#include "expression_node.hpp"

class OperatorNode : public ExpressionNode
{
public:
    OperatorNode(Lexer::TokenValue token) : ExpressionNode(token) {}
};

#endif
