/**
 * Experiment 5
 * Problem 3
 *
 * Author: Robotxm
 * Date: 2020-05-26
 * Description: Definition of exceptions
 */

#ifndef _EXCEPTION_HPP
#define _EXCEPTION_HPP

#include <exception>
#include <string>

/**
 * Base class for exception
 */
class BaseException : public std::exception
{
public:
    BaseException(std::string exception_name, std::string msg)
        : message_(exception_name + ": " + msg) {}

    virtual const char *what() const throw() { return message_.c_str(); }

private:
    std::string message_;
};

/**
 * This exception will be thrown when non-null argument expected is null
 */
class ArgumentNullException : public BaseException
{
public:
    ArgumentNullException(std::string msg) : BaseException("ArgumentNullException", msg) {}
};

/**
 * This exception will be thrown when trying to parse from a string which contains invalid characters
 */
class FormatException : public BaseException
{
public:
    FormatException(std::string msg) : BaseException("FormatException", msg) {}
};

/**
 * This exception will be thrown when trying to parse from a string which contains overflowed number
 */
class OverflowException : public BaseException
{
public:
    OverflowException(std::string msg) : BaseException("OverflowException", msg) {}
};

#endif
