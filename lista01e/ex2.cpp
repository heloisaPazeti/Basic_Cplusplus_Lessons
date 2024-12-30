#include <iostream>

int main()
{
    int temp, result = 0;
    while(std::cin >> temp)
        result = result ^ temp;
    
    std::cout << result;
    return 0;
}