#include <iostream>
#include <vector>
#include <array>
#include "bscpp.hpp"
using namespace std;


int busca_binaria(const array<int, 5> &lista, int elemento){
    int pos_inicio = 0;
    int pos_fim = lista.size() - 1;
    int meio = (pos_inicio + pos_fim) / 2;

    while( pos_inicio <= pos_fim){
        if(lista[meio] == elemento){
            return meio;
        }
        if(lista[meio] > elemento){
            pos_fim  = meio - 1;
        }
        if(lista[meio] < elemento){
            pos_inicio = meio + 1;
        }
    }
    return meio;
}

examples{
    check_expect(busca_binaria((array<int, 5> {2, 4, 6, 7, 8}), 7), 3);
    check_expect(busca_binaria((array<int, 5> {2, 4, 6, 7, 8}), 2), 0);
    check_expect(busca_binaria((array<int, 5> {2, 4, 6, 7, 8}), 4), 1);
    check_expect(busca_binaria((array<int, 5> {2, 4, 6, 7, 8}), 8), 4);
}
int main(){
    run_tests();
}
