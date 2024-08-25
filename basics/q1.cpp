#include <iostream>

using namespace std;

void print_to_terminal(string keyword)
{
    cout << keyword << "\n";
}

void read_and_printout_number()
{
    cout << "Enter Any Number\n";
    int user_number;
    cin >> user_number;

    cout << "\n\nNumber Entered By User is " << user_number << "\n";
}

void print_ASCII_value_char(char k)
{
    cout << int(k) << "\n";
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void size_of()
{
    cout << sizeof(int) << " Bytes\n";
    cout << sizeof(double) << " Bytes\n";
    cout << sizeof(char) << " Bytes\n";
    cout << sizeof("this") << " Bytes\n";
}

string check_odd_even(int number)
{
    string result;
    (number % 2 == 0) ? result = "Even" : result = "Odd";
    return result;
}

bool isPalindrome(string text)
{
    if (text.length() < 2)
    {
        return true;
    }
    else
    {
        if (text[0] == text[text.length() - 1])
        {
            return isPalindrome(text.substr(1, text.length() - 2));
        }
        else
        {
            return false;
        }
    }
}
int main()
{
    // print_to_terminal("this");
    // read_and_printout_number();
    // print_ASCII_value_char('A');

    // int a = 2;
    // int b = 3;

    // cout << "Before Swap: A= " << a << " B= " << b << "\n";
    // swap(&a, &b);
    // cout << "After Swap:  A= " << a << " B= " << b << "\n";

    // size_of();
    // cout << check_odd_even(11) << "\n";
    // cout << check_odd_even(12) << "\n";
    // cout << check_odd_even(15) << "\n";

    cout << isPalindrome("") << "\n";
    return 0;
}