#include <iostream>

void print_pattern(int number_rows)
{
    int number_alphas = 26;
    int conversion_factor = 32;
    int i, j, k;
    char a;
    bool uppercase = true;
    i = 0;
    k = 0;
    while (i < number_rows)
    {
        j = 0;
        while (j <= i)
        {
            a = 'a' + (k % number_alphas);
            if (uppercase)
            {
                a = a - conversion_factor;
            }

            printf("%c ", a);
            uppercase = !uppercase;
            j++;
            k++;
        }

        printf("\n");
        i++;
    }
}

int main()
{
    print_pattern(10);
    return 1;
}