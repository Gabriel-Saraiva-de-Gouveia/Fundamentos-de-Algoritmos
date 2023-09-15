/**Projeto uma fun��o que procure se um valor x existe em um arranjo de n�meros inteiros
organizados em ordem crescente. Devolva o �ndice correspondente a esse valor x no arranjo ou -1 caso o valor
n�o exista no vetor. (para pensar: o fato do vetor estar em ordem ajuda a encontrar x de alguma forma?
                       conceitos de busca sequencial e bin�ria).
An�lise: projetar uma fun��o que verifica se um valor x existe em um arranjo e, caso ele exista, devolva o �ndice correspondente.

Tipos de dados:
*entrada: um valor x e um arranjo de inteiros em ordem crescente.
*sa�da: um valor inteiro que corresponde a posi��o do valor x no arranjo.

Especifica��o:
//Assinatura:
int encontra_posicao_x (int x, vector<int> elementos){
    return 0;
    }
//Prop�sito: verificar se um valor x pertence ao vetor de entrada e devolver o indice correspondente.

//Exemplos:
    check_expect(encontra_posicao_x(4, vector<int>{1, 2, 3, 4, 5, 6}), 3);
    check_expect(encontra_posicao_x(36, vector<int>{6, 9, 12, 24, 36, 15}), 4);
    check_expect(encontra_posicao_x(23, vector<int>{2, 3, 5, 7, 11, 13, 17, 23, 29, 57}), 6);
    check_expect(encontra_posicao_x(61, vector<int>{2, 4, 6, 8, 10, 12, 14, 24, 36, 60}), -1);
**/
//IMPLEMENTA��O:
#include <iostream>
#include <vector>
#include "bscpp.hpp"
using namespace std;

int encontra_posicao_x (int x, const vector<int> &elementos){
    int inicio = 0;
    int fim = elementos.size() - 1;
    int indice = 0;
    while(inicio <= fim){
        int meio = (inicio + fim)/2;
        if( x == elementos[meio]){
            return indice = meio;
        }
        else if( x < elementos[meio]){
            fim = meio - 1;
        }
        else if( x > elementos[meio]){
            inicio = meio + 1;
        }
    }
    return indice = -1;
}

examples{
    check_expect(encontra_posicao_x(4, vector<int>{1, 2, 3, 4, 5, 6}), 3);
    check_expect(encontra_posicao_x(36, vector<int>{6, 9, 12, 24, 36, 15}), 4);
    check_expect(encontra_posicao_x(23, vector<int>{2, 3, 5, 7, 11, 13, 17, 23, 29, 57}), 7);
    check_expect(encontra_posicao_x(5, vector<int>{2, 4, 6, 8, 10, 12, 14, 24, 36, 60}), -1);
}
int main(){
    run_tests();
    }














