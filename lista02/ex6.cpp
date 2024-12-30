// =========================================================
// =============== HELOISA PAZETI - 14577991 ===============
// =========================================================


// Baseado no código em https://www.geeksforgeeks.org/bigint-big-integers-in-c-with-example/

#include <string> 
#include <stdio.h>
#include <iostream>
#include <iomanip>

#define max 1000000000

int CalculateAllocSize(int charSize)
{
    int mallocSize;

    if(charSize % 9 == 0)
        mallocSize = charSize/9;
    else if (charSize % 9 > 0)
        mallocSize = ((charSize-(charSize%9))/9) + 1;
    else
        mallocSize = 1; 

    return mallocSize;
}

class BigInt {

    int* _partes;
    int _npartes;
    bool _positivo = true;
    
    public:

        // ============================================
        // =============== CONSTRUTORES ===============
        // ============================================

        // Recebe uma string e transforma em um big int
        BigInt(std::string numero) {

            int i, k = numero.size()-1;
            int size = numero.size();

            if(numero[0] == '-')
            {
                _positivo = false;
                size--;
            }

            _npartes = CalculateAllocSize(size);
            _partes = new int[_npartes];

            for(i = _npartes-1; i >= 0; i--)
            {
                char temp[9] = {'0', '0', '0', '0', '0', '0', '0', '0', '0'};
                for(int j = 8; j >= 0; j--)
                {
                    if(k < 0 || numero[k] == '-')
                        break;
                    
                    temp[j] = numero[k];
                    k--;
                }
                _partes[i] = std::stoi(temp);
            }
        }   

        
        // Recebe um int para ou ser um big int ou para ser o valor zero, apenas inicializado.
        BigInt(int num = 0, bool eh_num = true) {

            if(eh_num)
                new (this) BigInt(std::to_string(num));
            else
            {
                _npartes = num;
                _partes = new int[num];
                for(int i = 0; i < _npartes; i++)
                    _partes[i] = 0;
            }
        }

        // Move b para um novo big int
        BigInt(BigInt&& b) {
            
            _positivo = std::move(b._positivo);
            _npartes = std::move(b._npartes);

            if(b._partes != NULL)
            {
                _partes = b._partes;
                b._partes = NULL;
            }
        }

        // ============================================
        // =============== DESTRUTORES ================
        // ============================================

        ~BigInt() {
            _npartes = 0;
            delete this->_partes;
        }

        // ============================================
        // ================= RETORNOS =================
        // ============================================

        bool positivo() const { return _positivo; }

        // ============================================
        // ================ OPERACOES =================
        // ============================================

        BigInt& operator=(const BigInt& b) {

            _positivo = b._positivo;
            _npartes = b._npartes;

            delete this->_partes;
            _partes = new int[_npartes];

            for(int i = 0; i < _npartes; i++)
                _partes[i] = b._partes[i];

            return *this;
        }

        // Retorna o modulo
        BigInt abs() const {

            BigInt temp = BigInt(this->_npartes, false);
            temp = *this;
            temp._positivo = true;
            return temp;
        }

        // Retorna o sinal oposto
        BigInt operator-() const {

            BigInt temp;
            temp = *this;
            temp._positivo = !temp._positivo;
            return temp;

        }

