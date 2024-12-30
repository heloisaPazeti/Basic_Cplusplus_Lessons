#include <iostream>


int soma(double a, double b)
{  
    return (int)(a+b);
}

int main()
{
    double a,b;
    int result;

    std::cin >> a;
    std::cin >> b;

    result = soma(a,b);
    std::cout << result;

    return 0;
}