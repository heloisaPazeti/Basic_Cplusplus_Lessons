#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>

#define indexStack   0
#define indexQueue   1
#define indexPq      2

void add(int value, std::stack<int> &stack, std::queue<int> &queue, std::priority_queue<int> &pq)
{
    stack.push(value);
    queue.push(value);
    pq.push(value);
}

void pop(int value, bool *r, std::stack<int> &stack, std::queue<int> &queue, std::priority_queue<int> &pq)
{
    if(stack.top() != value)    r[indexStack] = false;
    if(queue.front() != value)  r[indexQueue] = false;
    if(pq.top() != value)       r[indexPq] = false;

    stack.pop();
    queue.pop();
    pq.pop();
}

int main()
{
    std::string op;
    std::stack<int> stack;
    std::queue<int> queue;
    std::priority_queue<int> pq;

    int value;
    bool r[3] = { true, true, true};

    std::cin >> op >> value;
    add(value, stack, queue, pq);

    while(std::cin >> op)
    {
        std::cin >> value;
        
        if(op == "add")
            add(value, stack, queue, pq);
        if(op == "pop")
            pop(value, r, stack, queue, pq);
    }

    if(r[indexStack] && !r[indexQueue] && !r[indexPq])    std::cout << "stack"    << std::endl;
    if(!r[indexStack] && r[indexQueue] && !r[indexPq])    std::cout << "queue"    << std::endl;
    if(!r[indexStack] && !r[indexQueue] && r[indexPq])    std::cout << "priority" << std::endl;
    if((r[indexStack] + r[indexQueue] + r[indexPq]) >= 2) std::cout << "both"     << std::endl;
    if((r[indexStack] + r[indexQueue] + r[indexPq]) == 0) std::cout << "none"     << std::endl;

    return 0;
}