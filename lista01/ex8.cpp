#include <iostream>
#include <fstream>
#include <string>
using namespace std;

std::string conteudo(std::string nome);

int main () 
{
    string fileName;
    string text;
    cin >> fileName;

    text = conteudo(fileName);
    cout << text;  

  return 0;
}

std::string conteudo(std::string nome)
{
    string text;
    string line;
    ifstream file(nome);

    if(!file.is_open())
    {
        cout << "Failed To Open File.";
        return text;
    }

    while (!file.eof()) 
    {
      getline(file, line);
      text += line;
      text += "\n";
    }

    file.close();
    return text;
}
