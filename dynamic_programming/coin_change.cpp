#include <iostream>
#include <stdlib.h>
using namespace std;

int maximum_number_of_ways(int coins[], int target, int n)
{
    int table[n + 1][target + 1];
    // intilize the mem matrix.
    int i, j;
    for (i = 0; i <= n; i++)
    {
        table[i][0] = 1;
    }
    for (j = 1; j <= target; j++)
    {
        table[0][j] = 0;
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= target; j++)
        {
            if (coins[i - 1] <= j)
            {
                table[i][j] = table[i][j - coins[i - 1]] + table[i - 1][j];
            }
            else
            {
                table[i][j] = table[i - 1][j];
            }
        }
    }
    return table[n][target];
}

int minimum_number_of_coins(int coins[], int target, int n)
{
    int t[n + 1][target + 1];
    // intialiazeation
    int i, j;
    for (i = 0; i <= n; i++)
    {
        t[i][0] = 0;
    }
    for (j = 0; j <= target; j++)
    {
        t[0][j] = INT16_MAX - 1;
    }

    for (j = 1; j <= target; j++)
    {
        if (t[1][j] % coins[0] == 0)
        {
            t[1][j] = t[1][j] / coins[0];
        }
        else
        {
            t[1][j] = INT16_MAX - 1;
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= target; j++)
        {
            if (coins[i - 1] <= j)
            {
                t[i][j] = min(t[i][j - coins[i - 1]]+1, t[i-1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    //
    return t[n][target];
}

int main()
{

    int coins[] = {2, 5, 3, 6};
    int target_sum = 10;
    int n = sizeof(coins) / sizeof(coins[0]);

    printf("Answer: %d\n", maximum_number_of_ways(coins, target_sum, n));
    printf("Answer: %d\n", minimum_number_of_coins(coins, target_sum, n));
}