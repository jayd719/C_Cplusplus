#include <iostream>

int main()
{

    std::cout << "This is begining of the program\n\n";

    // ternary operator ?
    // condition ? expression1 : expression2

    // Check if number is Odd Or Even Using Ternary Operator

    // condition ? expression1 : expression2

    int number = 10;
    number % 2 == 0 ? std::cout << "Even\n" : std::cout << "Odd\n";

    bool isValid= true;
    isValid ? std ::cout << "isValid\n" : std ::cout << "Not Valid\n";



    return 0;
}