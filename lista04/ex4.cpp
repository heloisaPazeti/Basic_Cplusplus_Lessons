#include <iostream>
#include <vector>
#include <algorithm>

bool order(const std::string &first, const std::string &second)
{
    if(first.size() == second.size()) return first > second;   
    return first.size() < second.size();
}

void ordena_strings(std::vector<std::string>& vetor)
{
    std::sort(vetor.begin(), vetor.end(), order);
}