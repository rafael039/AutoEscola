#include <conio.h>
#include <conio2.h>
#include <windows.h>
#define MAX 50
#define tmp 50

using namespace std;

void tabela(int coluna, int linha)
{
    gotoxy(coluna,linha-1);//coluna da tabela
    cout<<"\xcb";
    gotoxy(coluna,linha+1);//coluna da tabela
    cout<<"\xca";
    gotoxy(coluna,linha);//coluna da tabela
    cout<<"\xba";

}
void quadrado(int col, int lin, int alt, int larg)
{
   textbackground(LIGHTGRAY);
   textcolor(BLACK);

   gotoxy(col,lin); printf("\xC9");
   gotoxy((col+larg),lin); printf("\xBB");
   gotoxy(col,(lin+alt)); printf("\xC8");
   gotoxy((col+larg),(lin+alt)); printf("\xBC");

   for(int i=(col+1);i<(col+larg);i++)
   {
      gotoxy(i,lin); printf("\xCD");
      gotoxy(i,(lin+alt));   printf("\xCD");
   }
   for(int j=(lin+1);j<(lin+alt);j++)
   {
       gotoxy(col,j);   printf("\xBA");
       gotoxy((col+larg),j);  printf("\xBA");
   }

   printf("\n\n");
}
void tela(int coluna, int linha)//9,6
{
    quadrado(1,1,34,114);
    quadrado(coluna-3,linha-1,2,103);
    gotoxy(45,2);
    cout<<"FREQUENCIA AULA TEORICA";
    gotoxy(coluna,linha);
    cout<<"MATRICULA";
    gotoxy(coluna+27,linha);
    cout<<"NOME";
    gotoxy(coluna+52,linha);
    cout<<"AULA 1";
    gotoxy(coluna+62,linha);
    cout<<"AULA 2";
    gotoxy(coluna+72,linha);
    cout<<"AULA 3";
    gotoxy(coluna+82,linha);
    cout<<"AULA 4";
    gotoxy(coluna+92,linha);
    cout<<"AULA 5";
    gotoxy(95,31);
    cout<<"PRESENCA";
    gotoxy(95,33);
    cout<<"FALTAS";
    gotoxy(3,31);
    cout<<"MEDIA DE FREQUENCIA DA TURMA";
    gotoxy(3,32);
    cout<<"MEDIA PRESENCA: ";
    gotoxy(3,33);
    cout<<"MEDIA FALTAS..: ";

    tabela(20,linha);
    tabela(58,linha);
    tabela(68,linha);
    tabela(78,linha); //DIVISAO DAS COLUNAS DA TABELA
    tabela(88,linha);
    tabela(98,linha);

    textcolor(BLACK);
    textbackground(GREEN);
    gotoxy(88,31);
    cout<<"  0  ";

    textcolor(BLACK);
    textbackground(RED);
    gotoxy(88,33);
    cout<<"  1  ";
}
void tela_pratica(int coluna, int linha)
{
    quadrado(1,1,34,114);
    quadrado(coluna-3,linha-1,2,102);
    gotoxy(45,2);
    cout<<"FREQUENCIA AULA PRATICA";
    gotoxy(coluna-1,linha);
    cout<<"CPF DO ALUNO";
    gotoxy(coluna+28,linha);
    cout<<"NOME";
    quadrado(coluna-3,linha+1,2,102);
    gotoxy(coluna-3,(linha+1));
    cout<<"\xcc";
    gotoxy(coluna+99,(linha+1));
    cout<<"\xb9";

    quadrado(coluna-3,linha+3,2,102);
    gotoxy(coluna-3,(linha+3));
    cout<<"\xcc";
    gotoxy(coluna+99,(linha+3));
    cout<<"\xb9";

    gotoxy(coluna-1,linha+2);
    cout<<"AULA 1";
    gotoxy(coluna+9,linha+2);
    cout<<"AULA 2";
    gotoxy(coluna+19,linha+2);
    cout<<"AULA 3";
    gotoxy(coluna+29,linha+2);
    cout<<"AULA 4";
    gotoxy(coluna+39,linha+2);
    cout<<"AULA 5";
    gotoxy(coluna+49,linha+2);
    cout<<"AULA 6";
    gotoxy(coluna+59,linha+2);
    cout<<"AULA 7";
    gotoxy(coluna+69,linha+2);
    cout<<"AULA 8";
    gotoxy(coluna+79,linha+2);
    cout<<"AULA 9";
    gotoxy(coluna+90,linha+2);
    cout<<"AULA 10";
    gotoxy(95,31);
    cout<<"PRESENCA";
    gotoxy(95,33);
    cout<<"FALTAS";

    tabela(21,linha);
    tabela(35,linha);
    tabela(42,linha);
    tabela(16,linha+2);
    tabela(26,linha+2);
    tabela(36,linha+2);
    tabela(46,linha+2);
    tabela(56,linha+2);
    tabela(66,linha+2);
    tabela(76,linha+2);
    tabela(86,linha+2);
    tabela(96,linha+2);

    tabela(16,linha+4);
    gotoxy(16,(linha+3));
    cout<<"\xce";
    tabela(26,linha+4);
    gotoxy(26,(linha+3));
    cout<<"\xce";
    tabela(36,linha+4);
    gotoxy(36,(linha+3));
    cout<<"\xce";
    tabela(46,linha+4);
    gotoxy(46,(linha+3));
    cout<<"\xce";
    tabela(56,linha+4);
    gotoxy(56,(linha+3));
    cout<<"\xce";
    tabela(66,linha+4);
    gotoxy(66,(linha+3));
    cout<<"\xce";
    tabela(76,linha+4);
    gotoxy(76,(linha+3));
    cout<<"\xce";
    tabela(86,linha+4);
    gotoxy(86,(linha+3));
    cout<<"\xce";
    tabela(96,linha+4);
    gotoxy(96,(linha+3));
    cout<<"\xce";


    textcolor(BLACK);
    textbackground(GREEN);
    gotoxy(88,31);
    cout<<"  0  ";

    textcolor(BLACK);
    textbackground(RED);
    gotoxy(88,33);
    cout<<"  1  ";

    gotoxy(3,33);
}
void desenhaBotao(int coluna, int linha,int cor, char msg[MAX])
{

    int i, j;
    textcolor(cor);
    gotoxy(coluna,linha);
    for(i=1; i<=25; i++)
    {
        printf("\xdb");
    }
    gotoxy(coluna,linha+1);
    for(i=1; i<=25; i++)
    {
        printf("\xdb");
    }
    gotoxy(coluna,linha+2);
    for(i=1; i<=25; i++)
    {
        printf("\xdb");
    }
    gotoxy(coluna+9,linha+1);
    textcolor(BLACK);
    textbackground(CYAN);
    printf(" %s ", msg);
}

