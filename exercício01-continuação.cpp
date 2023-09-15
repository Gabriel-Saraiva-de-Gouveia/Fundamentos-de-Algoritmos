/**
Projete um programa que possa auxiliar um professor a calcular a nota final de cada um dos alunos de uma turma
(sabendo-se que a nota final Ú calculada pela mÚdia aritmÚtica simples das notas de 3 avaliações) e determinar
se o aluno foi aprovado (média >= 6) ou não na disciplina. Além disso, o programa deve calcular a mÚdia geral
da turma e determinar quantos alunos ficaram com notas acima dessa média.

Inicialmente devemos projetar funþ§es auxiliares, de prop¾sito simples, para auxiliar a resolver o problema em questÒo.

1) ler os dados dos alunos (três notas para cada um) e colocar os dados em um arranjo que contenha os dados de cada aluno da turma.
2) calcular a nota final e determinar a situação de cada aluno (aprovado ou reprovado).
3) calcular a média geral da turma.
4) determinar quantos alunos obtiveram nota final maior que a média geral da turma.

Convém criar então uma estrutura de dados que possa guardar as informações de cada um dos alunos da turma em uma mesma variável.
Para isso, precisamos de uma estrutura que represente os dados de cada um dos alunos:
**/

#include<iostream>
//#include "bscpp.hpp"
#include<vector>

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
A funþÒo de leitura de dados deve colocar os dados dos alunos em um arranjo de alunos, vamos chamß-lo de turma:
vector<Aluno> turma = {};

1) A funþÒo de leitura de dados colocarß informaþ§es fornecidas pelo professor para as notas 1, 2 e 3,
referente aos n alunos da turma. Por isso essa funþÒo nÒo tem parÔmetro de entrada, somente de saÝda.

2) A funþÒo que calcula a nota final e a situaþÒo de cada aluno, recebe o arranjo turma e determina os
campos notafinal e situaþÒo de cada aluno. O arranjo pode ser um parÔmetro passado por referÛncia, e nesse caso, o retorno da funþÒo Ú void.

3) A funþÒo que calcula a mÚdia geral da turma, recebe o arranjo turma e devolve a mÚdia geral da turma.

4) A funþÒo que determina o n·mero de alunos acima da mÚdia geral da turma recebe o arranjo turma e a mÚdia
geral da turma e retorno o n·mero de alunos acima da mÚdia.

******************** FUNÃ+O 1 - LEITURA DE DADOS

1) Analise: A funþÒo de leitura de dados (RA e notas) deve colocar os dados dos alunos
fornecidos pelo professor em um arranjo de alunos (turma)
2) Tipos de dados:
    entrada: nenhuma
    saÝda: um arranjo de alunos ==> vector<Aluno> turma = {};
3)EspecificÒo:
    3.1 assinatura:
        vector<Aluno> le_notas_alunos(){
            vector<Aluno> turma = {};
            ...
            return turma;
        }

    3.2 prop¾sito: ler dados (RA e notas) dos alunos fornecidos pelo professor e
    colocar as informaþ§es em turma
    3.3 exemplos: depende dos dados digitados pelo professor
    3.4 repetiþÒo:
        quais varißveis serÒo calculadas? serÒo lidas as notas de um aluno de cada vez
        como as varißveis serÒo inicializadas? turma = {}
        com as varißveis serÒo atualizadas? os dados do aluno em questÒo serÒo adicionados ao final do arranjo turma

//versÒo parada do laþo pela quantidade de alunos na turma
//Prop¾sito: ler dados (RA e notas) dos alunos fornecidos pelo professor e colocar as informaþ§es em turma
//    vector<Aluno> le_notas_alunos(){
//            vector<Aluno> turma = {};
//            Aluno a1;
//            int n;
//            cout<<"Entre com a quantidade de alunos na turma: ";
//            cin>>n;
//            for(int i = 0; i < n; i++){
//                cout<<"Entre com o RA do aluno ou um n·mero negativo para parar: ";
//                cin>>a1.RA;
//                cout<<"Entre com as trÛs notas do aluno: ";
//                cin>>a1.nota1>>a1.nota2>>a1.nota3;
//                turma.push_back(a1);
//            }
//            return turma;
//    }

