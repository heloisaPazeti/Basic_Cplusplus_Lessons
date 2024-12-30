#include <iostream>

std::string retira(std::string texto, char c)
{
    for(int i = 0; i < texto.size(); i++)
    {
        if(texto[i] == c)
        {
            texto.erase(i, 1);
            i--;
        } 
    }

    return texto;
}