void pressionaBotao(int coluna, int linha, char msg[MAX])
{
    desenhaBotao(coluna,linha,3,msg); //cor branca
    desenhaBotao(coluna+1,linha+1,8,msg); // cor BRANCA
    Sleep(tmp);
    desenhaBotao(coluna+1,linha+1,0,msg); //cor cinza
    Sleep(tmp);
    desenhaBotao(coluna,linha,3,msg); //cor branca
    Sleep(tmp);
}

void frequencia_teorica(int coluna, int linha)
{
     quadrado(1,1,34,114);
     gotoxy(45,2);
     cout<<"FREQUENCIA AULA TEORICA";
     gotoxy(coluna,linha-2);
     cout<<"TURMA (1)MANHA (2)TARDE: [   ]";
     gotoxy(coluna,linha-1);
     cout<<"NUMERO DA AULA:[   ]";
     gotoxy(coluna,linha+1);
     cout<<"MATRICULA";
     gotoxy(coluna+30,linha+1);
     cout<<"NOME";
     quadrado(coluna-2,linha+25,2,20);
     gotoxy(coluna-1,linha+26);
     cout<<"ALUNO PRESENTE S/N?";
     quadrado(coluna-2,linha,2,103);
     tabela(20,linha+1);

     desenhaBotao(38,linha+26,0," SIM ");
     desenhaBotao(37,linha+25,3," SIM ");
     desenhaBotao(75,linha+26,0," NAO ");
     desenhaBotao(74,linha+25,3," NAO ");
     gotoxy(3,33);
}
void frequencia_pratica(int coluna, int linha)//9,6
{
    quadrado(1,1,34,114);
    quadrado(coluna-3,linha+1,2,102);
    gotoxy(45,2);
    cout<<"FREQUENCIA AULA PRATICA";
    gotoxy(coluna-1,linha-1);
    cout<<"NUMERO DA AULA [   ] ";
    gotoxy(coluna-1,linha+2);
    cout<<"CPF DO ALUNO";
    gotoxy(coluna+28,linha+2);
    cout<<"NOME";

    quadrado(coluna-2,linha+25,2,24);
    gotoxy(coluna-1,linha+26);
    cout<<"CONFIRMAR PRESENSA S/N?";

    tabela(21,linha+2);
    tabela(35,linha+2);
    tabela(42,linha+2);

    desenhaBotao(38,linha+26,0," SIM ");
    desenhaBotao(37,linha+25,3," SIM ");
    desenhaBotao(75,linha+26,0," NAO ");
    desenhaBotao(74,linha+25,3," NAO ");
}
void tela_pesquisa(int coluna, int linha)//9,6
{

    quadrado(1,1,34,114);
    quadrado(coluna-3,linha-1,2,102);
    quadrado(coluna-3,linha+1,2,102);
    gotoxy(coluna-3,(linha+1));
    cout<<"\xcc";
    gotoxy(coluna+99,(linha+1));
    cout<<"\xb9";

    quadrado(coluna-3,linha+3,2,102);
    gotoxy(coluna-3,(linha+3));
    cout<<"\xcc";
    gotoxy(coluna+99,(linha+3));
    cout<<"\xb9";


    quadrado(coluna-3,linha+5,2,102);
    gotoxy(coluna-3,(linha+5));
    cout<<"\xcc";
    gotoxy(coluna+99,(linha+5));
    cout<<"\xb9";

    quadrado(coluna-3,linha+7,2,102);
    gotoxy(coluna-3,(linha+7));
    cout<<"\xcc";
    gotoxy(coluna+99,(linha+7));
    cout<<"\xb9";

    quadrado(coluna-3,linha+9,2,102);
    gotoxy(coluna-3,(linha+9));
    cout<<"\xcc";
    gotoxy(coluna+99,(linha+9));
    cout<<"\xb9";

    quadrado(coluna-3,linha+11,2,102);
    gotoxy(coluna-3,(linha+11));
    cout<<"\xcc";
    gotoxy(coluna+99,(linha+11));
    cout<<"\xb9";

    gotoxy(coluna+4,linha+4);
    cout<<"AULA 1";
    gotoxy(coluna+24,linha+4);
    cout<<"AULA 2";
    gotoxy(coluna+44,linha+4);
    cout<<"AULA 3";
    gotoxy(coluna+64,linha+4);
    cout<<"AULA 4";
    gotoxy(coluna+84,linha+4);
    cout<<"AULA 5";

    gotoxy(coluna+4,linha+10);
    cout<<"AULA 1";
    gotoxy(coluna+24,linha+10);
    cout<<"AULA 2";
    gotoxy(coluna+44,linha+10);
    cout<<"AULA 3";
    gotoxy(coluna+64,linha+10);
    cout<<"AULA 4";
    gotoxy(coluna+84,linha+10);
    cout<<"AULA 5";

    gotoxy(45,2);
    cout<<"PESQUISA DE AULOS POR CPF";
    gotoxy(coluna-1,linha);
    cout<<"CPF DO ALUNO";
    gotoxy(coluna+27,linha);
    cout<<"NOME";
    gotoxy(coluna+32,linha+2);
    cout<<"FREQUENCIA AULA TEORICA";
    gotoxy(coluna+32,linha+8);
    cout<<"FREQUENCIA AULA PRATICA";

    gotoxy(95,31);
    cout<<"PRESENCA";
    gotoxy(95,33);
    cout<<"FALTAS";

    tabela(21,linha);
    tabela(34,linha);
    tabela(41,linha);

    tabela(26,linha+4);
    tabela(46,linha+4);
    tabela(66,linha+4);
    tabela(86,linha+4);

    tabela(26,linha+6);
    tabela(46,linha+6);
    tabela(66,linha+6);
    tabela(86,linha+6);

    gotoxy(26,linha+5);
    cout<<"\xce";
    gotoxy(46,linha+5);
    cout<<"\xce";
    gotoxy(66,linha+5);
    cout<<"\xce";
    gotoxy(86,linha+5);
    cout<<"\xce";

    tabela(26,linha+12);
    tabela(46,linha+12);
    tabela(66,linha+12);
    tabela(86,linha+12);

    tabela(26,linha+10);
    tabela(46,linha+10);
    tabela(66,linha+10);
    tabela(86,linha+10);


    gotoxy(26,linha+11);
    cout<<"\xce";
    gotoxy(46,linha+11);
    cout<<"\xce";
    gotoxy(66,linha+11);
    cout<<"\xce";
    gotoxy(86,linha+11);
    cout<<"\xce";


    textcolor(BLACK);
    textbackground(GREEN);
    gotoxy(88,31);
    cout<<"  0  ";

    textcolor(BLACK);
    textbackground(RED);
    gotoxy(88,33);
    cout<<"  1  ";
}
void logo(int coluna,int linha)
{
    textcolor(CYAN);
    quadrado(coluna-2,linha-1,7,86);
    gotoxy(coluna,linha);
    cout<<"BBBBBB  BBBBBB   BBBBBB   BBBBB   BBB  BBB  BBBBBB  BB   BB    BBBB   BBB    BBB "<<endl;
    gotoxy(coluna,linha+1);
    cout<<"BBB     BB   BB  BB      BBB BBB  BBB  BBB  BB      BBB  BB  BBBBBBB  BBB   BBBBB"<<endl;
    gotoxy(coluna,linha+2);
    cout<<"BBBBBB  BBBBBBB  BBBBB   BB    BB BBB  BBB  BBBBB   BBBB BB  BB       BBB  BB   BB"<<endl;
    gotoxy(coluna,linha+3);
    cout<<"BBB     BB  BB   BB      BB  B BB BBB  BBB  BB      BB BBBB  BB       BBB BBBBBBBBB"<<endl;
    gotoxy(coluna,linha+4);
    cout<<"BBB     BB   BB  BBBBBBB  BBBBBBB  BBBBBB   BBBBBB  BB  BBB   BBBBBB  BBB BB     BB"<<endl;
    gotoxy(coluna,linha+5);
    cout<<"                               BBB                                                 "<<endl;
}
void desenhaBotaoG(int coluna, int linha,int cor, char msg[50])
{

    int i, j;
    textcolor(cor);
    gotoxy(coluna,linha);
    for(i=1; i<=30; i++)
    {
        printf("\xdb");
    }
    gotoxy(coluna,linha+1);
    for(i=1; i<=30; i++)
    {
        printf("\xdb");
    }
    gotoxy(coluna,linha+2);
    for(i=1; i<=30; i++)
    {
        printf("\xdb");
    }
    gotoxy(coluna+5,linha+1);
    textcolor(BLACK);
    textbackground(CYAN);
    printf(" %s ", msg);
}
void tela_de_frequencia(int coluna, int linha)//9,6
{
    system("cls");
    quadrado(1,1,34,114);
    logo(coluna+6,linha);
    desenhaBotaoG(coluna,linha+15,0," REALIZAR CHAMADA ");
    desenhaBotaoG(coluna-1,linha+14,3,"  REALIZAR CHAMADA");

    desenhaBotaoG(coluna+34,linha+15,0,"    PESQUISAR    ");
    desenhaBotaoG(coluna+33,linha+14,3,"    PESQUISAR    ");

    desenhaBotaoG(coluna+68,linha+15,0,"      LISTAR      ");
    desenhaBotaoG(coluna+67,linha+14,3,"      LISTAR      ");

    desenhaBotao(coluna+69,linha+25,0,"VOLTAR      ");
    desenhaBotao(coluna+68,linha+24,3,"VOLTAR      ");

    textcolor(BLACK);
    textbackground(7);
    quadrado(coluna-2,29,5,61);
    gotoxy(coluna,30);
    cout<<"TECLE (R)- PARA REALIZAR CHAMADA";
    gotoxy(coluna,31);
    cout<<"TECLE (P)- PARA PESQUISAR HISTORICO DE FREQUENCIA DO ALUNO";
    gotoxy(coluna,32);
    cout<<"TECLE (L)- PARA LISTAR HISTORICO DE FREQUENCIA DA TURMA";
    gotoxy(coluna,33);
    cout<<"TECLE (v)- PARA VOLTAR";
}
void pressionaBotaoG(int coluna, int linha, char msg[MAX])
{
    desenhaBotaoG(coluna,linha,3,msg); //cor branca
    desenhaBotaoG(coluna+1,linha+1,8,msg); // cor BRANCA
    Sleep(tmp);
    desenhaBotaoG(coluna+1,linha+1,0,msg); //cor cinza
    Sleep(tmp);
    desenhaBotaoG(coluna,linha,3,msg); //cor branca
    Sleep(tmp);
}
