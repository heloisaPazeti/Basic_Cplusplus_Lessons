#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

typedef std::vector< std::vector<int> > Matriz;

bool Compare(const std::vector<int> &v1, const std::vector<int> &v2)
{
    int count1 = 0, count2 = 0;
    for(int i : v1)
        if (i % 2 == 0) count1++;

    for(int i : v2)
        if (i % 2 == 0) count2++;

    if(count1 == count2)
    {
        for(int k = 0; k < v2.size(); k++)
        {
            if(v1[k] != v2[k]) return v1[k] < v2[k];
        }
    }
    
    return count1 < count2;
}

void ordena_par(Matriz& M)
{
    return std::sort(M.begin(), M.end(), Compare);
}