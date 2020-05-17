/**
 * Experiment 2
 * Problem 3
 * 
 * Author: Robotxm
 * Date: 2020-04-22
 */

#include <iostream>
#include <cstdarg>
#include <iomanip>

using namespace std;

const int BUFFER_LENGTH = 16;

/**
 * Print uint32
 * 
 * @param n Unsigned integer to be printed
 * @param min_width Minimum with of output string
 * @param leading Leading character used to fill
 */
void PrintNumber(unsigned int n, int min_width, char leading)
{
    string buffer = to_string(n);
    min_width -= buffer.length();
    while ((min_width--) >= 0)
    {
        cout << leading;
    }

    cout << buffer;
}

/**
 * Print int32 using specific base
 * 
 * @param n Unsigned integer to be printed
 * @param min_width Minimum with of output string
 * @param leading Leading character used to fill
 */
void PrintNumber(int n, int min_width, char leading, int base)
{
    char buffer[BUFFER_LENGTH];
    itoa(n, buffer, base);
    min_width -= strlen(buffer);
    while ((min_width--) >= 0)
    {
        cout << leading;
    }

    cout << buffer;
}

/**
 * Print message containing placeholders
 * 
 * @param format A string contatining description of format
 */
void Error(const char *format, ...)
{
    va_list parg;
    va_start(parg, format);
    for (; *format != '\0'; format++)
    {
        // Check if format placeholder
        if (*format != '%')
        {
            cout << *format;
            continue;
        }
        format++;

        // Process leading character
        int min_width = 0;
        char leading = ' ';
        if (*format == '0')
        {
            leading = '0';
            format++;
        }
        while (isdigit(*format))
        {
            min_width *= 10;
            min_width += *format - '0';
            format++;
        }

        // Process placeholder and check format
        switch (*format)
        {
        case 'd': // Decimal integer
            PrintNumber(va_arg(parg, int), min_width, leading, 10);
            break;
        case 'o': // Octal integer
            PrintNumber(va_arg(parg, int), min_width, leading, 8);
            break;
        case 'x': // Hexadecimal integer
            PrintNumber(va_arg(parg, int), min_width, leading, 16);
            break;
        case 'u': // Decimal uint32
            PrintNumber(va_arg(parg, unsigned), min_width, leading);
            break;
        case 'c': // Character
            if (min_width > 1)
            {
                for (int i = 0; i < min_width - 1; i++)
                    cout << ' ';
            }
            cout << (char)va_arg(parg, int);
            break;
        case 's': // String
        {
            char *s = va_arg(parg, char *);
            if (strlen(s) < min_width)
            {
                for (int i = 0; i < min_width - strlen(s); i++)
                    cout << ' ';
            }
            cout << s;
            break;
        }
        case 'f': // Float and double. Do as printf does: consider both float and double as double
        {
            ios_base::fmtflags f(cout.flags());                       // Store current flags
            cout << fixed << setprecision(6) << va_arg(parg, double); // Print double with precision as printf does
            cout.flags(f);                                            // Restore flags
            break;
        }
        case '%': // Escape %
            cout << '%';
            break;
        }
    }
    va_end(parg);
}

int main()
{
    Error("float number test: %f", 0.5);

    return 0;
}