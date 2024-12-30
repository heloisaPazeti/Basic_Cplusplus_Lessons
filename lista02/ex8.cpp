// =========================================================
// =============== HELOISA PAZETI - 14577991 ===============
// =========================================================

#include <stdio.h>
#include <iostream>

// NUMEROS COMPLEXOS
class C {
    
    double _real = 0;
    double _imag = 0;

    public: 

        C(double real = 0, double imag = 0) {
            _real = real;
            _imag = imag;
        }

        // ============================================
        // ================== SETS ====================
        // ============================================

        int setReal(double real) {
            _real = real;
            return 0;
        }

        // ============================================
        // ================ IMPRESSAO =================
        // ============================================

        friend std::ostream& operator<<(std::ostream &out, const C &c) {

            c.Print();
            return out;
        }

        virtual int Print() const {

            if(_imag != 0)
                std::cout << _real << " + " << _imag << "i";
            else
                std::cout << _real;

            return 0;
        }

};

// NUMEROS REAIS
class R: public C {
    
    public:

        R(double real = 0) {
            this->setReal(real);
        }
};

// NUMEROS RACIONAIS
class Q: public R {
    
    int _numerador = 0;
    int _denominador = 1;

    public:

        Q(int numerador = 0, int denominador = 1) {

            _numerador = numerador;
            _denominador = denominador;
            this->setReal(_numerador/_denominador);
        }

        // ============================================
        // ================== SETS ====================
        // ============================================

        int setNumerador(int numerador) {
            _numerador = numerador;
            return 0;
        }

        // ============================================
        // ================== GETS ====================
        // ============================================

        int getNumerador() const { return _numerador; }

        // ============================================
        // ================ IMPRESSAO =================
        // ============================================

        virtual int Print() const {

            if(_denominador != 1)
                std::cout << _numerador << "/" << _denominador;
            else
                std::cout << _numerador;

            return 0;
        }
};

// NUMEROS INTEIROS
class Z: public Q {

    public:
        
        Z(int numerador = 0) {

            this->setNumerador(numerador);
            this->setReal(numerador);
        }

        // ============================================
        // ================ IMPRESSAO =================
        // ============================================

        
        virtual int Print() const {

            int numerador = this->getNumerador();

            if(numerador > 0)
                std::cout << "+" << numerador;
            else
                std::cout << numerador;

            return 0;
        }

        
};

// NUMEROS NATURAIS
class N: public Z {

    public:
    
        N(int numerador) {

            this->setNumerador(numerador);
            this->setReal(numerador);
        }

        // ============================================
        // ================ IMPRESSAO =================
        // ============================================

        
        virtual int Print() const {
                std::cout << this->getNumerador();
            return 0;
        }
};


int main() {

    const int numObjetos = 5;
    C* objetos[numObjetos];
    objetos[0] = new C(3.5, 2.1);
    objetos[1] = new R(5.0);
    objetos[2] = new Q(1, 3);
    objetos[3] = new Z(10);
    objetos[4] = new N(10);
    for (int i = 0; i < numObjetos; ++i)
        std::cout << *objetos[i] << std::endl;
    for (int i = 0; i < numObjetos; ++i)
        delete objetos[i];

    return 0;
}