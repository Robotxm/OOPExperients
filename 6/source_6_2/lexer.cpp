/**
 * Experiment 6
 * Problem 2
 *
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Implementation of Lexer
 */

#include <cctype>
#include <iostream>
#include <exception>
#include "error.hpp"
#include "lexer.hpp"
#include "parser.hpp"

Lexer::TokenValue Lexer::GetToken(std::istream *input)
{
    char ch;

    // Wait for valid input
    do
    {
        if (!input->get(ch))
            return current_token_ = TokenValue::END;
    } while (ch != '\n' && isspace(ch));

    // Get token
    switch (ch)
    {
    case 0:
        return current_token_ = TokenValue::END;
    case '+':
    case '-':
    case '*':
    case '/':
    case ';':
    case '(':
    case ')':
    case '=':
        return current_token_ = TokenValue(ch);
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
    case '.':
        // Put back to stream for future use
        input->putback(ch);
        *input >> number_value_;
        return current_token_ = TokenValue::NUMBER;
    default:
        // No valid input
        std::string msg = "Unexpected token ";
        msg += ch;
        throw error::SyntaxException(msg);
    }
}

Lexer::TokenValue Lexer::GetCurrentToken()
{
    return current_token_;
}

double Lexer::GetCurrentNumber()
{
    return number_value_;
}

std::string Lexer::GetCurrentString()
{
    return string_value_;
}
