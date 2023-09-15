/** Projete uma fun��o que receba as informa��es necess�rias para gerar os n primeiros
termos de uma Progress�o Aritm�tica (PA), quais s�o: a1, que represente o primeiro temo da PA
e r, quie represente a raz�o da PA. Retorne um arranjo contendo cada um dos n termos da PA.

An�lise: projetar uma fun��o que calcule os n primeiros termos de uma PA.

Tipos de dados:
*entrada: a1, razao, n que representa o numero de termos.
*sa�da: arranjo de n�meros representando os n termos da PA.

Especifica��o:
//Assinatura:
vector<int> gera_termos_PA(int a1, int razao, int n){
    return vector<int> termos_PA{};
}
//Prop�sito: determinar os n termos da PA, com a1 sendo o primeiro termo e a razao sendo a raz�o da PA.

//exemplos:
    check_expect(gera_termos_PA(2, 2, 4),(vector<int>{2, 4, 6, 8}));
    check_expect(gera_termos_PA(3, 2, 5),(vector<int>{3, 5, 7, 9, 11}));
    check_expect(gera_termos_PA(1, 5, 4),(vector<int>{1, 6, 11, 16}));
    check_expect(gera_termos_PA(2, 3, 4),(vector<int>{2, 5, 8, 11}));

**/
//Implementa��o
#include <iostream>
#include <vector>
#include "bscpp.hpp"
using namespace std;

vector<int> gera_termos_PA(int a1, int razao, int n){
    vector<int> termos_PA = {};
    termos_PA.push_back(a1);
    for(int i = 1; i < n; i = i + 1){
        a1 = a1 + razao;
        termos_PA.push_back(a1);
    }
    return termos_PA;
}

examples{
    check_expect(gera_termos_PA(2, 2, 4),(vector<int>{2, 4, 6, 8}));
    check_expect(gera_termos_PA(3, 2, 5),(vector<int>{3, 5, 7, 9, 11}));
    check_expect(gera_termos_PA(1, 5, 4),(vector<int>{1, 6, 11, 16}));
    check_expect(gera_termos_PA(2, 3, 4),(vector<int>{2, 5, 8, 11}));
    check_expect(gera_termos_PA(12, 6, 5),(vector<int>{12, 18, 24, 30, 36}))
}

int main(){
    run_tests();
    }

