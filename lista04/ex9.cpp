#include <iostream>
#include <vector>

std::vector<double> notas(std::string s)
{
    std::vector<double> v;
    int pInicio = 0, pFinal = 0;
   
    while (true)
    { 
        pInicio = s.find(",", pFinal+1);
        pFinal = s.find(",", pInicio+1);
        v.push_back(stod(s.substr(pInicio+1, (pFinal - pInicio)-1)));
        
        if (s.find(",", pFinal) == -1)
            break;
    }

    return v;
}
