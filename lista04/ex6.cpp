#include <iostream>
#include <vector>
#include <set>

std::vector<int> retira(std::vector<int> v, int n)
{
    std::set<int> s;
    std::vector<int> r;

    for(int i : v)
        s.insert(i);

    s.erase(n);
    
    for(int i : s)
        r.push_back(i);

    return r;
}