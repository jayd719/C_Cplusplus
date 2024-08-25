#include "bubbleSort.c++"

int main(){
    int array[] = {12,10,20,12,2,1,30};
    cout << array;
    bubble_sort(array,sizeof(array)/sizeof(array[0]));
    
    return 0;
}