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

        double operator()(double x) {

            return (_a*x*x + _b*x + _c);
        }


};

int main() {

    return 0;
}