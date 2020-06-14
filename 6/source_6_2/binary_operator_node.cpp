/**
 * Experiment 6
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Implementation of BinaryOperatorNode
 */

#include <sstream>
#include <iostream>
#include "binary_operator_node.hpp"

std::string BinaryOperatorNode::ToStringByPreOrder() const
{
    std::stringstream ss;
    ss << char(token_) << " " << left_->ToStringByPreOrder() << " " << right_->ToStringByPreOrder();

    return ss.str();
}

std::string BinaryOperatorNode::ToStringByInOrder() const
{
    std::stringstream ss;
    ss << "(" << left_->ToStringByInOrder() << char(token_) << right_->ToStringByInOrder() << ")";

    return ss.str();
}

std::string BinaryOperatorNode::ToStringByPostOrder() const
{
    std::stringstream ss;
    ss << left_->ToStringByPostOrder() << " " << right_->ToStringByPostOrder() << " " << char(token_);

    return ss.str();
}

void BinaryOperatorNode::PrintTree(int indent) const
{
    // Use lambda expression to simplify output of indent
    auto print_indent = [indent]() {
        for (int i = 0; i < indent; i++)
            std::cout << "    ";
    };
    print_indent();
    std::cout << "type: " << GetTypeName() << std::endl;
    print_indent();
    std::cout << "operator: " << char(GetType()) << std::endl;
    print_indent();
    std::cout << "left " << std::endl;
    left_->PrintTree(indent + 1);
    print_indent();
    std::cout << "right " << std::endl;
    right_->PrintTree(indent + 1);
}