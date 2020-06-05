/**
 * Experiment 5
 * Problem 5
 *
 * Author: Robotxm
 * Date: 2020-05-27
 * Description: Definition of Ptr_to_T
 */

#ifndef _PTR_TO_T_HPP
#define _PTR_TO_T_HPP

#include <exception>
#include <string>

template <class T>
class Ptr_to_T
{
public:
    Ptr_to_T(T *ptr, int length, int first_index = 0);

    Ptr_to_T &operator=(const Ptr_to_T &ptr);
    Ptr_to_T &operator++();
    Ptr_to_T operator++(int);
    Ptr_to_T &operator--();
    Ptr_to_T operator--(int);
    T &operator*() const;
    T *operator->() const;

    /**
     * This exception will be thrown when index specified is out of bounds
     */
    class IndexOutOfRangeException : public std::exception
    {
    public:
        IndexOutOfRangeException(std::string msg) : message_(msg) {}

        virtual const char *what() const throw() { return message_.c_str(); }

    private:
        std::string message_;
    };

    /**
     * This exception will be thrown when pointer is null
     */
    class NullPointerException : public std::exception
    {
    public:
        NullPointerException(std::string msg) : message_(msg) {}

        virtual const char *what() const throw() { return message_.c_str(); }

    private:
        std::string message_;
    };

    /**
     * This exception will be thrown when non-null argument specified is null
     */
    class ArgumentNullException : public std::exception
    {
    public:
        ArgumentNullException(std::string msg) : message_(msg) {}

        virtual const char *what() const throw() { return message_.c_str(); }

    private:
        std::string message_;
    };

    /**
     * This exception will be thrown when argument expected is illegal
     */
    class ArgumentException : public std::exception
    {
    public:
        ArgumentException(std::string msg) : message_(msg) {}

        virtual const char *what() const throw() { return message_.c_str(); }

    private:
        std::string message_;
    };

private:
    T *ptr_;
    int length_;
    int first_index_;
    int current_index_;
};

template <class T>
Ptr_to_T<T>::Ptr_to_T(T *ptr, int length, int first_index)
{
    if (!ptr)
        throw ArgumentNullException("Cannot initialize with null pointer");
    if (length < 0 || first_index < 0)
        throw ArgumentException("Invalid parameter");

    ptr_ = ptr;
    length_ = length;
    first_index_ = first_index;
    current_index_ = 0;
}

template <class T>
Ptr_to_T<T> &Ptr_to_T<T>::operator=(const Ptr_to_T<T> &ptr)
{
    ptr_ = ptr.ptr_;
    length_ = ptr.length_;
    first_index_ = ptr.first_index_;
    current_index_ = ptr.current_index_;
    return *this;
}

template <class T>
Ptr_to_T<T> &Ptr_to_T<T>::operator++()
{
    ptr_++;
    current_index_++;
    return *this;
}

template <class T>
Ptr_to_T<T> Ptr_to_T<T>::operator++(int)
{
    Ptr_to_T<T> copy = *this;
    ++*this;
    return copy;
}

template <class T>
Ptr_to_T<T> &Ptr_to_T<T>::operator--()
{
    ptr_--;
    current_index_--;
    return *this;
}

template <class T>
Ptr_to_T<T> Ptr_to_T<T>::operator--(int)
{
    Ptr_to_T<T> copy = *this;
    --*this;
    return copy;
}

template <class T>
T &Ptr_to_T<T>::operator*() const
{
    if (!ptr_)
        throw NullPointerException("Pointer is null");
    if (current_index_ < 0 || current_index_ >= length_)
        throw IndexOutOfRangeException("Index was outside the bounds of the array.");
    return *ptr_;
}

template <class T>
T *Ptr_to_T<T>::operator->() const
{
    if (!ptr_)
        throw NullPointerException("Pointer is null");
    if (current_index_ < 0 || current_index_ >= length_)
        throw IndexOutOfRangeException("Index was outside the bounds of the array.");
    return ptr_;
}

#endif
