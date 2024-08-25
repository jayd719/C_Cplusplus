#include <iostream>

int main()
{

    std::cout << "What is the temperature?\n";
    int temperature;
    std::cin >> temperature;

    (temperature >= 0 && temperature <= 30) ? std::cout << "Temperatur is good" : std::cout << "Temperature is bad";

    return 0;
}