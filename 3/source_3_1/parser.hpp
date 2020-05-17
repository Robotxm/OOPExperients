/**
 * Experiment 3
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-05-08
 * Description: Definition of parser
 */

#ifndef _PARSER_HPP
#define _PARSER_HPP

#include "error.hpp"
#include "lexer.hpp"

namespace parser
{
    class Parser
    {
    public:
        Parser(const Parser &) = delete;
        Parser &operator=(const Parser &) = delete;
        static Parser &GetInstance()
        {
            static Parser instance;
            return instance;
        }

        double ProcessExpression(bool get);
        double ProcessTerm(bool get);
        double ProcessPrimary(bool get);

    private:
        lexer::Lexer &lexer_instance_; // Get the instance of lexer for convenience
        Parser() : lexer_instance_(lexer::Lexer::GetInstance()) {}
    };
} // namespace parser

#endif
