#include <iostream>


class Televisao {

    bool _ligada;
    int _canal;

    friend std::ostream& operator<<(std::ostream &out, const Televisao &tv) {

             if(tv._ligada)
                std::cout << "(ligada, " << tv._canal << ")";
            else
                std::cout << "(desligada, " << tv._canal << ")";

            return out;
    }

    public:

        Televisao(bool ligada = false, int canal = 1) {
            _ligada = ligada;
            _canal = canal;
        }

        void liga() {
            _ligada = true;
        }

        void desliga() {
            _ligada = false;
        }

        void canal_cima() {
            if(_ligada)
                _canal++;
        }

        void canal_baixo() {
            if(_ligada)
                _canal--;
        }
};

int main()
{
    Televisao tv;
    std::cout << tv << std::endl;
    tv.canal_cima();
    std::cout << tv << std::endl;
    tv.canal_baixo();
    std::cout << tv << std::endl;
    tv.liga();
    std::cout << tv << std::endl;
    tv.canal_cima();
    std::cout << tv << std::endl;
    tv.canal_baixo();
    std::cout << tv << std::endl;
    tv.desliga();
    std::cout << tv << std::endl;
    tv.canal_cima();
    std::cout << tv << std::endl;
    return 0;
}