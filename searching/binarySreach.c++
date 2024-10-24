#include <iostream>
#include <stdlib.h>
using namespace std;

bool binary_search(int array[], int key, int front, int rear)
{
    int mid = (front + rear) / 2;
    if (front > rear)
    {
        return false;
    }

    if (key > *(array + mid))
    {
        return binary_search(array, key, (mid + 1), rear);
    }
    else if (key < *(array + mid))
    {
        return binary_search(array, key, front, (mid - 1));
    }
    else
    {
        return true;
    }
}

int main()
{
    system("clear");
    int testArray[] = {1, 2, 3, 4, 5, 6, 7};
    int arraySize = sizeof(testArray) / sizeof(testArray[0]);


    int sreachFor = 13;
    

    binary_search(testArray, sreachFor, 0, arraySize - 1)? cout<<"Found\n":cout<<"Not Found\n";

    return 0;
}