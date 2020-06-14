/**
 * Experiment 6
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Implementation of UnaryOperatorNode
 */

#include <sstream>
#include <iostream>
#include "unary_operator_node.hpp"

std::string UnaryOperatorNode::ToStringByPreOrder() const
{
    std::stringstream ss;
    ss << char(token_) << " " << child_->ToStringByPreOrder();

    return ss.str();
}

std::string UnaryOperatorNode::ToStringByInOrder() const
{
    std::stringstream ss;
    ss << "(" << char(token_) << child_->ToStringByInOrder() << ")";

    return ss.str();
}

std::string UnaryOperatorNode::ToStringByPostOrder() const
{
    std::stringstream ss;
    ss << child_->ToStringByPostOrder() << " " << char(token_);

    return ss.str();
}

void UnaryOperatorNode::PrintTree(int indent) const
{
    auto print_indent = [indent]() {
        for (int i = 0; i < indent; i++)
            std::cout << "    ";
    };
    print_indent();
    std::cout << "type: " << GetTypeName() << std::endl;
    print_indent();
    std::cout << "operator: " << char(GetType()) << std::endl;
    print_indent();
    std::cout << "argument " << std::endl;
    child_->PrintTree(indent + 1);
}