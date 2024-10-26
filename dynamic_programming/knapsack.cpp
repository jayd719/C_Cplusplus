#include <iostream>
#include <stdlib.h>
using namespace std;

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
    int n = 4;
    int w[] = {10, 30, 50, 40};
    int v[] = {4, 6, 2, 3};
    int m = 2;

    printf("%d\n", knapsack_rec(w, v, m, n));

    return 0;
}