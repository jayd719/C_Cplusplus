#include <stdlib.h>
#include <iostream>

using namespace std;
string print_lcs(string x, string y, int m, int n, int t[][])
{
    int i, j;
    i = m;
    j = n;

    string s = "";
    while (i > 0 & j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            s.push_back(x[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (t[i][j - 1] > t[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    return s;
}

int longest_common_subs_string(string x, string y, int m, int n)
{
    int table[m + 1][n + 1];

    // intlialize the mem tratick
    int i, j;
    int maxlength;
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
                table[i][j] = 1 + table[i - 1][j - 1];
                maxlength = max(maxlength, table[i][j]);
            }
            else
            {
                table[i][j] = 0;
            }
        }
    }

    printf("%s\n", print_lcs(x, y, m, n, table));
    return maxlength;
}

int main()
{
    string x = "abdcg";
    int m = x.length();
    string y = "abdckhdi";
    int n = y.length();

    printf("Longest Common Sub Sequence: %d\n", longest_common_subs_string(x, y, m, n));
}