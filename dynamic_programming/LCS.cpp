#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int LCS(string x, string y, int m, int n)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (x[m - 1] == y[n - 1])
    {
        return 1 + LCS(x, y, m - 1, n - 1);
    }
    else
    {
        return max(LCS(x, y, m, n - 1), LCS(x, y, m - 1, n));
    }
    return 1;
}

int main()
{

    string x = "abdcg";
    int m = x.length();
    string y = "abkhi";
    int n = y.length();

    printf("Longest Subsequence: %d\n", LCS(x, y, m, n));
}