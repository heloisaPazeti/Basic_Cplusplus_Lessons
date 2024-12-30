#include <iostream>

int seq(int n, int k, int *ini);

int main()
{
    int n, k, result;
    int *ini;

    std::cin >> n;
    std::cin >> k;

    for(int i = 0; i < k; i++)
        std::cin >> ini[i];

    result = seq(n, k, ini);
    std::cout << result;

    return 0;
}

int seq(int n, int k, int *ini)
{
    int i, j, sum;
    int temp[n+1];

    for(i = 0; i <= n; i++)
    {
        if(i < k)
            temp[i] = ini[i];
        else
        {
            sum = 0;
            for(j = (i-k); j < i; j++)
                sum += (temp[j]*temp[j]);
            
            temp[i] = sum;
        }
    }

    return temp[n];
}