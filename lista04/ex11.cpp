#include <iostream>

class Pessoa 
{
    private: 
        std::string uf;
        std::string nome;
        std::string pais;
        std::string idade;
        std::string cidade;

        int pInicio = 0;
        int pFinal = 0;

    public:

        Pessoa(std::string s)
        {
            pFinal = s.find("tem");
            nome = s.substr(0, pFinal-1);

            pInicio = pFinal + 4;
            pFinal = s.find("anos");
            idade = s.substr(pInicio, (pFinal - pInicio)-1);

            pInicio = s.find(" em") + 4;
            pFinal = s.find("-");
            cidade = s.substr(pInicio, (pFinal - pInicio));

            pInicio = pFinal + 1;
            pFinal = s.find(",");
            uf = s.substr(pInicio, (pFinal - pInicio));

            pInicio = pFinal + 2;
            pFinal = s.size();
            pais = s.substr(pInicio, (pFinal - pInicio));
        }

        friend std::ostream& operator << (std::ostream& out, const Pessoa& p) 
        {
            out << p.nome << std::endl;
            out << p.idade << std::endl;
            out << p.cidade << std::endl;
            out << p.uf << std::endl;
            out << p.pais << std::endl;
            return out;
        }
};