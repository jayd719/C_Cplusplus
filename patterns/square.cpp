#include <iostream>
using namespace std;

void print_square_pattern(int n)
{
    int i, j;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

void print_pattern_2(int n)
{

    int i, j, k;
    k = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << k << " ";
            k++;
        }
        cout << "\n";
    }
}

void print_star_triangle(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << "\n";
    }
}

void print_number_triangle(int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 0; j < i; j++)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}

void print_char_triangle(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= i; j++)
        {
            cout << char('A' + i) << " ";
        }
        cout << "\n";
    }
}

void increment_triangle(int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

void print_reverse_triangle(int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = i; j > 0; j--)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}

void print_inverted_triangle(int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j < i; j++)
        {
            cout << "  ";
        }

        for (j = i; j <= n; j++)
        {
            cout << i << " ";
        }

        cout << "\n";
    }
}

int main()
{
    cout << "PRINT SQUARE PATTERN\n";
    print_square_pattern(4);
    cout << "PRINT PATTERN 2\n";
    print_pattern_2(3);
    cout << "PRINT STAR TRIANGLE\n";
    print_star_triangle(4);
    cout << "PRINT NUMBER TRIANGLE\n";
    print_number_triangle(4);
    cout << "PRINT CHAR TRIANGLE\n";
    print_char_triangle(5);
    cout << "PRINT INCREMENT TRIANGLE\n";
    increment_triangle(4);
    cout << "PRINT REVERSE TRIANGLE\n";
    print_reverse_triangle(4);
    cout << "PRINT INVERTED TRIANGLE\n";
    print_inverted_triangle(4);
    return 1;
}