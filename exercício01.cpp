/**
Projete um programa que possa auxiliar um professor a calcular a nota final de cada um dos alunos de uma turma
(sabendo-se que a nota final é calculada pela média aritmética simples das notas de 3 avaliações) e determinar
se o aluno foi aprovado (média >= 6) ou não na disciplina. Além disso, o programa deve calcular a média geral
da turma e determinar quantos alunos ficaram com notas acima dessa média.

Inicialmente devemos projetar funções auxiliares, de propósito simples, para auxiliar a resolver o problema em questão.

1) ler os dados dos alunos (três notas para cada um) e colocar os dados em um arranjo que contenha os dados de cada aluno da turma.
2) calcular a nota final e determinar a situação de cada aluno (aprovado ou reprovado).
3) calcular a média geral da turma.
4)  determinar quantos alunos obtiveram nota final maior que a média geral da turma.

Convém criar então uma estrutura de dados que possa guardar as informações de cada um dos alunos da turma em uma mesma variável.
Para isso, precisamos de uma estrutura que represente os dados de cada um dos alunos:
**/

#include<iostream>
#include "bscpp.hpp"

using namespace std;

enum Situacao {
 	aprovado,
	reprovado,
};

struct Aluno {
	int RA;
	float nota1,
          nota2,
          nota3,
          notafinal;
	Situacao situacao;
};



/**
A função de leitura de dados deve colocar os dados dos alunos em um arranjo de alunos, vamos chamá-lo de turma:
vector<Aluno> turma = {};

1) A função de leitura de dados colocará informações fornecidas pelo professor para as notas 1, 2 e 3,
referente aos n alunos da turma. Por isso essa função não tem parâmetro de entrada, somente de saída.

2) A função que calcula a nota final e a situação de cada aluno, recebe o arranjo turma e determina os
campos notafinal e situação de cada aluno. O arranjo pode ser um parâmetro passado por referência, e nesse caso, o retorno da função é void.

3) A função que calcula a média geral da turma, recebe o arranjo turma e devolve a média geral da turma.

4) A função que determina o número de alunos acima da média geral da turma recebe o arranjo turma e a média
geral da turma e retorno o número de alunos acima da média.

******************** FUNÇÃO 1 - LEITURA DE DADOS

1) Analise: A função de leitura de dados (RA e notas) deve colocar os dados dos alunos
fornecidos pelo professor em um arranjo de alunos (turma)
2) Tipos de dados:
    entrada: nenhuma
    saída: um arranjo de alunos ==> vector<Aluno> turma = {};

3)Especificão:
    3.1 assinatura:
        vector<Aluno> le_notas_alunos(){
            vector<Aluno> turma = {};
            ...
            return turma;
        }

    3.2 propósito: ler dados (RA e notas) dos alunos fornecidos pelo professor e
    colocar as informações em turma
    3.3 exemplos: depende dos dados digitados pelo professor
    3.4 repetição:
        quais variáveis serão calculadas? serão lidas as notas de um aluno de cada vez
        como as variáveis serão inicializadas? turma = {}
        com as variáveis serão atualizadas? os dados do aluno em questão serão adicionados ao final do arranjo turma

//versão parada do laço pela quantidade de alunos na turma
//Propósito: ler dados (RA e notas) dos alunos fornecidos pelo professor e colocar as informações em turma
//    vector<Aluno> le_notas_alunos(){
//            vector<Aluno> turma = {};
//            Aluno a1;
//            int n;
//            cout<<"Entre com a quantidade de alunos na turma: ";
//            cin>>n;
//            for(int i = 0; i < n; i++){
//                cout<<"Entre com o RA do aluno ou um número negativo para parar: ";
//                cin>>a1.RA;
//                cout<<"Entre com as três notas do aluno: ";
//                cin>>a1.nota1>>a1.nota2>>a1.nota3;
//                turma.push_back(a1);
//            }
//            return turma;
//    }

**/

//versão parada do laço pelo finalizados (RA == a número negativo)
//Propósito: ler dados (RA e notas) dos alunos fornecidos pelo professor e colocar as informações em turma
    vector<Aluno> le_notas_alunos(){
            vector<Aluno> turma = {};
            Aluno a1;
            cout<<"Entre com o RA do aluno ou um número negativo para parar: ";
            cin>>a1.RA;
            while (a1.RA >= 0){
                cout<<"Entre com as três notas do aluno: ";
                cin>>a1.nota1>>a1.nota2>>a1.nota3;
                turma.push_back(a1);
                cout<<"Entre com o RA do aluno ou um número negativo para parar: ";
                cin>>a1.RA;
            }
            return turma;
    }

