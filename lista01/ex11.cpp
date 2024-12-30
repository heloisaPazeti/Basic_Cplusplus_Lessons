#include <iostream>
#include <string>
#include <sstream>
#include <math.h>


std::string raizes(double a, double b, double c);

int main()
{
    double a,b,c;
    std::string result;

    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    result = raizes(a, b, c);
    std::cout << result;

    return 0;
}

std::string raizes(double a, double b, double c)
{
    std::stringstream stream;
    double x1, x2;
    double delta = pow(b, 2) - (4*a*c);

    if(delta < 0)
        return "Nenhuma";
    else if((a == 0) && (b == 0))
    {
        if(c == 0)
            return "Infinitas";
        else
            return "Nenhuma";
    }

    if(a != 0)
    {
        x1 = ((-b) + sqrt(delta))/(2*a);
        x2 = ((-b) - sqrt(delta))/(2*a);
    }
    else
    {
        x1 = -(c/b);
        x2 = x1;
    }
    
    if(x1 == x2)
        return (std::to_string(x1));
    else if(x1 > x2)
        return (std::to_string(x2) + " e " + std::to_string(x1));
    else
        return (std::to_string(x1) + " e " + std::to_string(x2));
}