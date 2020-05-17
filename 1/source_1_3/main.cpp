/**
 * Experiment 1
 * Problem 3
 * 
 * Author: Robotxm
 * Date: 2020-04-06
 */

#include <iostream>
#include <stack>

using namespace std;

/**
 * Convert decimal int32 to string
 * 
 * The result will be stored in array (a.k.a. C-style string) given.
 * Negative number will be output as in complement representation if base is not 10.
 * 
 * @param i Integer to be converted
 * @param b Destination string
 * @param base Base used in conversion. Default value is 10
 * 
 * @return Pointer to destination string
 */
char *itoa(int i, char b[], int base = 10)
{
    // If base is invalid, return original string
    if (base < 0)
        return b;

    // Because it is required to keep the function signature,
    // convert input number to uint32 so that result is in complement representation when it is negative and base is not 10
    // In addition, it is needed to convert input number to positive number when it is negative,
    // so the result will be correct if base is 10. Symbol will be added finally
    unsigned int t;
    if (i > 0)
        t = i;
    else
    {
        if (base == 10)
            t = -i;
        else
            t = i;
    }

    // Store the head address of b
    char *r = b;
    // Use stack to store every character of digit
    stack<char> chars;

    // Start to parse number
    do
    {
        int digit = t % base;
        if (digit < 10)
            chars.push(digit + '0');
        else
            chars.push(digit - 10 + 'A');
    } while ((t /= base) > 0);
    // Push '-' if the number is negative and base is 10
    if (i < 0 && base == 10)
        chars.push('-');
    else if (base == 16) // Add '0' and 'x' before hexadecimal number
    {
        chars.push('x');
        chars.push('0');
    }
    else if (base == 8) // Add '0' before octal number
        chars.push('0');

    // Output characters to array
    while (!chars.empty())
    {
        *b = chars.top();
        chars.pop();
        *b++;
    }
    // Make array a real string
    *b = '\0';

    return r;
}

int main()
{
    int number;
    cin >> number;
    char oct[100], dec[100], hex[100];
    // Octal
    cout << "Octal-string: " << itoa(number, oct, 8) << endl;
    // Decimal
    cout << "Decimal-string: " << itoa(number, dec) << endl;
    // Hexadecimal
    cout << "Hexadecimal-string: " << itoa(number, hex, 16) << endl;

    return 0;
}