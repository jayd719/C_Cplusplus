#include <stdio.h>
#include <cmath>
#include <climits>

using namespace std;

/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x
causes the value to go outside the signed 32-bitinteger range [-231, 231 - 1],
then return 0.
*/
int reverse(int inputInteger)
{
    int reversedNumber = 0;
    while (inputInteger != 0)
    {

        if (reversedNumber > INT32_MAX / 10 || reversedNumber < INT32_MIN / 10)
            return 0;

        int mod = inputInteger % 10;
        reversedNumber = reversedNumber * 10 + mod;
        inputInteger /= 10;
    }

    return reversedNumber;
}
int main()
{
    // Test cases
    printf("Reverse of 123: %d\n", reverse(123));                 // Typical positive number
    printf("Reverse of -123: %d\n", reverse(-123));               // Typical negative number
    printf("Reverse of 0: %d\n", reverse(0));                     // Edge case: zero
    printf("Reverse of 120: %d\n", reverse(120));                 // Number with trailing zero
    printf("Reverse of 5: %d\n", reverse(5));                     // Single-digit number
    printf("Reverse of INT_MAX: %d\n", reverse(INT32_MAX));       // Edge case: maximum 32-bit integer
    printf("Reverse of INT_MIN: %d\n", reverse(INT32_MIN));       // Edge case: minimum 32-bit integer
    printf("Reverse of 1534236469: %d\n", reverse(1534236469));   // Number that reverses to overflow
    printf("Reverse of -2147483412: %d\n", reverse(-2147483412)); // Negative number close to INT_MIN

    return 0;
}
