/**
 * Experiment 6
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Declaration of BinaryOperatorNode
 */

#ifndef _BINARY_OPERATOR_NODE
#define _BINARY_OPERATOR_NODE

#include "operator_node.hpp"

class BinaryOperatorNode : public OperatorNode
{
public:
    BinaryOperatorNode(Lexer::TokenValue token, ExpressionNode *left, ExpressionNode *right)
        : left_(left), right_(right), OperatorNode(token) {}
    ~BinaryOperatorNode()
    {
        delete left_;
        delete right_;
    }

    std::string ToStringByPreOrder() const;
    std::string ToStringByInOrder() const;
    std::string ToStringByPostOrder() const;
    void PrintTree(int indent) const;

protected:
    ExpressionNode *left_;
    ExpressionNode *right_;
};

#endif
