/**Projetar uma fun��o que receba um arranjo contendo a temperatura m�dia de cada m�s do ano, em graus Celsius,
e devolva, a maior e a menor temperatura do ano e em que m�s elas aconteceram.

An�lise: projetar uma fun��o que receba um arranjo contendo a temperatura m�dia de cada m�s do ano e devolva,
a maior e a menor temperatura do ano e em que m�s elas aconteceram.

Tipos de dados:
*entrada: um arranjo do tipo struct que cont�m a temperatura m�dia de cada m�s do ano.
*sa�da: um vetor do tipo struct que contem a maior e a menor temperatura do ano e o m�s.

Especifica��o:
//Assinatura:
vector<TemperaturaAno> determina_temperaturas (vector<TemperaturaAno>){
    return temperaturas = {};
    }
//Prop�sito: determinar a maior e a menor temperatura do ano e em que m�s elas aconteceram.

//Exemplos:
    check_expect(determina_temperaturas(vector<TemperaturaAno>{34 outubro, 12 julho, 37.5 dezembro}),
    (vector<TemperaturaAno>{37.5 dezembro, 12 julho}));
    check_expect(determina_temperaturas(vector<TemperaturaAno>{5 mar�o, 17 maio, -5 maio}),
    (vector<TemperaturaAno>{17 maio, -5 maio}));
    check_expect(determina_temperaturas(vector<TemperaturaAno>{10 agosto, 20.6 fevereiro, -2 junho, 40 janeiro}),
    (vector<TemperaturaAno>{40 janeiro, -2 junho}));
**/
//Implementa��o
#include <iostream>
#include <vector>
#include <string>
#include "bscpp.hpp"
using namespace std;

enum Mes{
    janeiro =1,
    fevereiro = 2,
    marco = 3,
    abril = 4,
    maio = 5,
    junho = 6,
    julho = 7,
    agosto = 8,
    setembro = 9,
    outubro = 10,
    novembro = 11,
    dezembro = 12,
    };

struct TemperaturaAno {
    float temperatura;
    Mes mes;
};

vector<TemperaturaAno> determina_temperaturas (vector<TemperaturaAno> &previsoes){
    vector<TemperaturaAno> temperaturas = {};
    for(int i = 0; i < previsoes.size(); i++){
        TemperaturaAno temp_menor;
        TemperaturaAno temp_maior;
        TemperaturaAno t;
        if(temp_maior.temperatura < t.temperatura){
            temp_maior.temperatura = t.temperatura;
        }
        else if(temp_menor.temperatura > t.temperatura){
            temp_menor.temperatura = t.temperatura;
        }
        temperaturas.push_back(t);
    }
    return temperaturas = {};
}
examples{
    check_expect(determina_temperaturas(vector<TemperaturaAno>({34, outubro, 12, julho, 37.5, dezembro})),
                 (vector<TemperaturaAno>({37.5, dezembro, 12, julho})));
    check_expect(determina_temperaturas(vector<TemperaturaAno>({5 mar�o, 17, maio, -5, maio})),
                 (vector<TemperaturaAno>({17, maio, -5, maio})));
    check_expect(determina_temperaturas(vector<TemperaturaAno>({10, agosto, 20.6, fevereiro, -2, junho, 40, janeiro})),
                 (vector<TemperaturaAno>({40, janeiro, -2, junho})));
}
int main(){
    run_tests();
}












