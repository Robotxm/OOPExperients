/**
 * Experiment 5
 * Problem 2
 *
 * Author: Robotxm
 * Date: 2020-05-26
 * Description: Implementation of String, Srep and Cref
 */

#include "string.hpp"

String::String()
{
    rep_ = new Srep(0, "");
}

String::String(const char *s)
{
    rep_ = new Srep(strlen(s), s);
}

String::String(const String &s)
{
    s.rep_->count++;
    rep_ = s.rep_;
}

String::~String()
{
    if (--(rep_->count) == 0)
        delete rep_;
}

int String::GetSize() const
{
    return rep_->size;
}

void String::Check(int i) const
{
    if (i < 0 || i >= rep_->size)
        throw IndexOutOfRangeException("Index was outside the bounds of the array.");
}

char String::CharAt(int i)
{
    return rep_->string[i];
}

void String::Write(int i, char c)
{
    rep_ = rep_->Copy();
    rep_->string[i] = c;
}

String &String::operator+=(const String &x)
{
    return *this += x.rep_->string;
}

String &String::operator+=(const char *x)
{
    int size = rep_->size + strlen(x);
    char *s = new char[size + 1];
    strcpy(s, rep_->string);
    strcat(s, x);
    rep_->Assign(size, s);
    delete[] s;
    return *this;
}

String &String::operator=(const String &s)
{
    s.rep_->count++;
    if (--(rep_->count) == 0)
        delete rep_;
    rep_ = s.rep_;
    return *this;
}

String &String::operator=(const char *s)
{
    if (rep_->count == 1)
        rep_->Assign(strlen(s), s);
    else
    {
        rep_->count--;
        rep_ = new Srep(strlen(s), s);
    }
    return *this;
}

String::Cref String::operator[](int i)
{
    Check(i);
    return Cref(*this, i);
}

char String::operator[](int i) const
{
    Check(i);
    return rep_->string[i];
}

ostream &operator<<(ostream &o, const String &x)
{
    o << x.rep_->string;
    return o;
}

istream &operator>>(istream &i, String &x)
{
    char *s = new char[256];
    int n = 0;
    int size = 255;
    char ch;

    while (i && i.get(ch) && !isspace(ch))
    {
        s[n++] = ch;
        // Expand if needed
        if (n > size)
        {
            s[n] = 0;
            char *s2 = new char[size * 2 + 1];
            strcpy(s2, s);
            delete[] s;
            s = s2;
            size *= 2;
        }
    }
    s[n] = 0;

    x = String(s);
    delete[] s;
    return i;
}

bool operator==(const String &x, const char *s)
{
    return strcmp(x.rep_->string, s) == 0;
}

bool operator==(const String &x, const String &y)
{
    return strcmp(x.rep_->string, y.rep_->string) == 0;
}

bool operator!=(const String &x, const char *s)
{
    return strcmp(x.rep_->string, s) != 0;
}

bool operator!=(const String &x, const String &y)
{
    return strcmp(x.rep_->string, y.rep_->string) != 0;
}

String::Srep::Srep(int new_size, const char *p)
{
    count = 1;
    size = new_size;
    string = new char[size + 1];
    strcpy(string, p);
}

String::Srep *String::Srep::Copy()
{
    if (count == 1)
        return this;
    count--;
    return new Srep(size, string);
}

void String::Srep::Assign(int new_size, const char *p)
{
    if (size != new_size)
    {
        delete[] string;
        size = new_size;
        string = new char[size + 1];
    }
    strncpy(string, p, size);
    string[size] = 0;
}
