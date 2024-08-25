#include <iostream>
#include <stdlib.h>

using namespace std;

class Car
{
private:
    string brand;
    string model;
    int year;

    string getFullName()
    {
        return this->brand + " " + this->model;
    }

public:
    Car(string brand, string model, int year)
    {
        this->brand = brand;
        this->model = model;
        this->year = year;
    }

    void print_details()
    {
        cout << "Name:" << this->brand << "\nModel: " << this->model << "\nYear: " << this->year << "\n";
    }
};

int main()
{
    system("clear");
    cout << "this\n";

    Car myCar("BMW", "THIS", 2333);

    myCar.print_details();
    return 0;
}