        // Compara dois big ints
        friend bool operator==(const BigInt& a, const BigInt& b) {


            int sub, smaller;

            if(&a == &b) return true;                                           // Se sao o mesmo endereco sao iguais
            if((a._partes == NULL) || (b._partes == NULL)) return false;        // Se nao estao alocados nao existem
            if(a._positivo != b._positivo) return false;                        // Se nao tem o mesmo sinal nao sao iguais

            if(a._npartes == 0 && b == BigInt()) return true;
            if(b._npartes == 0 && a == BigInt()) return true;

            if(a._npartes > b._npartes)                                         // Vetor a > vetor b
            {
                smaller = b._npartes;
                sub = a._npartes - b._npartes;

                for(int i = 0; i < sub; i++)                                    // So serao iguais se o vetor a mais for zero
                    if(a._partes[i] != 0) return false;


                for(int i = 0; i < smaller; i++)                                // Verifica se o resto eh igual
                    if(a._partes[i+sub] != b._partes[i]) return false;
            }
            else                                                                // Vetor b > vetor a ou vetor b = vetor a
            {
                smaller = a._npartes;
                sub = b._npartes - a._npartes;

                for(int i = 0; i < sub; i++)
                    if(b._partes[i] != 0) return false;

                for(int i = 0; i < smaller; i++)
                    if(a._partes[i] != b._partes[i+sub]) return false;
            }
            
            return true;
        }

        friend bool operator>(const BigInt& a, const BigInt& b) {

            int sub, smaller;
            bool aIsbigger;

            if((a._positivo) && (!b._positivo)) return true;                    // Se a for positivo e b negativo, entao a > b
            if((!a._positivo) && (b._positivo)) return false;                   // Se a for negativo e b positivo, entao b > a

            if(a._npartes > b._npartes)                                         // Vetor a > vetor b
            {
                smaller = b._npartes;
                sub = a._npartes - b._npartes;

                for(int i = 0; i < sub; i++)                                    // Verifica se |a| > |b| ou a = 0
                {
                    if(a._partes[i] > 0)
                    {
                        if(!a._positivo && !b._positivo) return false;
                        return true;
                    }

                }

                for(int i = 0; i < smaller; i++)                                // Tem o mesmo tamanho -> verifica se |a| > |b|
                {
                    if(a._partes[i+sub] > b._partes[i])
                    {
                        if(!a._positivo && !b._positivo) return false;
                        return true;
                    }

                }

                if(!a._positivo && !b._positivo) return true;                   // |b| > |a| -> verifica sinal
                return false;
            }
            else                                                                // Vetor b > vetor a ou vetor b = vetor a
            {
                smaller = a._npartes;
                sub = b._npartes - a._npartes;

                for(int i = 0; i < sub; i++)
                {
                    if(b._partes[i] > 0)
                    {
                        if(!a._positivo && !b._positivo) return true;
                        return false;
                    }

                }

                for(int i = 0; i < smaller; i++)
                {
                    if(a._partes[i] < b._partes[i+sub])
                    {
                        if(!a._positivo && !b._positivo) return true;
                        return false;
                    }
                    else if(a._partes[i] > b._partes[i+sub])
                    {
                        if(!a._positivo && !b._positivo) return false;
                        return true;
                    }

                }
                return false;                                                           // b == a
            }
        }
        
        // Trata caso onde a,b > 0
        friend BigInt operator+(const BigInt& a, const BigInt& b) {

            int smaller = 0, sub = 0, zeros = 0;
            BigInt temp;
            
            if(a.abs() == b.abs())                                                      // Se |a| == |b|
            {
                if(a._positivo != b._positivo)                                          // Sinais opostos -> a + b = 0
                    return BigInt();                                                    // Retorna big int zerado
            }
            if(a._positivo && !b._positivo)                                             // Se b < 0
                return (a - b.abs());                                                      // Subtracao dos modulos
            
            if(!a._positivo && b._positivo)                                             // Se a < 0
                return (b - a.abs());                                                      // Subtracao dos modulos

            if(a._npartes > b._npartes)                                                 // Se a > b (em tamanho)
            {
                temp = BigInt(a._npartes + 1, false);                                   // Instancia temp com max necessario de espaço = 0
                smaller = b._npartes;                                                   // Menor entre eles
                sub = a._npartes - b._npartes;                                          // Diferença entre eles

                for(int i = 0; i < sub; i++)                                            // Adiciona valor "maior"
                    temp._partes[i + 1] = a._partes[i];

                for(int i = 0; i < smaller; i++)                                        // Soma posicoes iguais
                    temp._partes[i + sub + 1] = a._partes[i + sub] + b._partes[i];
            }
            else
            {   
                temp = BigInt(b._npartes + 1, false);                                   // Instancia temp com max necessario de espaço = 0
                smaller = a._npartes;                                                   // Menor entre eles
                sub = b._npartes - a._npartes;                                          // Diferença entre eles

                for(int i = 0; i < sub; i++)                                            // Adiciona valor "maior"
                    temp._partes[i + 1] = b._partes[i];

                for(int i = 0; i < smaller; i++)                                        // Soma posicoes iguais
                    temp._partes[i + sub + 1] = a._partes[i] + b._partes[i + sub];
            }

            
            for(int i = temp._npartes - 1; i > 0; i--)
            {
                if(temp._partes[i] >= max)                                              // Se pedaco > 1000000000
                {
                    temp._partes[i] -= max;
                    temp._partes[i-1] += 1;
                }
            }

            if(!a._positivo && !b._positivo)
                temp._positivo = false;
            else
                temp._positivo = true;

            return temp;
        }

