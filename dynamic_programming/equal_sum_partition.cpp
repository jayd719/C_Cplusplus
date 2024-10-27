#include <iostream>
#include <stdlib.h>

// such a partition can only exist if sum of the given array is even.

bool sum_subset(int arr[], int n, int target_sum)
{

    int t[n + 1][target_sum + 1];
    // intilize this prev mat.
    int i, j;
    for (i = 0; i <= n; i++)
    {
        t[i][0] = true;
    }

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

bool equal_sum_partition(int arr[], int n)
{
    // check for sum of the given array;
    int sum_of_array = 0;
    for (int i = 0; i < n; i++)
    {
        sum_of_array += arr[i];
    }

    if (sum_of_array % 2 != 0)
    {
        return false;
    }

    return sum_subset(arr, n, sum_of_array / 2);
}

int main()
{
    printf("Equal Sum Partition\n");

    int arr[] = {1, 3, 5, 2, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Equal Partition Exists: %d\n", equal_sum_partition(arr, n));
}