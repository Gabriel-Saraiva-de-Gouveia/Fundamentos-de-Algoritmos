/**Projete uma fun��o que calcule e devolva um arranjo W cujos componentes s�o os fatoriais dos respectivos componentes
de um arranjo V dado como entrada.

An�lise: Projetar uma fun��o que de devolva um arranjo W que cont�m os fatoriais de cada elemento de um arranjo V.

Tipo de dados:
*entrada: um arranjo inteiro V
*sa�da: um arranjo W de inteiros contendo os fatoriais.

Especifica��o:
//Assinatura:
vector<int> fatoriais_de_v (vector<int> v){
    return vector<int> w = {};
}
//Prop�sito: devolver um arranjo que cont�m os fatoriais dos elementos de um arranjo de entrada

//Exemplos:
    check_expect(fatoriais_de_v(vector<int> v = {1, 2, 3, 4},), (vector<int> = {1, 2, 6, 24}));
    check_expect(fatoriais_de_v(vector<int> v = {0, 2, 4},), (vector<int> = {1, 2, 24}));
    check_expect(fatoriais_de_v(vector<int> v = {0, 5, 4, 6},), (vector<int> = {1, 120, 24, 720}));
**/
//Implementa��o
#include <iostream>
#include <vector>
#include "bscpp.hpp"
using namespace std;

vector<int> fatoriais_de_v (vector<int> v){
    vector<int> w = {};
    for(int i = 0; i < v.size(); i++){
        int fat;
        for(int j = 0; j < v.size(); j++){
            fat = v[j] * fat;
        }
            w.push_back(fat);
    }
    return w;
}


examples{
    check_expect(fatoriais_de_v(vector<int>{1, 2, 4}), (vector<int>{1, 2, 24}));
    check_expect(fatoriais_de_v(vector<int>{1, 5, 4, 6}), (vector<int>{1, 120, 24, 720}));
}
int main(){
    run_tests();
    }








