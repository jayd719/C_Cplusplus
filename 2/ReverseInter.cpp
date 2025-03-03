#include <stdio.h>
#include <cmath>
#include <climits>
#include <bitset>

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
// Time Complexity= O(numberOfDigitsInInteger)
// Space Complexity = O(1)

void test_int_reverse()
{
    printf("Reverse of 123: %d\n", reverse(123));                 // Typical positive number
    printf("Reverse of -123: %d\n", reverse(-123));               // Typical negative number
    printf("Reverse of 0: %d\n", reverse(0));                     // Edge case: zero
    printf("Reverse of 120: %d\n", reverse(120));                 // Number with trailing zero
    printf("Reverse of 5: %d\n", reverse(5));                     // Single-digit number
    printf("Reverse of INT_MAX: %d\n", reverse(INT32_MAX));       // Edge case: maximum 32-bit integer
    printf("Reverse of INT_MIN: %d\n", reverse(INT32_MIN));       // Edge case: minimum 32-bit integer
    printf("Reverse of 1534236469: %d\n", reverse(1534236469));   // Number that reverses to overflow
    printf("Reverse of -2147483412: %d\n", reverse(-2147483412)); // Negative number close to INT_MIN
}

/*
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in
its binary representation
*/
int bitwiseComplement(int n)
{
    // base case
    if (n == 0)
        return 1;
    int numberOfBits = log2(n) + 1;
    int mask = (1 << numberOfBits) - 1;
    return n ^ mask;
}
// Time Complexity = O(1)
// Space Complexity = O(1)

void test_bitwiseComplement()
{
    printf("bitwiseComplement(0) = %d\n", bitwiseComplement(0));       // Expected: 1
    printf("bitwiseComplement(1) = %d\n", bitwiseComplement(1));       // Expected: 0
    printf("bitwiseComplement(2) = %d\n", bitwiseComplement(2));       // Expected: 1
    printf("bitwiseComplement(5) = %d\n", bitwiseComplement(5));       // Expected: 2
    printf("bitwiseComplement(7) = %d\n", bitwiseComplement(7));       // Expected: 0
    printf("bitwiseComplement(10) = %d\n", bitwiseComplement(10));     // Expected: 5
    printf("bitwiseComplement(15) = %d\n", bitwiseComplement(15));     // Expected: 0
    printf("bitwiseComplement(16) = %d\n", bitwiseComplement(16));     // Expected: 15
    printf("bitwiseComplement(100) = %d\n", bitwiseComplement(100));   // Expected: 27
    printf("bitwiseComplement(255) = %d\n", bitwiseComplement(255));   // Expected: 0
    printf("bitwiseComplement(256) = %d\n", bitwiseComplement(256));   // Expected: 255
    printf("bitwiseComplement(1023) = %d\n", bitwiseComplement(1023)); // Expected: 0
    printf("bitwiseComplement(1024) = %d\n", bitwiseComplement(1024)); // Expected: 1023
}
bool isPowerOfTwo(int n)
{
    for (int i = 0; i <= 30; i++)
    {
        int answer = pow(2, i);
        if (answer == n)
            return true;
    }
    return false;
}

void test_isPowerOfTwo()
{
    // Test cases with formatted output
    printf("1 >> %d\n", isPowerOfTwo(1));       // Expected: 1 (2^0 = 1)
    printf("2 >> %d\n", isPowerOfTwo(2));       // Expected: 1 (2^1 = 2)
    printf("3 >> %d\n", isPowerOfTwo(3));       // Expected: 0 (not a power of two)
    printf("4 >> %d\n", isPowerOfTwo(4));       // Expected: 1 (2^2 = 4)
    printf("6 >> %d\n", isPowerOfTwo(6));       // Expected: 0 (not a power of two)
    printf("8 >> %d\n", isPowerOfTwo(8));       // Expected: 1 (2^3 = 8)
    printf("16 >> %d\n", isPowerOfTwo(16));     // Expected: 1 (2^4 = 16)
    printf("31 >> %d\n", isPowerOfTwo(31));     // Expected: 0 (not a power of two)
    printf("32 >> %d\n", isPowerOfTwo(32));     // Expected: 1 (2^5 = 32)
    printf("64 >> %d\n", isPowerOfTwo(64));     // Expected: 1 (2^6 = 64)
    printf("127 >> %d\n", isPowerOfTwo(127));   // Expected: 0 (not a power of two)
    printf("128 >> %d\n", isPowerOfTwo(128));   // Expected: 1 (2^7 = 128)
    printf("255 >> %d\n", isPowerOfTwo(255));   // Expected: 0 (not a power of two)
    printf("256 >> %d\n", isPowerOfTwo(256));   // Expected: 1 (2^8 = 256)
    printf("512 >> %d\n", isPowerOfTwo(512));   // Expected: 1 (2^9 = 512)
    printf("1024 >> %d\n", isPowerOfTwo(1024)); // Expected: 1 (2^10 = 1024)

    // Edge cases
    printf("0 >> %d\n", isPowerOfTwo(0));     // Expected: 0 (not a power of two)
    printf("-1 >> %d\n", isPowerOfTwo(-1));   // Expected: 0 (negative numbers are not powers of two)
    printf("-2 >> %d\n", isPowerOfTwo(-2));   // Expected: 0 (negative numbers are not powers of two)
    printf("-16 >> %d\n", isPowerOfTwo(-16)); // Expected: 0 (negative numbers are not powers of two)
}
int main()
{
    test_isPowerOfTwo();
    return 0;
}