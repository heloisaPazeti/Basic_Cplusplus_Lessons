#include <iostream>

class Fracao {

    private: 

        long long int _numerador;
        long long int _denominador;

        void reduz() {

            long long int mdc;
            long long int numerador, denominador;

            numerador = this->_numerador;
            denominador = this->_denominador;

            while(denominador != 0){
                long long int r = numerador % denominador;
                numerador = denominador;
                denominador = r;
            }

            mdc = numerador;

            this->_numerador = this->_numerador / mdc;
            this->_denominador = this->_denominador / mdc;

        }

    public:

        Fracao(long long int numerador = 0, long long int denominador = 1) {
            _numerador = numerador;
            _denominador = denominador;

            reduz();
        }

        // Código baseado em um post no stack overflow
        Fracao(double x, double eps) {

           long long int sinal ;

            // Para inverter sinal caso precise
            if(x<0){
                sinal = -1;
                x = sinal*x;
            }
            else{
                sinal = 1;
            }

            // Retirar parte intera do numero.
            long long int n = static_cast<long long int>(x); 
            x -= n;

            // Aproximando erro
            if (x < eps) {
                _numerador = n*sinal;
                _denominador = 1;
                return;
            } else if (1 - eps < x) {
                _numerador = (n + 1)*sinal;
                _denominador = 1;
                return;
            }
            
            long long int lower_n = 0, lower_d = 1;
            long long int upper_n = 1, upper_d = 1;

            while (true) {
                long long int middle_n = lower_n + upper_n;
                long long int middle_d = lower_d + upper_d;

                if (middle_d * (x + eps) < middle_n) {
                    upper_n = middle_n;
                    upper_d = middle_d;
                } else if (middle_n < (x - eps) * middle_d) {
                    lower_n = middle_n;
                    lower_d = middle_d;
                } else {
                    _numerador = (n * middle_d + middle_n)*sinal;
                    _denominador = middle_d;
                    reduz();
                    return;
                }
            }

            reduz();
        }

        operator double(){

            double num = double(_numerador);
            double den = double(_denominador);

            return num/den;
        }

        friend Fracao operator+(const Fracao& a, const Fracao& b) {
                
                long long int numerador, denominador;

                if(b._numerador == 0) return a;
                if(a._numerador == 0) return b;

                numerador = (a._numerador*b._denominador) + (a._denominador * b._numerador);
                denominador = a._denominador * b._denominador;

                return Fracao(numerador, denominador);
        }

        friend Fracao operator-(const Fracao& a, const Fracao& b) {
                
                long long int numerador, denominador;

                if(b._numerador == 0) return a;
                if(a._numerador == 0) return Fracao(-b._numerador, b._denominador);

                numerador = (a._numerador*b._denominador) - (a._denominador * b._numerador);
                denominador = a._denominador * b._denominador;

                return Fracao(numerador, denominador);
        }

        friend Fracao operator*(const Fracao& a, const Fracao& b) {

                return Fracao(a._numerador * b._numerador, a._denominador * b._denominador);
        }

        friend Fracao operator/(const Fracao& a, const Fracao& b) {

                return Fracao(a._numerador * b._denominador, a._denominador * b._numerador);
        }

        
        friend std::ostream& operator<<(std::ostream &out, const Fracao &a) {

                if(a._numerador == 0)
                    std::cout << 0;
                else if(a._numerador == a._denominador || a._denominador == 1)
                    std::cout << a._numerador;
                else
                    std::cout << "" << a._numerador << "/" << a._denominador;

                return out;

        }

};

int main()
{
    Fracao f(-93LL, 19LL);
    f = f * Fracao(-61LL, 82LL);
    std::cout << f << " " << double(f) << std::endl;
    f = f - Fracao(63LL, 30LL);
    std::cout << f << " " << double(f) << std::endl;
    f = f + Fracao(-35LL, 57LL);
    f = f - Fracao(3LL, 84LL);
    f = f + Fracao(-5LL, 8LL);
    f = f / Fracao(20LL, 42LL);
    f = f + Fracao(-32LL, 91LL);
    f = f * Fracao(30LL, 24LL);
    f = f / Fracao(19LL, 8LL);
    f = f * Fracao(99LL, 29LL);
    f = f - Fracao(36LL, 31LL);
    f = f * Fracao(50LL, 21LL);
    std::cout << f << " " << double(f) << std::endl;
    
    f = f - Fracao(-21LL, 13LL);
    f = f + Fracao(12LL, 88LL);
    f = f - Fracao(-1LL, 42LL);
    f = f * Fracao(27LL, 33LL);
    f = f + Fracao(91LL, 1LL);
    f = f - Fracao(7LL, 18LL);
    std::cout << f << " " << double(f) << std::endl;
    f = f - Fracao(29LL, 9LL);
    std::cout << f << " " << double(f) << std::endl;
    f = f + Fracao(46LL, 64LL); 
    return 0;
}