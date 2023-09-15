/**Projete uma função que procure se um valor x existe em um arranjo de números inteiros e devolva o índice correspondente
a esse valor x no arranjo ou -1 caso o valor não exista no vetor.

Análise: projetar uma função que procure se um valor x existe em um arranjo de números inteiros e devolva o índice correspondente
a esse valor.
Tipos de dados:
*entrada: um arranjo de numeros inteiros e um valor x
*saída: um valor inteiro que representa o índice do valor x no arranjo

Especificação:
//Assinatura:
int procura_indice_de_x (int x, vector<int> valores){
    return 0;
    }
//Propósito: procurar o índice de um valor x de entrada em um vetor também de entrada.

//Exemplos:
    check_expect(procura_indice_de_x(4, vector<int>{1, 2, 3, 4}), 3);
    check_expect(procura_indice_de_x(43, vector<int>{12, 34, 7, 9, 18, 43, 0}), 5);
    check_expect(procura_indice_de_x(-2, vector<int>{0, -1, -3, -4, 6, -7, 4, -2}), 7);
    check_expect(procura_indice_de_x(6, vector<int>{1, 2, 3, 4}), -1);
**/
//Implementação
#include <iostream>
#include <vector>
#include "bscpp.hpp"
using namespace std;
int procura_indice_de_x (int x, const vector<int> &valores){
    int indice = 0;
    for(int i = 0; i < valores.size(); i++){
        if( x == valores[i]){
            indice = i;
        }
        else{
            indice = -1;
        }
    }
    return indice;
}
examples{
    check_expect(procura_indice_de_x(4, vector<int>{1, 2, 3, 4}), 3);
    check_expect(procura_indice_de_x(43, vector<int>{1, 7, 9, 18, 43}), 4);
    check_expect(procura_indice_de_x(-2, vector<int>{0, -1, -3, -4, 6, -7, 4, -2}), 7);
    check_expect(procura_indice_de_x(7, vector<int>{1, 2, 3, 4}), -1);
}
int main(){
    run_tests();
    }









