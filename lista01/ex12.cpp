#include <iostream>

int pow(int b, int e, int m);

int main()
{
    int b, e, m, result;

    std::cin >> b;
    std::cin >> e;
    std::cin >> m;

    result = pow(b, e, m);

    std::cout << result;
    return 0;
}

int pow(int b, int e, int m)
{
    int num = 1;

    for(int i = 0; i < e; i++)
        num *= b;

    return (num % m);
}