#include <iostream>
#include <stdlib.h>

int count_subsets_tab(int arr[], int n, int target)
{
    int t[n + 1][target+1];
    int i, j;

   
    for (i = 0; i <= n; i++)
    {
        t[i][0] = 1;
    }
     // intialize the matrix.
    for (j = 1; j <= target; j++)
    {
        t[0][j] = 0;
    }

    // compute resest of matrix here.

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= target; j++)
        {

            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][target];
}

int count_number_of_subsets_recursive(int arr[], int n, int target)
{
    // base case
    if (target == 0)
    {
        return 1;
    }

    if (n == 0)
    {
        return 0;
    }

    if (arr[n - 1] <= target)
    {
        return count_number_of_subsets_recursive(arr, n - 1, target - arr[n - 1]) + count_number_of_subsets_recursive(arr, n - 1, target);
    }
    else
    {
        return count_number_of_subsets_recursive(arr, n - 1, target);
    }
}

int main()
{
    printf("Count Number of subsets\n");

    int arr[] = {1, 2, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 6;
    printf("Number of subsets using recusrive: %d\n", count_number_of_subsets_recursive(arr, n, target));
    printf("Number of subsets using Top Down: %d\n", count_subsets_tab(arr, n, target));
}