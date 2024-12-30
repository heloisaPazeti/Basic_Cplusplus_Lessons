#include <iostream>
#include <math.h>

int main()
{
    float n1, n2, n3;
    float mA, mH, mG, mQ;


    std::cin >> n1;
    std::cin >> n2;
    std::cin >> n3;

    mA = (n1+n2+n3)/3;
    mH = 3/(1/n1 + 1/n2 + 1/n3);
    mG = pow((n1*n2*n3), (1.0f/3.0f));
    
    float q = pow(n1, 2) + pow(n2, 2) + pow(n3, 2);
    mQ = pow(q/3, (0.5));

    std::cout << "Menor: " << mH << "\n";
    std::cout << "Maior: " <<  mQ;

    return 0;
}