#include <iostream>
#include <stdio.h>
#include <stack>
#include <queue>

std::string jogo(std::stack<int> cartas, std::queue<std::string> jogadores)
{
    std::string *jog = new std::string[jogadores.size()];
    int somas[jogadores.size()];
    int carta, i, k = 0;
    int vencedor = 0, tam = jogadores.size();

    for (i = 0; i < tam; i++)
    {
        somas[i] = 0;
        jog[i] = jogadores.front();
        jogadores.pop();
    }

    while(!cartas.empty())
    {
        i = (k % tam);
        carta = cartas.top();
        cartas.pop();
        somas[i] += carta;
        k++;
    }

    for(i = 0; i < tam; i++)
    {
        if(somas[vencedor] > somas[i])
            vencedor = i;

        if(somas[vencedor] == somas[i])
            vencedor = jog[vencedor] < jog[i] ? vencedor : i;
    }

    return jog[vencedor];
}

int main() {
    std::stack<int> c;
    std::queue<std::string> j;
    c.push(3);
    c.push(5);
    c.push(15);
    c.push(6);
    c.push(15);
    c.push(8);
    c.push(12);
    c.push(7);
    c.push(7);
    c.push(15);
    c.push(6);
    c.push(4);
    c.push(5);
    c.push(10);
    c.push(10);
    c.push(7);
    c.push(2);
    c.push(13);
    c.push(1);
    c.push(10);
    c.push(7);
    c.push(10);
    c.push(3);
    c.push(9);
    c.push(12);
    c.push(13);
    c.push(9);
    c.push(11);
    c.push(4);
    c.push(7);
    c.push(10);
    c.push(5);
    c.push(1);
    c.push(10);
    c.push(1);
    c.push(3);
    c.push(3);
    c.push(5);
    c.push(3);
    c.push(2);
    c.push(3);
    c.push(7);
    c.push(10);
    c.push(11);
    c.push(5);
    c.push(1);
    c.push(9);
    c.push(2);
    c.push(13);
    c.push(5);
    j.push("benjamin");
    j.push("thomas");
    j.push("diogo");
    j.push("antonella");
    j.push("zoe");
    j.push("josué");
    j.push("ravy");
    j.push("nicolas");
    j.push("daniel");
    j.push("joana");
    j.push("isabelly");
    j.push("sabrina");
    j.push("evelyn");
    j.push("heitor");
    j.push("anna");
    j.push("cauã");
    std::cout << jogo(c, j) << std::endl;
    return 0;
}