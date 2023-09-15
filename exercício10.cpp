/** Segundo a conjectura de Goldbach, qualquer número par, maior do que 2, pode ser escrito como
a soma de 2 números primos. Ex: 8 = 3 + 5 (3 e 5 são primos e 8 é par), 16 = 11 + 5, 68 = 31 + 37.
Projete uma função que receba um número n > 2 (par) como entrada e retorne os dois primos resultantes.
DICA: Perceba que não é necessário gerar todas as combinações de dois números primeiros, mas encontrar
o primeiro primo e verificar se a diferença dele com um número n (par) também é primo.

Análise: projetar uma função que receba um número n > 2 (par) como entrada e retorne os dois primos resultantes.

Tipos de dados:
*entrada: um número n maior que dois e que seja par
*saída: dois números primos resultantes

Especificação:
//Assinatura:
*função auxiliar que verifica se um número é primo
array<int, 2> encontra_primos (int n){
    return primos_resultantes = {};
    }

//Propósito: calcular os dois número primos resultantes que cuja soma resulta em n.

//Exemplos:
    check_expect(encontra_primos(8),(array<int,2>{3, 5}));
    check_expect(encontra_primos(16),(array<int,2>{11, 5}));
    check_expect(encontra_primos(68),(array<int,2>{31, 37}));
**/
//Implementação:
#include <iostream>
#include <vector>
#include "bscpp.hpp"
using namespace std;
bool primo(int n)
{
    bool primo = n > 1;
    for (int i = 2; i <= n / 2 && primo; i = i + 1) {
        if (n % i == 0) {
            primo = false;
        }
    }
    return primo;
}

vector<int> encontra_primos (int n){
    vector<int> primos_resultantes = {};
    int p = 2;
    while (!( primo(p) && primo(n - p) ) ){
        p = p + 1;
        primos_resultantes.push_back(p);
        primos_resultantes.push_back(n-p);
    }
    return primos_resultantes;
}

examples{
    check_expect(encontra_primos(8),(vector<int>{3, 5}));
    check_expect(encontra_primos(16),(vector<int>{3, 13}));
    check_expect(encontra_primos(10),(vector<int>{3, 7}));
    check_expect(encontra_primos(12),(vector<int>{3, 9}));
}
int main(){
    run_tests();
    }

