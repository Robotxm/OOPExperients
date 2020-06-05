/**
 * Experiment 5
 * Problem 2
 *
 * Author: Robotxm
 * Date: 2020-05-26
 * Description: Declaration of String, Srep and Cref
 */

#ifndef _STRING_HPP
#define _STRING_HPP

#include <iostream>

using std::istream;
using std::ostream;

class String
{
private:
    struct Srep
    {
    public:
        char *string;
        int size;
        int count;

        Srep(int new_size, const char *p);
        ~Srep() { delete[] string; }

        Srep *Copy();
        void Assign(int new_size, const char *p);

    private:
        // Prevent copying
        Srep(const Srep &);
        Srep &operator=(const Srep &);
    } * rep_;

    class Cref
    {
    private:
        friend class String;
        String &string_;
        int index_;
        Cref(String &string, int index) : string_(string), index_(index) {}
        Cref(const Cref &ref) : string_(ref.string_), index_(ref.index_) {}

    public:
        operator char() const
        {
            string_.Check(index_);
            return string_.CharAt(index_);
        }

        void operator=(char c) { string_.Write(index_, c); }
    };

public:
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

    String();
    String(const char *);
    String(const String &);
    ~String();

    /**
     * Return length of the current String
     */
    int GetSize() const;

    /**
     * Check if index i of current String valid 
     */
    void Check(int i) const;

    /**
     * Return index i of current String 
     */
    char CharAt(int i);

    /**
     * Replace character at index i of current String with specified character
     */
    void Write(int i, char c);

    /**
     * Return C-style string of current String 
     */
    const char *GetCString() { return rep_->string; }

    String &operator+=(const String &x);
    String &operator+=(const char *x);
    String &operator=(const String &);
    String &operator=(const char *);
    Cref operator[](int i);
    char operator[](int i) const;
    friend ostream &operator<<(ostream &, const String &);
    friend istream &operator>>(istream &, String &);
    friend bool operator==(const String &x, const char *s);
    friend bool operator==(const String &x, const String &y);
    friend bool operator!=(const String &x, const char *s);
    friend bool operator!=(const String &x, const String &y);
};

#endif
