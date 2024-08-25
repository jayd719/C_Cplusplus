#include <iostream>
#include "swap.c++"
using namespace std;

void bubble_sort(int array[], int size)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size;j++)
        {
            if (array[i] >= array[j])
            {
                swap(array[i], array[j]);
            }
        }
    }
}