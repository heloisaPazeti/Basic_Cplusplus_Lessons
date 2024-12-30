#include <iostream>
#include <stdio.h>
#include <random>
#include <math.h>

class Polinomio2 {

        int _a;
        int _b;
        int _c;

    public:

        Polinomio2(int a = 0, int b = 0, int c = 0) {
            if(a != 0)
            {
                _a = a;
                _b = b;
                _c = c;
            }
            else
            {
                _a = 1;
                _b = rand();
                _c = rand();
            }
        }

        double *raizes() {
            
            // Calcular delta
                // Delta > 0 -> 2 raizes reais
                // Delta < 0 -> sem raizes reais
                // Delta = 0 -> uma unica raiz

            int size;
            double *raizes;
            double delta = _b*_b - 4*_a*_c;

            if(delta < 0)
            {
                raizes = (double*)calloc(1, sizeof(double));
                raizes[0] = (double)0;
            }
            else if(delta == 0)
            {
                raizes = (double*)calloc(2, sizeof(double));
                raizes[0] = (double)1;
                raizes[1] = -_b/(2*_a);
            }
            else
            {
                raizes = (double*)calloc(3, sizeof(double));
                raizes[0] = (double)2;
                raizes[1] = (-_b-sqrt(delta))/(2*_a);
                raizes[2] = (-_b+sqrt(delta))/(2*_a);
            }

            return raizes;
        }

        double operator()(double x) const {

            return (_a*x*x + _b*x + _c);
        }


};

class Trio {

    public: 
        int a, b, c;

        Trio(int a = 1, int b = 0, int c = 0) {
            this->a = a;
            this->b = b;
            this->c = c;
        }
};


Trio coeficientes(const Polinomio2& p) {
    
    double _a, _b, _c;
    // p(x) = ax² + bx + c
    // p(0) = c

    // p(1) = a + b + c
    // p(-1) = a - b + c
    //-----------------------
    // 2a + 2c = p(1) + p(-1)

    // a = (p(1) + p(-1) - 2c)/2
    // b = a + c - p(-1)

    _c = p(0);
    _a = (p(1) + p(-1) - 2*_c)/2;
    _b = _a + _c - p(-1);

    return Trio(_a, _b, _c);
}


int main() {
    return 0;
}