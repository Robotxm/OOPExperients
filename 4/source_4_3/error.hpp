/**
 * Experiment 4
 * Problem 3
 * 
 * Author: Robotxm
 * Date: 2020-05-13
 * Description: Declaration of custom exceptions
 */

#ifndef _ERROR_HPP
#define _ERROR_HPP

#include <string>
#include <exception>

namespace error
{
    /**
     * Base class for exception
     */
    class BaseException : public std::exception
    {
    public:
        BaseException(std::string exception_name, std::string msg)
            : message_(exception_name + ": " + msg) {}

        virtual const char *what() const throw();

    private:
        std::string message_;
    };

    /**
     * This exception will be thrown when there is any syntax error in statement.
     *
     * For example, if statement 2+* is given, a syntax exception will be thrown.
     */
    class SyntaxException : public BaseException
    {
    public:
        SyntaxException(std::string msg) : BaseException("Syntax Error", msg) {}
    };

    /**
     * This exception will be thrown when there is any arithmetic error in statement.
     *
     * For example, if statement 1/0 is given, a arithmetic exception will be thrown.
     */
    class ArithmeticException : public BaseException
    {
    public:
        ArithmeticException(std::string msg) : BaseException("Arithmetic Error", msg) {}
    };
} // namespace error

#endif
