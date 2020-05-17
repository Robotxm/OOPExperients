/**
 * Experiment 3
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-05-08
 * Description: Implementation of lexer
 */

#include <cctype>
#include <iostream>
#include <exception>
#include "error.hpp"
#include "lexer.hpp"
#include "parser.hpp"

namespace lexer
{
    Lexer::TokenValue Lexer::GetToken()
    {
        char ch;

        // Wait for valid input
        do
        {
            if (!input_->get(ch))
                return current_token_ = END;
        } while (ch != '\n' && isspace(ch));

        // Get token
        switch (ch)
        {
        case 0:
            return current_token_ = END;
        case '\n':
            return current_token_ = PRINT;
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
            input_->putback(ch);
            *input_ >> number_value_;
            return current_token_ = NUMBER;
        default:
            // Get symbol
            // A valid symbol starts with an letter
            if (isalpha(ch))
            {
                string_value_ = ch;
                while (input_->get(ch) && isalnum(ch))
                    string_value_.push_back(ch);
                input_->putback(ch);
                return current_token_ = NAME;
            }

            // No valid input
            throw error::SyntaxException("Bad token");
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

    void Lexer::SetInput(std::istream *input)
    {
        input_ = input;
        statement_count_ = 0; // Reset count
    }

    void Lexer::Start(bool is_prompt_showed)
    {
        // Check if stream valid
        if (input_ == nullptr)
            throw error::InvalidStreamException("Did you forget call SetInput() first?");

        while (input_)
        {
            try
            {
                // It is necessary when use g++, or in_avail() always returns 0
                input_->sync_with_stdio(false);

                if (input_->rdbuf()->in_avail() == 0 && is_prompt_showed)
                    std::cout << "> ";
                // Get token of first character
                GetInstance().GetToken();
                if (GetInstance().GetCurrentToken() == END)
                    break;
                if (GetInstance().GetCurrentToken() == PRINT)
                    continue;

                // Process statement
                std::cout << parser::Parser::GetInstance().ProcessExpression(false) << '\n';
                statement_count_++;
            }
            catch (std::exception &e)
            {
                statement_count_++;
                std::cout << "[Statement " << statement_count_ << "] " << e.what() << std::endl;
                Skip();
            }
        }
    }

    void Lexer::Skip()
    {
        // No need for skip if current stream is empty, or current token is PRINT
        if (input_->rdbuf()->in_avail() == 0 || current_token_ == PRINT)
            return;

        while (*input_)
        {
            char ch;

            input_->get(ch);

            // Eat '\n' and ';'
            switch (ch)
            {
            case '\n':
            case ';':
                return;
            }
        }
    }
} // namespace lexer