        // Trata o caso onde necessariamente a, b > 0 e onde a > b
        friend BigInt operator-(const BigInt& a, const BigInt& b) {

            int smaller = 0, sub = 0, zeros = 0;         
            BigInt temp;

            if(a.abs() == b.abs())
            {
                if(a._positivo == b._positivo)
                    return BigInt();
            }

            if(!a._positivo && b._positivo) return a+(-b);                                      // Se -a e +b, entao a-b = -a-b = -(a+b)
            if(a._positivo && !b._positivo) return a+(-b);                                      // Se +a e -b, entao a-b = a+b
            if(!a._positivo && !b._positivo) return (-b)-(-a);                                  // Se -a e -b, entao a-b = b-a

            temp._positivo = true;                                                              // Caso reduzido para a,b > 0, a > b

            if(b > a) 
                return -(b - a);


            if(a._npartes > b._npartes)
            {
                temp = BigInt(a._npartes + 1, false);                                           // Cria um temp com o tamanho max possivel
                smaller = b._npartes;                                                           // Pega o menor numero de casas
                sub = a._npartes - b._npartes;                                                  // Encontra a diferenca

                for(int i = 0; i < sub; i++)                                                    // Escreve as casas a mais
                    temp._partes[i + 1] = a._partes[i];

                for(int i = 0; i < smaller; i++)                                                // Escreve as subtracoes 
                    temp._partes[i + sub + 1] = a._partes[i + sub] - b._partes[i];  
            }
            else
            {
                temp = BigInt(b._npartes + 1, false);                                           // Cria um temp com o tamanho max possivel
                smaller = a._npartes;                                                           // Pega o menor numero de casas
                sub = b._npartes - a._npartes;                                                  // Encontra a diferenca

                for(int i = 0; i < sub; i++)                                                    // Escreve as casas a mais
                    temp._partes[i + 1] = (-1 * b._partes[i]);

                for(int i = 0; i < smaller; i++)                                                // Escreve as subtracoes
                    temp._partes[i + sub + 1] = a._partes[i] - b._partes[i + sub];
            }
 
            for(int i = temp._npartes - 1; i > 0; i--)                                          // Verifica se tem que "emprestar"
            {
                if(temp._partes[i] < 0)
                {
                    temp._partes[i] += 1000000000;
                    temp._partes[i-1] -= 1;
                }
            }

            return temp;
        }

