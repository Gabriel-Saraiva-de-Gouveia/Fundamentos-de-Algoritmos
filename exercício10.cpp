/** Segundo a conjectura de Goldbach, qualquer n�mero par, maior do que 2, pode ser escrito como
a soma de 2 n�meros primos. Ex: 8 = 3 + 5 (3 e 5 s�o primos e 8 � par), 16 = 11 + 5, 68 = 31 + 37.
Projete uma fun��o que receba um n�mero n > 2 (par) como entrada e retorne os dois primos resultantes.
DICA: Perceba que n�o � necess�rio gerar todas as combina��es de dois n�meros primeiros, mas encontrar
o primeiro primo e verificar se a diferen�a dele com um n�mero n (par) tamb�m � primo.

An�lise: projetar uma fun��o que receba um n�mero n > 2 (par) como entrada e retorne os dois primos resultantes.

Tipos de dados:
*entrada: um n�mero n maior que dois e que seja par
*sa�da: dois n�meros primos resultantes

Especifica��o:
//Assinatura:
*fun��o auxiliar que verifica se um n�mero � primo
array<int, 2> encontra_primos (int n){
    return primos_resultantes = {};
    }

//Prop�sito: calcular os dois n�mero primos resultantes que cuja soma resulta em n.

//Exemplos:
    check_expect(encontra_primos(8),(array<int,2>{3, 5}));
    check_expect(encontra_primos(16),(array<int,2>{11, 5}));
    check_expect(encontra_primos(68),(array<int,2>{31, 37}));
**/
//Implementa��o:
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

