/**
 * Experiment 4
 * Problem 3
 * 
 * Author: Robotxm
 * Date: 2020-05-13
 * Description: Implementation of ExpressionNode
 */

#include <string>
#include <sstream>
#include "expression_node.hpp"
#include "error.hpp"

double ExpressionNode::GetValue() const
{
    if (!this)
        return 0;

    switch (token_)
    {
    case Lexer::PLUS:
        return left_->GetValue() + right_->GetValue();
    case Lexer::MINUS:
        return left_->GetValue() - right_->GetValue();
    case Lexer::MUL:
        return left_->GetValue() * right_->GetValue();
    case Lexer::DIV:
        if (right_->GetValue() == 0)
            throw error::ArithmeticException("Divided by zero");
        return left_->GetValue() / right_->GetValue();
    case Lexer::NUMBER:
        return value_;
    }
}

std::string ExpressionNode::ToStringByPreOrder() const
{
    std::string ret = "";

    switch (token_)
    {
    case Lexer::PLUS:
        ret += "+";
        break;
    case Lexer::MINUS:
        ret += "-";
        break;
    case Lexer::MUL:
        ret += "*";
        break;
    case Lexer::DIV:
        ret += "/";
        break;
    case Lexer::NUMBER:
        std::stringstream ss;
        ss << value_;
        ret += ss.str();
        break;
    }
    if (left_)
        ret += " " + left_->ToStringByPreOrder();
    if (right_)
        ret += " " + right_->ToStringByPreOrder();

    return ret;
}

std::string ExpressionNode::ToStringByInOrder() const
{
    std::string ret = "(";

    if (left_)
        ret += left_->ToStringByInOrder();
    switch (token_)
    {
    case Lexer::PLUS:
        ret += '+';
        break;
    case Lexer::MINUS:
        ret += '-';
        break;
    case Lexer::MUL:
        ret += '*';
        break;
    case Lexer::DIV:
        ret += '/';
        break;
    case Lexer::NUMBER:
        std::stringstream ss;
        ss << value_;
        ret += ss.str();
        break;
    }
    if (right_)
        ret += right_->ToStringByInOrder();

    return ret += ')';
}

std::string ExpressionNode::ToStringByPostOrder() const
{
    std::string ret = "";

    if (left_)
        ret += left_->ToStringByPostOrder();
    if (right_)
        ret += right_->ToStringByPostOrder();
    switch (token_)
    {
    case Lexer::PLUS:
        ret += "+";
        break;
    case Lexer::MINUS:
        ret += "-";
        break;
    case Lexer::MUL:
        ret += "*";
        break;
    case Lexer::DIV:
        ret += "/";
        break;
    case Lexer::NUMBER:
        std::stringstream ss;
        ss << value_;
        ret += ss.str();
        break;
    }

    return ret + ' ';
}
