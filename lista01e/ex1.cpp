#include <iostream>

int main()
{
    int i, n;
    int gap = 3*5*7*11*17;
    
    std::cin >> n;

    for(i = 1; (i*gap) <= n; i++)
        std::cout << i*gap << "\n";
    return 0;
}