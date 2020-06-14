/**
 * Experiment 6
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Implementation of OperandNode
 */

#include <sstream>
#include <iostream>
#include "operand_node.hpp"

std::string OperandNode::ToStringByPreOrder() const
{
    std::stringstream ss;
    ss << Eval();
    return ss.str();
}

std::string OperandNode::ToStringByInOrder() const
{
    std::stringstream ss;
    ss << "(" << Eval() << ")";
    return ss.str();
}

std::string OperandNode::ToStringByPostOrder() const
{
    std::stringstream ss;
    ss << Eval();
    return ss.str();
}

void OperandNode::PrintTree(int indent) const
{
    auto print_indent = [indent]() {
        for (int i = 0; i < indent; i++)
            std::cout << "    ";
    };
    print_indent();
    std::cout << "type: " << GetTypeName() << std::endl;
    print_indent();
    std::cout << "value: " << value_ << std::endl;
}