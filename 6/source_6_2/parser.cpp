/**
 * Experiment 6
 * Problem 2
 *
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Implementation of Parser
 */

#include <iostream>
#include <sstream>
#include "parser.hpp"
#include "lexer.hpp"
#include "plus_node.hpp"
#include "minus_node.hpp"
#include "multiplication_node.hpp"
#include "division_node.hpp"
#include "operand_node.hpp"
#include "positive_sign_node.hpp"
#include "negative_sign_node.hpp"

ExpressionNode *Parser::Parse(const char *expression)
{
    input_ << expression;
    while (input_)
    {
        // Get token of first character
        lexer_.GetToken(&input_);
        auto result = ProcessExpression(false);
        if (lexer_.GetCurrentToken() != Lexer::TokenValue::END)
        {
            std::string msg = "Unexpected token ";
            msg += char(lexer_.GetCurrentToken());
            throw error::SyntaxException(msg);
        }
        return result;
    }
}

ExpressionNode *Parser::ProcessExpression(bool get)
{
    ExpressionNode *left;
    ExpressionNode *right;
    left = ProcessTerm(get);
    if (!left)
        return nullptr;
    while (1)
    {
        switch (lexer_.GetCurrentToken())
        {
        case Lexer::TokenValue::PLUS:
            right = ProcessTerm(true);
            if (!right)
            {
                delete left;
                return nullptr;
            }
            left = new PlusNode(left, right);
            break;
        case Lexer::TokenValue::MINUS:
            right = ProcessTerm(true);
            if (!right)
            {
                delete left;
                return nullptr;
            }
            left = new MinusNode(left, right);
            break;
        default:
            return left;
        }
    }
}

ExpressionNode *Parser::ProcessTerm(bool get)
{
    ExpressionNode *left;
    ExpressionNode *right;
    left = ProcessPrimary(get);
    if (!left)
        return nullptr;
    while (1)
    {
        switch (lexer_.GetCurrentToken())
        {
        case Lexer::TokenValue::MUL:
            right = ProcessPrimary(true);
            if (!right)
            {
                delete left;
                return nullptr;
            }
            left = new MultiplicationNode(left, right);
            break;
        case Lexer::TokenValue::DIV:
            right = ProcessPrimary(true);
            if (!right)
            {
                delete left;
                return nullptr;
            }
            left = new DivisionNode(left, right);
            break;
        default:
            return left;
        }
    }
}

ExpressionNode *Parser::ProcessPrimary(bool get)
{
    if (get)
        lexer_.GetToken(&input_);
    switch (lexer_.GetCurrentToken())
    {
    case Lexer::TokenValue::NUMBER:
    {
        lexer_.GetToken(&input_);
        return new OperandNode(lexer_.GetCurrentNumber());
    }
    case Lexer::TokenValue::PLUS:
        return new PositiveSignNode(ProcessPrimary(true));
    case Lexer::TokenValue::MINUS:
        return new NegativeSignNode(ProcessPrimary(true));
    case Lexer::TokenValue::LP:
    {
        auto e = ProcessExpression(true);
        if (lexer_.GetCurrentToken() != Lexer::TokenValue::RP) // Check right parenthesis
            throw error::SyntaxException(") expected");
        lexer_.GetToken(&input_);
        return e;
    }
    default:
        throw error::SyntaxException("Primary expected");
    }
}
