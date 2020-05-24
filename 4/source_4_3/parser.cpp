/**
 * Experiment 4
 * Problem 3
 *
 * Author: Robotxm
 * Date: 2020-05-13
 * Description: Implementation of parser
 */

#include <iostream>
#include <sstream>
#include "parser.hpp"
#include "lexer.hpp"
#include "expression_node.hpp"

ExpressionNode *Parser::Parse(const char *expression)
{
    input_ << expression;
    while (input_)
    {
        // Get token of first character
        lexer_.GetToken(&input_);
        auto result = ProcessExpression(false);
        if (lexer_.GetCurrentToken() != Lexer::END)
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
        case Lexer::PLUS:
            right = ProcessTerm(true);
            if (!right)
            {
                delete left;
                return nullptr;
            }
            left = new ExpressionNode(Lexer::PLUS, left, right);
            break;
        case Lexer::MINUS:
            right = ProcessTerm(true);
            if (!right)
            {
                delete left;
                return nullptr;
            }
            left = new ExpressionNode(Lexer::MINUS, left, right);
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
        case Lexer::MUL:
            right = ProcessPrimary(true);
            if (!right)
            {
                delete left;
                return nullptr;
            }
            left = new ExpressionNode(Lexer::MUL, left, right);
            break;
        case Lexer::DIV:
            right = ProcessPrimary(true);
            if (!right)
            {
                delete left;
                return nullptr;
            }
            left = new ExpressionNode(Lexer::DIV, left, right);
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
    case Lexer::NUMBER:
    {
        lexer_.GetToken(&input_);
        return new ExpressionNode(Lexer::NUMBER, nullptr, nullptr, lexer_.GetCurrentNumber());
    }
    case Lexer::PLUS:
        return new ExpressionNode(Lexer::PLUS, nullptr, ProcessPrimary(true), lexer_.GetCurrentNumber());
    case Lexer::MINUS:
        return new ExpressionNode(Lexer::MINUS, nullptr, ProcessPrimary(true), lexer_.GetCurrentNumber());
    case Lexer::LP:
    {
        auto e = ProcessExpression(true);
        if (lexer_.GetCurrentToken() != Lexer::RP) // Check right parenthesis
            throw error::SyntaxException(") expected");
        lexer_.GetToken(&input_);
        return e;
    }
    default:
        throw error::SyntaxException("Primary expected");
    }
}
