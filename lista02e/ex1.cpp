#include <iostream>

#define max 100

class Televisao {

    bool _ligada;
    int _canal;

    friend std::ostream& operator<<(std::ostream &out, const Televisao &tv) {

        std::string r[2] = {"ligada", "desligada"};
        out <<  "(" << r[!tv._ligada] << ", " << tv._canal << ")"; 
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
            _canal = _canal%max;
            _canal += _ligada;
        }

        void canal_baixo() {
            int espelho = max - _canal;
            espelho += _ligada;
            _canal = max - (espelho % max);
        }
};

int main()
{
    return 0;
}