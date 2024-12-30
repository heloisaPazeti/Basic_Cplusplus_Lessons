#include <iostream>
#include <math.h>
#include <iomanip>

int main()
{
    double x1, y1, x2, y2;
    double dist;

    std::cin >> x1;
    std::cin >> y1;
    std::cin >> x2;
    std::cin >> y2;

    dist = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
    std::cout << std::fixed << std::setprecision(4) << dist; 

    return 0;
}