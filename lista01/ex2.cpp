#include <iostream>
using namespace std;

int main() 
{
    int candyQuant;
    int chocQuant;
    float singleCandyPrice;
    float singleChocPrice;

    float totalValue = 0;

    cin >> candyQuant;
    cin >> singleCandyPrice;
    cin >> chocQuant;
    cin >> singleChocPrice;


    totalValue = (candyQuant * singleCandyPrice) + (chocQuant * singleChocPrice);
    //totalValue = (chocQuant * singleChocPrice);
    cout << totalValue;

    return 0;
}
