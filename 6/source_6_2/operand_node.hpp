/**
 * Experiment 6
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Declaration of OperandNode
 */

#ifndef _OPERAND_NODE
#define _OPERAND_NODE

#include "expression_node.hpp"

class OperandNode : public ExpressionNode
{
public:
    OperandNode(double value) : value_(value), ExpressionNode(Lexer::TokenValue::NUMBER) {}
    ~OperandNode() {}

    double Eval() const { return value_; }
    std::string ToStringByPreOrder() const;
    std::string ToStringByInOrder() const;
    std::string ToStringByPostOrder() const;
    const char *GetTypeName() const { return "Number"; }
    void PrintTree(int indent) const;

private:
    double value_;
};

#endif
