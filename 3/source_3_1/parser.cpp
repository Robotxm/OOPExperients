/**
 * Experiment 3
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-05-08
 * Description: Implementation of parser
 */

#include <string>
#include "parser.hpp"
#include "lexer.hpp"
#include "symbol_table.hpp"

namespace parser
{
    double Parser::ProcessExpression(bool get)
    {
        using namespace lexer;

        // First process term because of priority
        double left = ProcessTerm(get);
        while (1)
        {
            switch (lexer_instance_.GetCurrentToken())
            {
            case Lexer::PLUS:
                left += ProcessTerm(true);
                break;
            case Lexer::MINUS:
                left -= ProcessTerm(true);
                break;
            default: // No next item
                return left;
            }
        }
    }

    double Parser::ProcessTerm(bool get)
    {
        using namespace lexer;

        double left = ProcessPrimary(get);
        while (1)
        {
            switch (lexer_instance_.GetCurrentToken())
            {
            case Lexer::MUL:
                left *= ProcessPrimary(true);
                break;
            case Lexer::DIV:
                if (double d = ProcessPrimary(true))
                {
                    left /= d;
                    break;
                }
                // d is zero
                throw error::ArithmeticException("Divided by 0");
            default:
                return left;
            }
        }
    }

    double Parser::ProcessPrimary(bool get)
    {
        using namespace lexer;

        if (get)
            lexer_instance_.GetToken();

        switch (lexer_instance_.GetCurrentToken())
        {
        case Lexer::NUMBER:
        {
            lexer_instance_.GetToken();
            return lexer_instance_.GetCurrentNumber();
        }
        case Lexer::NAME: // Process symbol
        {
            std::string symbol_name = lexer_instance_.GetCurrentString();
            auto next_token = lexer_instance_.GetToken();
            if (next_token == Lexer::ASSIGN)
            {
                if (symbol_name == "pi" || symbol_name == "e") // Assignment to built-in constant is forbidden
                    throw error::IllegalOperationException("Cannot assign built-in constant a value");
                else
                {
                    double new_value = ProcessExpression(true);
                    symboltable::SymbolTable::GetInstance().Put(symbol_name, new_value); // Store the value in symbol table
                    return new_value;
                }
            }

            return symboltable::SymbolTable::GetInstance().Get(symbol_name, true);
        }
        case Lexer::PLUS:
            return ProcessPrimary(true);
        case Lexer::MINUS:
            return -ProcessPrimary(true);
        case Lexer::LP:
        {
            double e = ProcessExpression(true);
            if (lexer_instance_.GetCurrentToken() != Lexer::RP) // Check right parenthesis
                throw error::SyntaxException(") expected");
            lexer_instance_.GetToken();
            return e;
        }
        default:
            throw error::SyntaxException("Primary expected");
        }
    }
} // namespace parser
