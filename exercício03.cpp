#include <iostream>
#include <array>
#include "bscpp.hpp"
using namespace std;

int numero_de_acertos (array<char, 10> gabarito, array<char, 10> respostas){
    int acertos = 0;
    for(int i = 0; i < gabarito.size(); i++){
        if(gabarito[i] == respostas[i]){
            acertos = acertos + 1;
        }
    }
    return acertos;
}

examples{
    check_expect(numero_de_acertos(array<char, 10>{'a', 'b', 'c', 'f', 'c', 'c', 'f', 'd', 'f', 'a'},
                                   array<char, 10>{'b', 'b', 'c', 'f', 'd', 'c', 'f', 'd', 'f', 'b'}), 7);
    check_expect(numero_de_acertos(array<char, 10>{'a', 'b', 'c', 'f', 'c', 'c', 'f', 'd', 'f', 'a'},
                                   array<char, 10>{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'f', 'j'}), 4);
    check_expect(numero_de_acertos(array<char, 10>{'a', 'b', 'c', 'f', 'c', 'c', 'f', 'd', 'f', 'a'},
                                   array<char, 10>{'a', 'b', 'c', 'f', 'c', 'c', 'f', 'd', 'f', 'a'}), 10);
}
int main(){
    run_tests();
    }
