/**
 * Experiment 1
 * Problem 2
 * 
 * Author: Robotxm
 * Date: 2020-04-06
 */

#include <iostream>
#include <regex>
#include <set>
#include <cmath>

using namespace std;

/**
 * Replace all specified string.
 * Input string will be modified.
 * 
 * @param str String to be processed
 * @param src String to be replaced
 * @param dst src will be replaced with dst
 */
void ReplaceAll(string &str, const string &src, const string &dst)
{
    size_t start_pos = 0;
    while ((start_pos = str.find(src, start_pos)) != string::npos)
    {
        str.replace(start_pos, src.length(), dst);
        start_pos += dst.length();
    }
}

/**
 * Convert hexadecimal- or octal-string to char.
 * 
 * @param s String to be converted
 * @return A char. If conversion is failed, return '\0'
 */
char ToChar(string s)
{
    char c = 0;
    int base;
    if (s.find("\\x") != s.npos) // Hex
    {
        ReplaceAll(s, "\\x", "");
        base = 16;
    }
    else if (s.find("\\0") != s.npos) // Oct
    {
        ReplaceAll(s, "\\0", "");
        base = 8;
    }
    else // Invalid base
        return 0;

    for (int i = 0; i < s.length(); i++)
        c += (s[i] - '0') * pow(base, s.length() - i - 1);

    return c;
}

/**
 * Convert all non-decimal characters to decimal characters.
 * Only support hexadecimal and octal.
 * 
 * @param s A C-style string to be processed
 * @param base Base to be used in process
 * @return A new C++-style string 
 */
string PreProcess(const char *s, int base)
{
    // Process hexadecimal character
    regex reg(base == 16 ? "\\\\x[0-9A-Za-z]{2}" : "\\\\0[0-9]{2}");
    smatch m;
    string original_str(s);
    bool ret = regex_search(original_str, m, reg);
    auto pos = original_str.cbegin();
    set<string> candidate_list;
    for (; regex_search(pos, original_str.cend(), m, reg); pos = m.suffix().first)
        candidate_list.insert(m.str());
    for (auto substring : candidate_list)
        ReplaceAll(original_str, substring, string(1, ToChar(substring)));

    return original_str;
}

/**
 * Convert string to int32
 * 
 * @param s A C-style string to be converted
 * @return Return a number (stored as int32) converted from string given.
 *         Return INT_MAX or INT_MIN if the number is larger than INT_MAX or smaller INT_MIN.
 *         Return 0 if string given is illegal.
 */
int atoi(const char *s)
{
    // Before converting from string to int32,
    // use regular expression to process any character such as '\x31' (hex) or '\061' (oct)
    const char *processed_string = PreProcess(PreProcess(s, 16).c_str(), 8).c_str();

    // Store current character
    char c;
    // Skip all whitespaces
    do
    {
        c = *processed_string++;
    } while (isspace(c));
    // Check if negative
    bool is_negative = false;
    if (c == '-')
    {
        is_negative = true;
        c = *processed_string++; // Move to the 'real' number part
    }
    else if (c == '+') // Skip plus
        c = *processed_string++;

    // Check base
    int base = 0;
    if (c == '0' && (tolower(*processed_string) == 'x')) // Hex
    {
        c = processed_string[1];
        base = 16;
        processed_string += 2;
    }
    else
        base = (c == '0' ? 8 : 10); // If c is '0', the string given will be parsed as an octal number

    // max_result and max_result_remainder are used to check if number overflows
    // The max_result is the limit set to the maximum or minimum (depends on number given) value of int32
    int max_result = is_negative ? -(unsigned int)INT_MIN : INT_MAX;
    // The last digit of limit value
    int max_result_remainder = max_result % (unsigned int)base;
    // Remove the last digit from max_result for future usage
    max_result /= (unsigned int)base;

    // Start to parse number
    int result = 0;
    bool is_overflowed = false; // It is negative when overflows
    do
    {
        // Process each digit
        if (isdigit(c))
            c -= '0';
        else if (isalpha(c)) // Find letter which represents number, in this problem it is used for hex
            c -= isupper(c) ? 'A' - 10 : 'a' - 10;
        else // Illegal character
            break;
        if (c >= base) // Illegal digit
            break;

        // Check overflow
        // If current result is larger than limit of max_result,
        // or current result equals to max_result but the last digit which will be appended to current result is larger than max_result_remainder,
        // the result is considered as an overflowed number
        // And, if overflow occurs when base is not 16, the conversion will be interrupted
        if ((is_overflowed || result > max_result || (result == max_result && c > max_result_remainder)))
            is_overflowed = true;
        else
        {
            is_overflowed = false;
            result *= base;
            result += c;
        }
    } while (c = *processed_string++);

    // Result to return
    // If overflow occurs, return the maximum or minimum (depends on number given) value of int32
    if (is_overflowed)
        return (is_negative ? INT_MIN : INT_MAX);
    else if (is_negative) // Negative
        return -result;
    else // Positive
        return result;
}

int main()
{
    string s;
    getline(cin, s); // Use getline to process input which contains space
    cout << atoi(s.c_str()) << endl;

    return 0;
}