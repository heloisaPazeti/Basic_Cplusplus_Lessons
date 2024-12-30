#include <iostream>
#include <fstream>
#include <string>

// Class Iterator -> https://stackoverflow.com/questions/62716242/implement-iterator-over-file

struct End_iterator {};
struct Iterator {

    private:
        std::ifstream& file_;
        std::string str_;

        void next() {
            std::getline(file_, str_);
        }

    public:
        Iterator(std::ifstream& file) : file_{file} {
            next();
        }

        const std::string& operator*() const {
            return str_;
        }

        Iterator& operator++() {
            next();
            return *this;
        }

        bool operator!=(End_iterator) const {
            return !!file_;
        }
};

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

        Iterator begin() {
            return Iterator(_conteudo);
        }

        End_iterator end() {
            return End_iterator();
        }

        ~Arquivo() { _conteudo.close();}
};

int main()
{
    for (const auto& linha : Arquivo("ex3.cpp" ))
        std::cout << linha << std::endl;   

    return 0; 
}