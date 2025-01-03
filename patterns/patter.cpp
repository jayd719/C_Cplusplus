#include <iostream>
// #include<stdio.h>
#include <string>
using namespace std;

void intiliaze_letter(char letters[])
{
    for (int i = 0; i < 26; i++)
    {
        letters[i] = 'a' + i;
    }
}
void pattern(int n)
{
    int i, j, k;
    char letters[26];
    bool capital;
    char letter;

    intiliaze_letter(letters);
    k = 0;
    capital = true;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j < i; j++)
        {
            k = k % sizeof(letters);

            letter = letters[k];
            if (capital)
            {
                letter = letter - 32;
            }
            capital = !capital;
            k++;
            printf("%c ", letter);
        }
        printf("\n");
    }
}

int main()
{
    2 > 1 ? cout << "this\n" : cout << "that\n";
    return 1;
}