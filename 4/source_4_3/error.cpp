/**
 * Experiment 4
 * Problem 3
 * 
 * Author: Robotxm
 * Date: 2020-05-13
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
