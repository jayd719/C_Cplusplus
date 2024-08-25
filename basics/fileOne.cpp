#include <iostream>
int main()
{
    int j = 1;
    int k = 2;

    int sum;

    sum = j+k;
    std::cout << sum;

    if(sum<5){
        std::cout<<"\nthis is here\n";
    }


    std::string name="s";
    std::cout << name.empty();
    std::cout << name.insert(1,"as");
    return 0;
}