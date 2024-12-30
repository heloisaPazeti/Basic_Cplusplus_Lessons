#include <iostream>
#include <map>

typedef std::map<std::pair<int, int>, int> Matriz;
Matriz soma(const Matriz& A, const Matriz& B)
{
    Matriz r;

    for(const auto &[k, v] : A)
        r.insert({{k.first, k.second}, v});

    for(const  auto &[i, j] : B)
    {
        if(i.first!=-1 && i.second!=-1) r[{i.first, i.second}] += j;
        if(r[{i.first, i.second}] == 0) r.erase({i.first, i.second});
    }

    return r;
}