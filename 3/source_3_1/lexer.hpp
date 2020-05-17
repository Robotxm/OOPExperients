/**
 * Experiment 3
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-05-08
 * Description: Definition of lexer
 */

#ifndef _LEXER_HPP
#define _LEXER_HPP

#include <string>
#include "error.hpp"

namespace lexer
{
    class Lexer
    {
    public:
        Lexer(const Lexer &) = delete;
        Lexer &operator=(const Lexer &) = delete;
        static Lexer &GetInstance()
        {
            static Lexer instance;
            return instance;
        }

        // Token enum
        enum TokenValue
        {
            NAME,
            NUMBER,
            END,
            PLUS = '+',
            MINUS = '-',
            MUL = '*',
            DIV = '/',
            PRINT = ';',
            ASSIGN = '=',
            LP = '(',
            RP = ')',
        };

        /**
         * Get value of token
         */
        TokenValue GetToken();

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

        /**
         * Skip current statement
         */
        void Skip();

        /**
         * Set stream of input
         * 
         * @param input The pointer of input that will be used
         */
        void SetInput(std::istream *input);

        /**
         * Begin process
         * 
         * @param is_prompt_shown If this is true, prompt will be shown before input
         */
        void Start(bool is_prompt_shown);

    private:
        TokenValue current_token_; // Indicate current token
        double number_value_;      // Store current number
        std::string string_value_; // Store current string
        std::istream *input_;
        int statement_count_;

        Lexer()
        {
            current_token_ = PRINT;
            statement_count_ = 0;
        }
    };
} // namespace lexer

#endif