/******************** FUNÇÃO 2 - CALCULO NOTA FINAL E SITUAÇÃO

1) Analise: A função que calcula a nota final e a situação de cada aluno,
recebe o arranjo turma e determina os campos notafinal e situação de cada aluno.
O arranjo pode ser um parâmetro passado por referência, e nesse caso,
o retorno da função é void.

2) Tipos de dados:
    entrada: um arranjo de alunos (turma)
    saída: void (o arranjo de entrada será passado por referência)

3)Especificão:
    3.1 assinatura:
        void calcula_notafinal_situacao(vector<Aluno> &turma){

        }
    3.2 propósito: calcular a nota final e a situação de cada aluno, com base nas notas
    das três avaliações e sabendo-se que a nota final é a média aritmétia simples das três
    notas e a situação é aprovado para notafinal >= 6 e reprovado caso contrário.
    3.3 exemplos:
        vector<Aluno> turma ={{123, 4.0, 3.0, 8.0}, {124, 4.0, 6.0, 8.0}, {125, 4.0, 3.0, 5.0}}
        calcula_notafinal_situacao(turma);
        check_expect(turma,(vector<Aluno>{Aluno{123, 4.0, 3.0, 8.0, 5.0, reprovado},
                                          Aluno{124, 4.0, 6.0, 8.0, 6.0, aprovado},
                                          Aluno{125, 4.0, 3.0, 5.0, 4.0, reprovado}));


        turma = {{126, 7.0, 4.5, 8.0}, {127, 7.0, 6.0, 8.0}, {128, 4.0, 4.5, 5.0}};
        calcula_notafinal_situacao(turma);
        check_expect(turma,(vector<Aluno>{Aluno{126, 7.0, 4.5, 8.0, 6.5, aprovado},
                                          Aluno{127, 7.0, 6.0, 8.0, 7.0, aprovado},
                                          Aluno{128, 4.0, 4.5, 5.0, 4.5, reprovado}}))

    3.4 repetição:
        quais variáveis serão calculadas? notafinal e situação de cada um dos alunos
        como as variáveis serão inicializadas? notafinal será a média aritmética simples das três notas de cada aluno
        e situação será aprovado se notafinal > = 6 e reprovado caso contrário
        com as variáveis serão atualizadas? com as notas do próximo aluno

**/

    void calcula_notafinal_situacao(vector<Aluno> &turma){
        for(int i = 0; i < turma.size(); i++){
            Aluno a = turma[i];
            a.notafinal = (a.nota1 + a.nota2 + a.nota3)/3;
            if (a.notafinal >= 6.0)
                a.situacao = aprovado;
            else a.situacao = reprovado;
            turma[i] = a;
        }
    }


/********************** FUNÇÃO 3 - CALCULO MEDIA GERAL DA TURMA

1) Analise: A função que calcula a média geral da turma, recebe o arranjo turma e devolve a média geral da turma.

2) Tipos de dados:
    entrada: nota final dos alunos (a.notafinal)
    saída: um valor do tipo real que representa a média geral da turma.

3)Especificão:
    3.1 assinatura:
        float media_final_turma (

    3.2 propósito:

    3.3 exemplos:

    3.4 repetição:
        quais variáveis serão calculadas?
        como as variáveis serão inicializadas?
        com as variáveis serão atualizadas?
**/

/********************* FUNÇÃO 4 - DETERMINA QUANTIDADE DE ALUNO ACIMA DA MÉDIA GERAL DA TURMA

1) Analise: A função que determina o número de alunos acima da média geral da turma recebe o arranjo turma e a média
geral da turma e retorno o número de alunos acima da média.

2) Tipos de dados:
    entrada:
    saída:

3)Especificão:
    3.1 assinatura:

    3.2 propósito:

    3.3 exemplos:

    3.4 repetição:
        quais variáveis serão calculadas?
        como as variáveis serão inicializadas?
        com as variáveis serão atualizadas?
**/



    examples{
        vector<Aluno> turma = {};
        turma = {{123, 4.0, 3.0, 8.0}, {124, 4.0, 6.0, 8.0}, {125, 4.0, 3.0, 5.0}};
        calcula_notafinal_situacao(turma);
        check_expect(turma,(vector<Aluno>{Aluno{123, 4.0, 3.0, 8.0, 5.0, reprovado},
                                          Aluno{124, 4.0, 6.0, 8.0, 6.0, aprovado},
                                          Aluno{125, 4.0, 3.0, 5.0, 4.0, reprovado}}));

        turma = {{126, 7.0, 4.5, 8.0}, {127, 7.0, 6.0, 8.0}, {128, 4.0, 4.5, 5.0}};
        calcula_notafinal_situacao(turma);
        check_expect(turma,(vector<Aluno>{Aluno{126, 7.0, 4.5, 8.0, 6.5, aprovado},
                                          Aluno{127, 7.0, 6.0, 8.0, 7.0, aprovado},
                                          Aluno{128, 4.0, 4.5, 5.0, 4.5, reprovado}}))
    }




int main(){
    //vector<Aluno> turma = le_notas_alunos();
    run_tests();
    //calcula notafinal e situação de todos os alunos
    //calcula média geral da turma
    //determina qtde de alunos acima da média geral

}
