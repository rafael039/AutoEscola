#include <iostream>
#include "funcoes.h"

using namespace std;

int main()
{
    char opcao;
    do
    {
        tela_de_frequencia(9,6);
        opcao=getch();
        opcao=toupper(opcao);
        switch(opcao)
        {
            case'R': {
                        pressionaBotaoG(9,20," REALIZAR CHAMADA ");
                        textcolor(BLACK);
                        textbackground(LIGHTGRAY);
                        fstream inout("ALUNOS.txt", ios::in | ios::out);//ABRI O ARQUIVO EM MODO LEITURA E GRAVACAO
                        frequencia(inout);
                        inout.close();
                     }
                break;
            case'P':pressionaBotaoG(42,20,"    PESQUISAR    ");
                    textcolor(BLACK);
                    textbackground(LIGHTGRAY);
                    consulta();
                    getch();
                break;
            case'L':pressionaBotaoG(76,20,"      LISTAR      ");
                    textcolor(BLACK);
                    textbackground(LIGHTGRAY);
                    lista();
                break;
            case'V': pressionaBotao(77,30,"VOLTAR      ");
                        textcolor(BLACK);
                        textbackground(LIGHTGRAY);

                break;
            default: cout<<"OPCAO INVALIDA!";
                break;
        }

    }while(opcao!='V');
}
