#include <iostream>
using namespace std;

int main() 
{
    int middleNumber;

    cin >> middleNumber;

    for (int i = 0; i <= 2*middleNumber; i++)
    {
        if(i != 2*middleNumber)
            cout << i << ", ";
        else
            cout << i;
    }

    return 0;
}
