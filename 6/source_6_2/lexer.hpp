/**
 * Experiment 6
 * Problem 2
 *
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Definition of Lexer
 */

#ifndef _LEXER_HPP
#define _LEXER_HPP

#include <string>
#include "error.hpp"

class Lexer
{
public:
    Lexer() { current_token_ = TokenValue::END; }

    // Token enum
    enum class TokenValue
    {
        NUMBER,
        END,
        PLUS = '+',
        MINUS = '-',
        MUL = '*',
        DIV = '/',
        LP = '(',
        RP = ')',
    };

    /**
     * Get value of token
     */
    TokenValue GetToken(std::istream *input);

    /**
     * Get current token
     */
    TokenValue GetCurrentToken();

    /**
     * Get current number
     */
    double GetCurrentNumber();

    /**
     * Get current string
     */
    std::string GetCurrentString();

protected:
    TokenValue current_token_; // Indicate current token
    double number_value_;      // Store current number
    std::string string_value_; // Store current string
};

#endif
