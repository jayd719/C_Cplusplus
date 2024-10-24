#include <iostream>
#include <stdlib.h>

using namespace std;

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
}