#include <iostream>
#include <stdlib.h>

using namespace std;

int cal_fib_memoization(int n, int array_[])
{
    if (n <= 1)
    {
        return n;
    }
    if (array_[n] != -1)
    {
        return array_[n];
    }

    array_[n] = cal_fib_memoization(n - 2, array_) + cal_fib_memoization(n - 1, array_);
    return array_[n];
}

int cal_fib_tabulation_method(int n)
{
    int tab[n];
    if (n <= 1)
    {
        return n;
    }

    tab[0] = 0;
    tab[1] = 1;

    int l;
    for (l = 2; l <= n; l++)
    {
        tab[l] = tab[l - 2] + tab[l - 1];
    }
    return tab[n];
}

int cal_fib(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return cal_fib(n - 2) + cal_fib(n - 1);
}

int main()
{
    int k = 8;
    printf("%dth Fib number is: %d\n", k, cal_fib(k));
    printf("%dth Fib using tabulation method is: %d\n", k, cal_fib_tabulation_method(k));
    int array_[k+1];
    for (int i = 0; i <= k; i++)
    {
        array_[i] = -1;
    }
    printf("%dth Fib using mem method is: %d\n", k, cal_fib_memoization(k, array_));
}