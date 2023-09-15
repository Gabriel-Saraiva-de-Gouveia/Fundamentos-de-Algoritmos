/**
Projete um programa que possa auxiliar um professor a calcular a nota final de cada um dos alunos de uma turma
(sabendo-se que a nota final � calculada pela m�dia aritm�tica simples das notas de 3 avalia��es) e determinar
se o aluno foi aprovado (m�dia >= 6) ou n�o na disciplina. Al�m disso, o programa deve calcular a m�dia geral
da turma e determinar quantos alunos ficaram com notas acima dessa m�dia.

Inicialmente devemos projetar fun��es auxiliares, de prop�sito simples, para auxiliar a resolver o problema em quest�o.

1) ler os dados dos alunos (tr�s notas para cada um) e colocar os dados em um arranjo que contenha os dados de cada aluno da turma.
2) calcular a nota final e determinar a situa��o de cada aluno (aprovado ou reprovado).
3) calcular a m�dia geral da turma.
4)  determinar quantos alunos obtiveram nota final maior que a m�dia geral da turma.

Conv�m criar ent�o uma estrutura de dados que possa guardar as informa��es de cada um dos alunos da turma em uma mesma vari�vel.
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
A fun��o de leitura de dados deve colocar os dados dos alunos em um arranjo de alunos, vamos cham�-lo de turma:
vector<Aluno> turma = {};

1) A fun��o de leitura de dados colocar� informa��es fornecidas pelo professor para as notas 1, 2 e 3,
referente aos n alunos da turma. Por isso essa fun��o n�o tem par�metro de entrada, somente de sa�da.

2) A fun��o que calcula a nota final e a situa��o de cada aluno, recebe o arranjo turma e determina os
campos notafinal e situa��o de cada aluno. O arranjo pode ser um par�metro passado por refer�ncia, e nesse caso, o retorno da fun��o � void.

3) A fun��o que calcula a m�dia geral da turma, recebe o arranjo turma e devolve a m�dia geral da turma.

4) A fun��o que determina o n�mero de alunos acima da m�dia geral da turma recebe o arranjo turma e a m�dia
geral da turma e retorno o n�mero de alunos acima da m�dia.

******************** FUN��O 1 - LEITURA DE DADOS

1) Analise: A fun��o de leitura de dados (RA e notas) deve colocar os dados dos alunos
fornecidos pelo professor em um arranjo de alunos (turma)
2) Tipos de dados:
    entrada: nenhuma
    sa�da: um arranjo de alunos ==> vector<Aluno> turma = {};

3)Especific�o:
    3.1 assinatura:
        vector<Aluno> le_notas_alunos(){
            vector<Aluno> turma = {};
            ...
            return turma;
        }

    3.2 prop�sito: ler dados (RA e notas) dos alunos fornecidos pelo professor e
    colocar as informa��es em turma
    3.3 exemplos: depende dos dados digitados pelo professor
    3.4 repeti��o:
        quais vari�veis ser�o calculadas? ser�o lidas as notas de um aluno de cada vez
        como as vari�veis ser�o inicializadas? turma = {}
        com as vari�veis ser�o atualizadas? os dados do aluno em quest�o ser�o adicionados ao final do arranjo turma

//vers�o parada do la�o pela quantidade de alunos na turma
//Prop�sito: ler dados (RA e notas) dos alunos fornecidos pelo professor e colocar as informa��es em turma
//    vector<Aluno> le_notas_alunos(){
//            vector<Aluno> turma = {};
//            Aluno a1;
//            int n;
//            cout<<"Entre com a quantidade de alunos na turma: ";
//            cin>>n;
//            for(int i = 0; i < n; i++){
//                cout<<"Entre com o RA do aluno ou um n�mero negativo para parar: ";
//                cin>>a1.RA;
//                cout<<"Entre com as tr�s notas do aluno: ";
//                cin>>a1.nota1>>a1.nota2>>a1.nota3;
//                turma.push_back(a1);
//            }
//            return turma;
//    }

**/

//vers�o parada do la�o pelo finalizados (RA == a n�mero negativo)
//Prop�sito: ler dados (RA e notas) dos alunos fornecidos pelo professor e colocar as informa��es em turma
    vector<Aluno> le_notas_alunos(){
            vector<Aluno> turma = {};
            Aluno a1;
            cout<<"Entre com o RA do aluno ou um n�mero negativo para parar: ";
            cin>>a1.RA;
            while (a1.RA >= 0){
                cout<<"Entre com as tr�s notas do aluno: ";
                cin>>a1.nota1>>a1.nota2>>a1.nota3;
                turma.push_back(a1);
                cout<<"Entre com o RA do aluno ou um n�mero negativo para parar: ";
                cin>>a1.RA;
            }
            return turma;
    }

/******************** FUN��O 2 - CALCULO NOTA FINAL E SITUA��O

1) Analise: A fun��o que calcula a nota final e a situa��o de cada aluno,
recebe o arranjo turma e determina os campos notafinal e situa��o de cada aluno.
O arranjo pode ser um par�metro passado por refer�ncia, e nesse caso,
o retorno da fun��o � void.

2) Tipos de dados:
    entrada: um arranjo de alunos (turma)
    sa�da: void (o arranjo de entrada ser� passado por refer�ncia)

3)Especific�o:
    3.1 assinatura:
        void calcula_notafinal_situacao(vector<Aluno> &turma){

        }
    3.2 prop�sito: calcular a nota final e a situa��o de cada aluno, com base nas notas
    das tr�s avalia��es e sabendo-se que a nota final � a m�dia aritm�tia simples das tr�s
    notas e a situa��o � aprovado para notafinal >= 6 e reprovado caso contr�rio.
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

    3.4 repeti��o:
        quais vari�veis ser�o calculadas? notafinal e situa��o de cada um dos alunos
        como as vari�veis ser�o inicializadas? notafinal ser� a m�dia aritm�tica simples das tr�s notas de cada aluno
        e situa��o ser� aprovado se notafinal > = 6 e reprovado caso contr�rio
        com as vari�veis ser�o atualizadas? com as notas do pr�ximo aluno

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


/********************** FUN��O 3 - CALCULO MEDIA GERAL DA TURMA

1) Analise: A fun��o que calcula a m�dia geral da turma, recebe o arranjo turma e devolve a m�dia geral da turma.

2) Tipos de dados:
    entrada: nota final dos alunos (a.notafinal)
    sa�da: um valor do tipo real que representa a m�dia geral da turma.

3)Especific�o:
    3.1 assinatura:
        float media_final_turma (

    3.2 prop�sito:

    3.3 exemplos:

    3.4 repeti��o:
        quais vari�veis ser�o calculadas?
        como as vari�veis ser�o inicializadas?
        com as vari�veis ser�o atualizadas?
**/

/********************* FUN��O 4 - DETERMINA QUANTIDADE DE ALUNO ACIMA DA M�DIA GERAL DA TURMA

1) Analise: A fun��o que determina o n�mero de alunos acima da m�dia geral da turma recebe o arranjo turma e a m�dia
geral da turma e retorno o n�mero de alunos acima da m�dia.

2) Tipos de dados:
    entrada:
    sa�da:

3)Especific�o:
    3.1 assinatura:

    3.2 prop�sito:

    3.3 exemplos:

    3.4 repeti��o:
        quais vari�veis ser�o calculadas?
        como as vari�veis ser�o inicializadas?
        com as vari�veis ser�o atualizadas?
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
    //calcula notafinal e situa��o de todos os alunos
    //calcula m�dia geral da turma
    //determina qtde de alunos acima da m�dia geral

}
