#include <iostream>
#include <stdlib.h>
using namespace std;

int n = 4;
int w[] = {1, 3, 5, 4};
int v[] = {4, 6, 2, 3};
int m = 10;

int dp[5][11];

int knapsack_top_down(int weight[], int values[], int knapsack_weight, int n)
{
    int table[n + 1][knapsack_weight + 1];

    int i, j;

    // intinitailze the table for base case
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= knapsack_weight; j++)
        {
            if (i == j)
            {
                table[i][j] = 0;
            }
        }
    }

    //
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= knapsack_weight; j++)
        {
            if (weight[i - 1] <= j)
            {
                table[i][j] = max(weight[n - 1] + table[i - 1][j - weight[i - 1]], table[i - 1][j]);
            }else{
                table[i][j] = table[i+1][j];
            }
        }
    }

    return table[n+1][knapsack_weight+1];
}

int knapsack_mem(int weight[], int values[], int knapsack_weight, int n)
{

    // base case if no items to be added to bag and weight of bag is zero.
    if (n == 0 || knapsack_weight == 0)
    {
        return 0;
    }

    // if already calculated for this
    if (dp[n][knapsack_weight] != -1)
    {
        return dp[n][knapsack_weight];
    }

    if (weight[n - 1] <= knapsack_weight)
    {
        dp[n][knapsack_weight] = max(weight[n - 1], knapsack_mem(weight, values, knapsack_weight - weight[n - 1], n - 1));
        return dp[n][knapsack_weight];
    }
    else
    {
        dp[n][knapsack_weight] = knapsack_mem(weight, values, knapsack_weight, n - 1);
        return dp[n][knapsack_weight];
    }
}

int knapsack_rec(int weight[], int values[], int knapsack_weight, int n)
{

    // base case if no items to be added to bag and weight of bag is zero.
    if (n == 0 || knapsack_weight == 0)
    {
        return 0;
    }

    if (weight[n - 1] <= knapsack_weight)
    {
        return max(weight[n - 1], knapsack_rec(weight, values, knapsack_weight - weight[n - 1], n - 1));
    }
    else
    {
        return knapsack_rec(weight, values, knapsack_weight, n - 1);
    }
}

int main()
{

    printf("Using Simple Recursion %d\n", knapsack_rec(w, v, m, n));
    memset(dp, -1, sizeof(dp));
    printf("Using Memoiztion %d\n", knapsack_mem(w, v, m, n));
    printf("Using Top Down %d\n", knapsack_top_down(w, v, m, n));

    return 0;
}