**/

//versÒo parada do laþo pelo finalizados (RA == a n·mero negativo)
//Prop¾sito: ler dados (RA e notas) dos alunos fornecidos pelo professor e colocar as informaþ§es em turma
    vector<Aluno> le_notas_alunos(){
            vector<Aluno> turma = {};
            Aluno a1;
            cout<<"Entre com o RA do aluno ou um n·mero negativo para parar: ";
            cin>>a1.RA;
            while (a1.RA >= 0){
                cout<<"Entre com as trÛs notas do aluno: ";
                cin>>a1.nota1>>a1.nota2>>a1.nota3;
                turma.push_back(a1);
                cout<<"Entre com o RA do aluno ou um n·mero negativo para parar: ";
                cin>>a1.RA;
            }
            return turma;
    }

/******************** FUNÃ+O 2 - CALCULO NOTA FINAL E SITUAÃ+O

1) Analise: A funþÒo que calcula a nota final e a situaþÒo de cada aluno,
recebe o arranjo turma e determina os campos notafinal e situaþÒo de cada aluno.
O arranjo pode ser um parÔmetro passado por referÛncia, e nesse caso,
o retorno da funþÒo Ú void.

2) Tipos de dados:
    entrada: um arranjo de alunos (turma)
    saÝda: void (o arranjo de entrada serß passado por referÛncia)

3)EspecificÒo:
    3.1 assinatura:
        void calcula_notafinal_situacao(vector<Aluno> &turma){

        }
    3.2 prop¾sito: calcular a nota final e a situaþÒo de cada aluno, com base nas notas
    das trÛs avaliaþ§es e sabendo-se que a nota final Ú a mÚdia aritmÚtia simples das trÛs
    notas e a situaþÒo Ú aprovado para notafinal >= 6 e reprovado caso contrßrio.
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

    3.4 repetiþÒo:
        quais varißveis serÒo calculadas? notafinal e situaþÒo de cada um dos alunos
        como as varißveis serÒo inicializadas? notafinal serß a mÚdia aritmÚtica simples das trÛs notas de cada aluno
        e situaþÒo serß aprovado se notafinal > = 6 e reprovado caso contrßrio
        com as varißveis serÒo atualizadas? com as notas do pr¾ximo aluno

**/

