#include <stdio.h>
#include <iostream> 
#include <fstream>
#include <string>

class Arquivo {
    private:
        std::ifstream _conteudo;

    public:
        Arquivo(std::string arquivo) {
             _conteudo.open(arquivo);
            if(!_conteudo.is_open()){
                std::cout << "Erro ao abrir o arquivo " << arquivo << '\n';
             }
        }

        std::string proxima_linha() {
            std::string line;
            if (getline(_conteudo, line)) return line;
            else return "";
        }

        ~Arquivo() { _conteudo.close();}
};

int main() {
    
    return 0;
}