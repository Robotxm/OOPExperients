/**
 * Experiment 4
 * Problem 3
 *
 * Author: Robotxm
 * Date: 2020-05-13
 * Description: Declaration of parser
 */

#ifndef _PARSER_HPP
#define _PARSER_HPP

#include <sstream>
#include "lexer.hpp"
#include "expression_node.hpp"

class Parser
{
public:
    ExpressionNode *Parse(const char *expression);

private:
    ExpressionNode *ProcessExpression(bool get);
    ExpressionNode *ProcessTerm(bool get);
    ExpressionNode *ProcessPrimary(bool get);

    Lexer lexer_;
    std::stringstream input_;
};

#endif
