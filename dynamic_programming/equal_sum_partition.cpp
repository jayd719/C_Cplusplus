#include <iostream>
#include <stdlib.h>

// such a partition can only exist if sum of the given array is even.

bool equal_sum_partition(int arr[], int n)
{
    // check for sum of the given array;
    int sum_of_array;
    for (int i = 0; i < n; i++)
    {
        sum_of_array += arr[i];
    }

    if (sum_of_array % 2 != 0)
    {
        return false;
    }
}

int main()
{
    printf("Equal Sum Partition\n");

    int arr[] = {1, 3, 5, 2, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
}