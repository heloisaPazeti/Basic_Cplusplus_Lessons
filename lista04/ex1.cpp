#include <iostream>
#include <stack>

int elementok(std::stack<int> pilha, int k) 
{
    int temp;
    while(!pilha.empty() && k != 0)
    {
        temp = pilha.top();
        pilha.pop();

        if(temp % 2 == 0)
            k--;
    } 

    if( k == 0 ) return temp;
    return -1;
}

int main() 
{

    std::stack<int> pilha;
    for(int e=5; e>=1; e--)
    pilha.push(e);

    std::cout << elementok(pilha, 2) << std::endl;

    while(not pilha.empty()) 
    {
        std::cout << pilha.top() << " " ;
        pilha.pop();
    }
    std::cout << std::endl;
    return 0;
}