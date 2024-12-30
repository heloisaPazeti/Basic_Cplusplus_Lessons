#include <stdio.h>
#include <iostream>
#include <math.h>

class Vetor {

    private: 

        int _x;
        int _y;

    public:

        Vetor(int x = 0, int y = 0) {
            
            _x = x;
            _y = y;
        }

        friend Vetor operator+(const Vetor& a, const Vetor& b) {
            
            return Vetor(a._x+b._x, a._y+b._y);
        }

        friend Vetor operator-(const Vetor& a, const Vetor& b) {

            return Vetor(a._x-b._x, a._y-b._y);
        }

        friend int operator*(const Vetor& a, const Vetor& b) {

            return (a._x*b._x + a._y*b._y);
        }

        // Como calcular o ângulo -> https://mundoeducacao.uol.com.br/matematica/angulo-entre-dois-vetores.htm
        friend double operator<(const Vetor& a, const Vetor& b) {
            
            Vetor _a = a;
            Vetor _b = b;
            double angulo = acos((a*b)/(_a.abs()*_b.abs()))*180/M_PI;   //180/pi -> transformar para grau
            return angulo;
        }

        friend int operator^(const Vetor& a, const Vetor& b) {

            // D = |ax ay|
            //     |bx by|
            // D = (ax*by) - (ay*bx) 
            return (a._x*b._y - a._y*b._x);
        }


        friend std::ostream& operator<<(std::ostream &out, const Vetor &a) {

            std::cout << "(" << a._x << ", " << a._y << ")"; 
            return out;
        }

        double abs() {
            return sqrt(_x*_x + _y*_y);
        }

};

int main() {

    Vetor v;
    int a, b;
    double c;
    std::cout << v << std::endl;
    v = v+Vetor(1, 2);
    std::cout << v << std::endl;
    v = v+Vetor(1, 2);
    std::cout << v << std::endl;
    v = v-Vetor(1, 6);
    std::cout << v << std::endl;
    a = v*Vetor(3, 2);
    std::cout << a << std::endl;
    b = v^Vetor(-4501, 9002);
    std::cout << b << std::endl;
    c = v.abs();
    std::cout << c << std::endl;

    return 0;
}