#include <iostream>
#include <stdlib.h>
using namespace std;

int rod_cutting(int price[], int n)
{
    int table[n + 1][n + 1];
    // intilzie
    int lenght[n + 1];
    int i, j;

    for (i = 0; i <= n; i++)
    {
        lenght[i] = i + 1;
    }

    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                table[i][j] = 0;
            }
        }
    }

    // fill rest of the table
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (price[i - 1] <= j)
            {
                table[i][j] = max(price[i - 1] + table[i][j - lenght[i - 1]], table[i - 1][j]);
            }
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }

    return table[n][n];
}

int main()
{
    int lenght = 8;
    int price[] = {3, 5, 8, 9, 10, 17};
    int n = sizeof(price) / sizeof(price[0]);

    printf("Maximum Value: %d\n", rod_cutting(price, n));
}