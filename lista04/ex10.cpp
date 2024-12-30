#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::string &s1, std::string &s2) 
{ 
    int pInicio1 = 0, pFinal1 = 0;
    int pInicio2 = 0, pFinal2 = 0;
    int sub1, sub2;

    if(s1 == s2) return false;

    while(pInicio1 != -1 && pInicio2 != -1)
    {
        pInicio1 = pFinal1;
        pInicio2 = pFinal2;

        pFinal1 = s1.find('.', pInicio1+1);
        pFinal2 = s2.find('.', pInicio2+1);

        if(pFinal1 == -1 || pFinal2 == -1) 
        {
            if(pInicio1 == 0) pFinal1 = s1.size()-1;
            if(pInicio2 == 0) pFinal2 = s2.size()-1;
        }


        pFinal1++;
        pFinal2++;
        
        sub1 = stoi(s1.substr(pInicio1, (pInicio1 - pFinal1))); 
        sub2 = stoi(s2.substr(pInicio2, (pInicio2 - pFinal2)));
        pInicio1 = s1.find('.', pInicio1+1);
        pInicio2 = s2.find('.', pInicio2+1);

        if(sub1 == sub2) continue;
        return sub1 < sub2;

    }


    return s1.size() < s2.size(); 

}

void ordena_versoes(std::vector<std::string>& versoes) { std::sort(versoes.begin(), versoes.end(), compare);}