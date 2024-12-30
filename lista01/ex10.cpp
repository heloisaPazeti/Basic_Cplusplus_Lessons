#include <iostream>
#include <iomanip>

void Change(double change);

int main()
{
    double toPay, pay;

    std::cin >> toPay;
    std::cin >> pay; 

    Change(pay-toPay);
    return 0;
}

void Change(double change)
{
    float availableMoney[] = {200.00, 100.00, 50.00, 20.00, 10.00, 5.00, 2.00, 1.00, 0.50, 0.25, 0.10, 0.05, 0.01};
    int size = sizeof(availableMoney)/sizeof(availableMoney[0]);
    int usedMoney[size];
    int i = 0;
    int k;
   
    for(k = 0; k < size; k++)
        usedMoney[k] = 0;

    std::cout << std::fixed << std::setprecision(2) << "Troco: R$ " << change << "\n";

    while((i < size))
    {

        if(((change)*1000)+1 >= availableMoney[i]*1000)
        {
            change -= availableMoney[i];
            usedMoney[i]++; 
        }
        else
            i++;
    }

    for(k = 0; k < size; k++)
        std::cout << usedMoney[k] << " de R$ " << std::fixed << std::setprecision(2) << availableMoney[k] << "\n";
}