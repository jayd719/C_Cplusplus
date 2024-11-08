#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
int static t[1001][1001];

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
}

int LCS_mem(string x, string y, int m, int n)
{
    if (n == 0 || m == 0)
    {
        return 0;
    }

    if (t[m][n] != -1)
    {
        return t[m][n];
    }

    if (x[m - 1] == y[n - 1])
    {
        t[m][n] = 1 + LCS(x, y, m - 1, n - 1);
        return t[m][n];
    }
    else
    {
        t[m][n] = max(LCS(x, y, m, n - 1), LCS(x, y, m - 1, n));
        return t[m][n];
    }
}

int LCS_top_down(string x, string y, int m, int n)
{
    int table[m + 1][n + 1];
    // intialze table
    int i, j;
    for (i = 0; i <= m; i++)
    {
        table[i][0] = 0;
    }
    for (j = 0; j <= n; j++)
    {
        table[0][j] = 0;
    }

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            else
            {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }

    return table[m][n];
}

int main()
{
    memset(t, -1, sizeof(t));
    string x = "abdcg";
    int m = x.length();
    string y = "abkhdi";
    int n = y.length();

    printf("Longest Subsequence: %d\n", LCS(x, y, m, n));
    printf("Longest Subsequence Rec: %d\n", LCS_mem(x, y, m, n));
    printf("Longest Subsequence Top Down: %d\n", LCS_top_down(x, y, m, n));
}