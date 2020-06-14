/**
 * Experiment 6
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Declaration of UnaryOperatorNode
 */

#ifndef _UNARY_OPERATOR_NODE
#define _UNARY_OPERATOR_NODE

#include "operator_node.hpp"
#include "operand_node.hpp"

class UnaryOperatorNode : public OperatorNode
{
public:
    UnaryOperatorNode(Lexer::TokenValue token, ExpressionNode *child) : child_(child), OperatorNode(token) {}
    ~UnaryOperatorNode() { delete child_; }

    std::string ToStringByPreOrder() const;
    std::string ToStringByInOrder() const;
    std::string ToStringByPostOrder() const;
    void PrintTree(int indent) const;

protected:
    ExpressionNode *child_;
};

#endif
