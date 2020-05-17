/**
 * Experiment 3
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-05-08
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

    int BaseException::GetCount()
    {
        return count_;
    }
} // namespace error
