/**
 * Experiment 6
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-05-23
 * Description: Implementation of base exception
 */

#include <iostream>
#include "error.hpp"
#include "lexer.hpp"

namespace error
{

    const char *BaseException::what() const throw()
    {
        return message_.c_str();
    }
} // namespace error
