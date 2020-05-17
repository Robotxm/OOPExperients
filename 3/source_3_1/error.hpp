/**
 * Experiment 3
 * Problem 1
 * 
 * Author: Robotxm
 * Date: 2020-05-08
 * Description: Definition of custom exceptions
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
            : message_(exception_name + ": " + msg)
        {
            count_++;
        }

        virtual const char *what() const throw();

        static int GetCount();

    private:
        std::string message_;
        inline static int count_ = 0;
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

    /**
     * This exception will be thrown when specified stream is invalid.
     *
     * For example, before processing statement, SetInput() should be called,
     * or this exception will be thrown.
     */
    class InvalidStreamException : public BaseException
    {
    public:
        InvalidStreamException(std::string msg) : BaseException("Invalid Stream", msg) {}
    };

    /**
     * This exception will be thrown when statement contains any illegal operation.
     *
     * For example, if statement tries to modify value of eithor pi or e in symbol table,
     * this exception will be thrown.
     */
    class IllegalOperationException : public BaseException
    {
    public:
        IllegalOperationException(std::string msg) : BaseException("Invalid Operation", msg) {}
    };

    /**
     * This exception will be thrown when specified file cannot be open.
     */
    class FileIOException : public BaseException
    {
    public:
        FileIOException(std::string msg) : BaseException("File IO Error", msg) {}
    };

    /**
     * This exception will be thrown when symbol required is unknown.
     */
    class UnknownSymbolException : public BaseException
    {
    public:
        UnknownSymbolException(std::string msg) : BaseException("Unknown Symbol Error", msg) {}
    };
} // namespace error

#endif
