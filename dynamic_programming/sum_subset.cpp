#include <iostream>
#include <stdlib.h>




bool sum_subset_mem(int arr[],int n ,int target_sum){
    
}

bool sum_subset_recursive(int arr[], int n, int target_sum)
{

    // handle base cases
    // if there are no elements in array to check.
    if (n == 0)
    {
        return false;
    }

    // if the target sum is zero, yes empty set can get the sum zero.
    if (target_sum == 0)
    {
        return true;
    }

    if (arr[n - 1] <= target_sum)
    {
        return sum_subset_recursive(arr, n - 1, target_sum - arr[n - 1]) || sum_subset_recursive(arr, n - 1, target_sum);
    }

    return sum_subset_recursive(arr, n - 1, target_sum);
}

bool sum_subset(int arr[], int n, int target_sum)
{
    // create a 2D matrix for storing results of boolean type

    bool t[n + 1][target_sum + 1];

    // initialze the matrix
    int i, j;
    for (i = 0; i <= n; i++)
    {
        t[i][0] = true;
    }

    // fill rest of the matrix with using bottom up approach.
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= target_sum; j++)
        {

            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][target_sum];
}

bool sum_subset_recursive()
{
    return true;
}
int main()
{
    printf("Sum Subset Problem\n");

    int arr[] = {2, 3, 7, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target_sum = 11;


    printf("Target Sum is present in given array(Using Simple Recursion): %d\n", sum_subset(arr, n, target_sum));
    printf("Target Sum is present in given array(Using Top Down Approach): %d\n", sum_subset(arr, n, target_sum));

    return 0;
}