        friend BigInt operator*(const BigInt& a, const BigInt& b) {

            BigInt temp, result;
            int i = 0, j = 0;
            int k = a._npartes + b._npartes;                                                            // Maior tamanho possivel para temp = a._npartes + b._npartes
            int zeros = 0;                                                                              // Saber os zeros à esquerda
            long long int totalCarry = 0; 

            if(a == BigInt() || b == BigInt())                                                          // Se a ou b forem zero
                return BigInt();

            if(a._npartes <= 1 && a._partes[0] == 0) return BigInt();
            if(b._npartes <= 1 && b._partes[0] == 0) return BigInt();
    
            temp = BigInt(k, false);                                                                    // Inicializa temp

            if(a._positivo == b._positivo)                                                              // Escolhe sinal
                temp._positivo = true;
            else
                temp._positivo = false;

            for(i = a._npartes-1; i >= 0; i--)                                                          // Vai multiplicar todos os numeros por todos
            {
                                                                   
                for(j = b._npartes-1; j >= 0; j--)
                {
                    k = i+j+1;                                                                          // "Passa pra proxima casa"
                    long long int value = (long long int)a._partes[i] * (long long int)b._partes[j];    // Valor da multiplicacao
                    totalCarry = temp._partes[k] + value;                                               // Vai ser o total que tem que jogar pro outro lado
                    temp._partes[k] = totalCarry % max;                                                 // Parte "quebrada" é somada no atual
                    temp._partes[k-1] += totalCarry/max;                                                // Parte inteira é o carry somado                  
                }
            }

            for(i = 0 ; i < temp._npartes; i++)                                                         // Conta zeros à esquerda
            {
                if(temp._partes[i] == 0)
                    zeros++;
                else
                    break;
            }

            result =  BigInt(temp._npartes-zeros, false);                                               // Cria o resultado
            result._positivo = temp._positivo;                                                          // Acerta o sinal

            for(i = 0; i < result._npartes; i++)                                                        // Escreve o resultado
                result._partes[i] = temp._partes[i+zeros];

            return result; 
        }

        BigInt operator/(int b) {

            int i = 0;
            int leftZero = 0;
            long long int res = 0;
            BigInt temp = BigInt(this->_npartes, false);

            if(this->_positivo != (b >= 0)) temp._positivo = false;

            for (i = 0; i < this->_npartes; i++)
            {
                temp._partes[i] = (this->_partes[i]+res) / std::abs(b);
                res = ((this->_partes[i]+res) % b)*max;
            }

            for(int i = 0; i < this->_npartes-1; i++)
            {
                if(this->_partes[i] == 0)
                    leftZero++;
                else
                    break;
            }
            
            BigInt result(temp._npartes - leftZero, false);                                    // Resultado com tamanho real
            for(int i = 0; i < result._npartes; i++)                                           // Copia valores de fato para result
                result._partes[i] = temp._partes[i + leftZero];

            result._positivo = temp._positivo;

            return result;
        }

        friend BigInt operator^(const BigInt& a, const BigInt& b) {
            
            BigInt r = BigInt(1, true);                                                         // Big int de resultado
            BigInt _b = BigInt();                                                               // Contador
            BigInt uni = BigInt(1, true);                                                       // Big int unitario
            _b = b;                                                                             // Inicio do contador

            while(!(_b == BigInt()))                                                            // Enquanto contador diferente de zero
            {
                r = r * a;                                                                      // Multiplica
                _b = _b - uni;                                                                  // Diminui contador
            }

            return r;                                                                           // Retorna resultado
        }


        // ============================================
        // ================ IMPRESSAO =================
        // ============================================

       friend std::ostream& operator<<(std::ostream &out, const BigInt &a) {

        int i = 0;
        bool isFirst = true;
        std::string temp;

        if(a._partes == nullptr)
            return out;

        if(a == BigInt() || a._npartes == 0)
        {
            out << '0';
            return out;
        }

        if(!a._positivo)
        {
            if(!(a._npartes <= 1 && a._partes[0] == 0))
                out << "-";
        }

        for(i = 0; i < a._npartes-1; i++)
        {
            if(a._partes[i] != 0)
                break;
        }

        while(i < a._npartes)
        {
            temp = std::to_string(a._partes[i]);

            if(isFirst)
                isFirst = false;
            else
                temp.insert(0, 9 - temp.size(), '0');
               
            out << temp;

            i++;
        }
        return out;
    }
};