/**
    calcula a nota final e a situaþÒo de cada aluno, com base nas notas
    das trÛs avaliaþ§es e sabendo-se que a nota final Ú a mÚdia aritmÚtia simples das trÛs
    notas e a situaþÒo Ú aprovado para notafinal >= 6 e reprovado caso contrßrio.
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

//   examples{
//        vector<Aluno> turma = {};
//        turma = {{123, 4.0, 3.0, 8.0}, {124, 4.0, 6.0, 8.0}, {125, 4.0, 3.0, 5.0}};
//        calcula_notafinal_situacao(turma);
//        check_expect(turma,(vector<Aluno>{Aluno{123, 4.0, 3.0, 8.0, 5.0, reprovado},
//                                          Aluno{124, 4.0, 6.0, 8.0, 6.0, aprovado},
//                                          Aluno{125, 4.0, 3.0, 5.0, 4.0, reprovado}}));
//
//        turma = {{126, 7.0, 4.5, 8.0}, {127, 7.0, 6.0, 8.0}, {128, 4.0, 4.5, 5.0}};
//        calcula_notafinal_situacao(turma);
//        check_expect(turma,(vector<Aluno>{Aluno{126, 7.0, 4.5, 8.0, 6.5, aprovado},
//                                          Aluno{127, 7.0, 6.0, 8.0, 7.0, aprovado},
//                                          Aluno{128, 4.0, 4.5, 5.0, 4.5, reprovado}}))
//    }

/********************** FUNÃ+O 3 - CALCULO MEDIA GERAL DA TURMA

1) Analise: A funþÒo que calcula a mÚdia geral da turma, recebe o arranjo turma e devolve a mÚdia geral da turma.

2) Tipos de dados:
    entrada: os dados dos alunos representados pelo vetor turma
    saÝda: um n·mero real representando a mÚdia geral da turma

3)EspecificÒo:
    3.1 assinatura:
    float media_geral(const vector<Aluno> &turma){
        float media;

        return media
    }

    3.2 prop¾sito: calcula a mÚdia geral da turma,
        recebe o arranjo turma e devolve a mÚdia geral da turma.

    3.3 exemplos:
        vector<Aluno> turma ={{123, 4.0, 3.0, 8.0, 5.0, reprovado}},
                              {124, 4.0, 6.0, 8.0, 6.0, aprovado}},
                              {125, 4.0, 3.0, 5.0, 4.0, reprovado}}}
        check_expect(media_geral(turma,5.0));
        turma = {{126, 7.0, 4.5, 8.0, 6.5, aprovado},
                 {127, 7.0, 6.0, 8.0, 7.0, aprovado},
                 {128, 4.0, 4.5, 5.0, 4.5, reprovado}};
        check_expect(media_geral(turma,6.0));

    3.4 repetiþÒo:
        quais varißveis serÒo calculadas? a soma de todas as notas finais
        como as varißveis serÒo inicializadas? soma = 0
        com as varißveis serÒo atualizadas? soma = soma + notafinal
**/

    double calcula_media_geral(const vector<Aluno> &turma){
        double media, soma = 0;
        for(Aluno a: turma){
            soma = soma + a.notafinal;
        }
        media = soma / turma.size();
        return media;
    }

/*    examples{
        vector<Aluno> turma ={{123, 4.0, 3.0, 8.0, 5.0, reprovado},
                              {124, 4.0, 6.0, 8.0, 6.0, aprovado},
                              {125, 4.0, 3.0, 5.0, 4.0, reprovado}};
        check_expect(calcula_media_geral(turma),5.0);
        turma = {{126, 7.0, 4.5, 8.0, 6.5, aprovado},
                 {127, 7.0, 6.0, 8.0, 7.0, aprovado},
                 {128, 4.0, 4.5, 5.0, 4.5, reprovado}};
        check_expect(calcula_media_geral(turma),6.0);
    }
*/
/********************* FUNÃ+O 4 - DETERMINA QUANTIDADE DE ALUNOS ACIMA DA M+DIA GERAL DA TURMA

1) Analise: A funþÒo que determina o n·mero de alunos acima da mÚdia geral da turma recebe o arranjo turma e a mÚdia
geral da turma e retorno o n·mero de alunos acima da mÚdia.

2) Tipos de dados:
    entrada:
    saÝda:

3)EspecificÒo:
    3.1 assinatura:

    3.2 prop¾sito:

    3.3 exemplos:

    3.4 repetiþÒo:
        quais varißveis serÒo calculadas?
        como as varißveis serÒo inicializadas?
        com as varißveis serÒo atualizadas?
**/

int numero_alunos_acima_media(const vector<Aluno> &turma, double media){
    int cont = 0;
    for(Aluno a: turma){
        if (a.notafinal > media){
            cont = cont + 1;
        }
    }
    return cont;
}


int main(){
    //run_tests();
    vector<Aluno> turma = le_notas_alunos();
    calcula_notafinal_situacao(turma);
    double mediag = calcula_media_geral(turma);
    int acima_media = numero_alunos_acima_media(turma, mediag);
    cout << "A media geral da turma foi: "<<mediag<<endl;
    cout << "O numero de alunos acima da mÚdia geral foi: "<<acima_media<<endl;
}
