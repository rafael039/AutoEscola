#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "telas.h"

using namespace std;

struct Aluno
{
    int matricula;
    char nome[100];
    char categoria[10];
    int turno;
    char sexo[10];
    char endereco[50];
    char estado[10];
    char cidade[50];
    char bairro[10];
    int num_casa;
    int idade;
    char cpf1[10];
    int telefone;
    int aula_teorica[5] = {1,1,1,1,1};
    int aula_pratica[10] = {1,1,1,1,1,1,1,1,1,1};
    int total_teorica=0;
    int total_pratica=0;
};

void media_frequencia(float presenca_aluno, float faltas_aluno, int qtaluno, float *media_totalP, float *media_totalF, int aulas)
{
    float mediaP_do_aluno;
    float mediaF_do_aluno;
    mediaP_do_aluno=(presenca_aluno/aulas);
    mediaF_do_aluno=(faltas_aluno/aulas);

    *media_totalP= (mediaP_do_aluno/qtaluno) * 100;
    *media_totalF= (mediaF_do_aluno/qtaluno)* 100;
}

void consulta() // funcao pesquisa se for colocar amanha eu digo se coloca ou nao
{
    Aluno aluno;
    char cpf[10];
    int l=10;
    int c=0;
    int i=0;
    int j=0;
    fstream in("ALUNOS.txt", ios::in);
    system("cls");
    tela_pesquisa(9,6);
    textbackground(LIGHTGRAY);
    textcolor(BLACK);
    gotoxy(23,6);
    fflush(stdin);
    gets(cpf);

    if(in.is_open())
    {
        in.read((char *)(&aluno),sizeof(Aluno));
        while( in && !in.eof())
        {
            if(strcmp(cpf,aluno.cpf1)==0)
            {
                c=0;
                gotoxy(44,6);
                cout<<aluno.nome;
                for(i=0; i<5; i++)
                {

                    if(aluno.aula_pratica[i]==0)
                    {
                        gotoxy(15+c,l+4);
                        textcolor(BLACK);
                        textbackground(RED);
                        cout<<"  1  ";
                    }
                    else
                    {
                        gotoxy(15+c,l+8);
                        textcolor(BLACK);
                        textbackground(GREEN);
                        cout<<"  0  ";

                    }
                    if(aluno.aula_teorica[i]==0)
                    {
                        gotoxy(15+c,l+2);
                        textcolor(BLACK);
                        textbackground(RED);
                        cout<<"  1  ";
                    }
                    else
                    {
                        gotoxy(15+c,l+2);
                        textcolor(BLACK);
                        textbackground(GREEN);
                        cout<<"  0  ";

                    }
                    textbackground(LIGHTGRAY);
                    textcolor(BLACK);
                    c+=20;
                }
            j+=1;
            l+=2;
            }
            in.read((char *)(&aluno),sizeof(Aluno));
        }
    }
    else
    {
        gotoxy(4,21);
        cout<<"ARQUIVO NAO FOI ABERTO!";
    }
    in.close();
}

void lista_teorica()// listar aulas teoricas
{
    Aluno aluno;
    int l=8;
    int c=0;
    int i;
    int qtaluno=0;
    float P_alunos=0, F_alunos=0;
    float *Media_presenca, *Media_faltas;
    Media_faltas= new float;
    Media_presenca= new float;

    fstream in("ALUNOS.txt", ios::in);
    system("cls");
    tela(9,5);
    textbackground(LIGHTGRAY);
    textcolor(BLACK);
    if(in.is_open())
    {
       in.read((char *)(&aluno),sizeof(Aluno));
       while( in && !in.eof())
        {
            qtaluno++;
            c=0;
            gotoxy(13,l);
            cout<<aluno.matricula;
            Sleep(tmp);
            gotoxy(23,l);
            cout<<aluno.nome;
            Sleep(tmp);
            for(i=0; i<5; i++)
            {
                if(aluno.aula_teorica[i]==0)
                {
                    gotoxy(61+c,l);
                    textcolor(BLACK);
                    textbackground(GREEN);
                    cout<<"  0  ";
                    P_alunos+=1;
                }
                else
                {
                    gotoxy(61+c,l);
                    textcolor(BLACK);
                    textbackground(RED);
                    cout<<"  1  ";
                    F_alunos+=1;
                }
                textbackground(LIGHTGRAY);
                textcolor(BLACK);
                c+=10;
            }
            l+=2;

            media_frequencia(P_alunos,F_alunos,qtaluno,Media_presenca,Media_faltas,5);
            in.read((char *)(&aluno),sizeof(Aluno));
        }
        gotoxy(18,32);
        cout<<""<<*Media_presenca<<"%";
        gotoxy(18,33);
        cout<<""<<*Media_faltas<<"%";
    }
    else
    {
        gotoxy(4,10);
        cout<<"ARQUIVO NAO FOI ABERTO!";
    }
    in.close();
    getch();
}
void cadastra()//funcao cadastra pra teste
{
    char *op;
    op = new char;
    Aluno aluno;
    ofstream out("ALUNOS.txt", ios::out | ios::app);
    if(out.is_open())
    {
        do
        {
            system("cls");
            fflush(stdin);
            cout<<"CODIGO: ";
            cin>>aluno.matricula;
            fflush(stdin);
            cout<<"NOME: ";
            gets(aluno.nome);
            fflush(stdin);
            cout<<"CATEGORIA (A)MOTO (B)CARRO (AB)CARRO E MOTO: ";
            gets(aluno.categoria);
            fflush(stdin);
            cout<<"TURNO (1)MANHA (2)TARDE: ";
            cin>>aluno.turno;
            fflush(stdin);
            cout<<"SEXO (M)MASCULINO (F)FEMININO: ";
            cin>>aluno.sexo;
            fflush(stdin);
            cout<<"ENDERECO: ";
            gets(aluno.endereco);
            fflush(stdin);
            cout<<"NUMERO: ";
            cin>>aluno.num_casa;
            fflush(stdin);
            cout<<"BAIRRO: ";
            gets(aluno.bairro);
            fflush(stdin);
            cout<<"CIDADE: ";
            gets(aluno.cidade);
            fflush(stdin);
            cout<<"ESTADO: ";
            gets(aluno.estado);
            fflush(stdin);
            cout<<"IDADE: ";
            cin>>aluno.idade;
            fflush(stdin);
            cout<<"CPF: ";
            gets(aluno.cpf1);
            fflush(stdin);
            cout<<"TELEFONE: ";
            cin >> aluno.telefone;
            //gets(aluno.telefone);
            fflush(stdin);

            out.write((const char *)(&aluno),sizeof(Aluno));
            cout<<"DESEJA CADASTRAR NOVO ALUNO:";
            *op=getch();
            *op=toupper(*op);
        }while(*op!='N');
    }
    else
    {
        cout<<"ARQUIVO NAO FOI ABERTO COM SUCESSO!\n";
    }
    out.close();
}

void freq_teorica(fstream &inout) //lancar frequencia teorica
{
    int turno;
    Aluno aluno;
    char presenca;
    int aula;
    int i;
    int linha=0;
    int indice=1;

    system("cls");
    frequencia_teorica(9,6);
    textcolor(BLACK);
    textbackground(LIGHTGRAY);
    gotoxy(36,4);
    cin>>turno;
    gotoxy(26,5);
    cin>>aula;
    aula--;
    cout<<endl;

    if(inout.is_open())//VER SE O ARQUIVO PODE SER ABERTO
    {
        i=0;
        while( inout && !inout.eof())//REPETE OS COMANDOS ATE ENCONTRAR O FIM DO ARQUIVO
        {
            inout.seekp((i) * sizeof(Aluno));
            inout.read((char *)(&aluno),sizeof(Aluno));

            aluno.total_teorica=aluno.aula_teorica[0]+aluno.aula_teorica[1]+aluno.aula_teorica[2]+aluno.aula_teorica[3]+aluno.aula_teorica[4];
            if(aluno.turno==turno)
            {
                if(aluno.turno==turno && aluno.total_teorica!=0 && aluno.aula_teorica[aula]==1)//DEFINE EM QUAL TURNO (MANHA OU TARDE) O ALUNO ESTÁ INCLUÍDO E SE ELE PERDEU ALGUMA AULA
                {
                    textcolor(BLACK);
                    textbackground(LIGHTGRAY);

                    gotoxy(14,11+linha);
                    cout<<aluno.matricula;
                    gotoxy(25,11+linha);
                    cout<<aluno.nome;

                    indice++;
                    textcolor(BLACK);
                    textbackground(LIGHTGRAY);

                    presenca=getch();
                    presenca=toupper(presenca);
                    if(presenca=='N')
                    {
                        pressionaBotao(74,31,"  NAO");
                        aluno.aula_teorica[aula]=1;
                        aluno.total_teorica=aluno.aula_teorica[0]+aluno.aula_teorica[1]+aluno.aula_teorica[2]+aluno.aula_teorica[3]+aluno.aula_teorica[4];
                        inout.seekp((i) * sizeof(Aluno));
                        inout.write((const char *)(&aluno),sizeof(Aluno));
                    }
                    else
                    {
                        pressionaBotao(37,31,"  SIM");
                        textcolor(BLACK);
                        textbackground(LIGHTGRAY);
                        aluno.aula_teorica[aula]=0;
                        aluno.total_teorica=aluno.aula_teorica[0]+aluno.aula_teorica[1]+aluno.aula_teorica[2]+aluno.aula_teorica[3]+aluno.aula_teorica[4];
                        inout.seekp((i) * sizeof(Aluno));
                        inout.write((const char *)(&aluno),sizeof(Aluno));
                    }
                    textcolor(BLACK);
                    textbackground(LIGHTGRAY);
                    cout<<endl;
                }
                else
                {
                    gotoxy(14,11+linha);
                    cout<<aluno.matricula;
                    gotoxy(25,11+linha);
                    cout<<aluno.nome;
                    aluno.total_teorica=aluno.aula_teorica[0]+aluno.aula_teorica[1]+aluno.aula_teorica[2]+aluno.aula_teorica[3]+aluno.aula_teorica[4];
                    gotoxy(55,11+linha);
                    cout<<"FREQUENCIA JA LANCADA!";
                }
            }

            inout.read((char *)(&aluno),sizeof(Aluno));
            linha++;
            i++;
        }
    }
    else
    {
        cout<<"ARQUIVO NAO PODE SER ABERTO!";
        system("pause");
    }
    inout.close();

}

void freq_pratica(fstream &inout)//lancar frequencia pratica
{
   Aluno aluno;
   char cpf[10];
   int i, aula;
   char presenca;

   system("cls");
   frequencia_pratica(9,6);
   textcolor(BLACK);
   textbackground(LIGHTGRAY);

   gotoxy(25,5);
   fflush(stdin);
   cin>>aula;
   aula--;

   gotoxy(23,8);
   fflush(stdin);
   gets(cpf); //COLETANDO O CPF

   if(inout.is_open())//VER SE O ARQUIVO PODE SER ABERTO
   {
        i=0;

        inout.read((char *)(&aluno),sizeof(Aluno));
        while( inout && !inout.eof())//REPETE OS COMANDOS ATE ENCONTRAR O FIM DO ARQUIVO
        {
            if(strcmp(aluno.cpf1,cpf)==0)
            {
               if(aluno.aula_pratica[aula]==1)
               {
                  aluno.total_teorica=aluno.aula_teorica[0]+aluno.aula_teorica[1]+aluno.aula_teorica[2]+aluno.aula_teorica[3]+aluno.aula_teorica[4];
                  if(aluno.total_teorica==0)
                  {
                      gotoxy(44,8);
                      cout<<aluno.nome;
                      presenca=getch();
                      presenca=toupper(presenca);
                      if(presenca=='N')
                        {
                             pressionaBotao(75,31,"  NAO");
                             aluno.aula_pratica[aula]=1;
                             aluno.total_pratica=0;
                             for(int j=0;j<10;j++)
                             {
                               aluno.total_pratica = aluno.total_pratica + aluno.aula_pratica[j];
                             }
                             inout.seekp((i) * sizeof(Aluno));
                             inout.write((const char *)(&aluno),sizeof(Aluno));
                             textcolor(BLACK);
                             textbackground(LIGHTGRAY);
                         }
                         else
                         {
                             pressionaBotao(37,31,"  SIM");
                             aluno.aula_pratica[aula]=0;
                             aluno.total_pratica=0;
                             for(int j=0;j<10;j++)
                             {
                               aluno.total_pratica = aluno.total_pratica + aluno.aula_pratica[j];
                             }
                             inout.seekp((i) * sizeof(Aluno));
                             inout.write((const char *)(&aluno),sizeof(Aluno));
                         }
                         textcolor(BLACK);
                         textbackground(LIGHTGRAY);
                         cout<<endl;
                     }
                     else
                     {
                         gotoxy(3,14);
                         cout<<"ALUNO NAO CONCLUIU AS AULAS TEORICAS!";
                     }

               }
               else
               {
                    gotoxy(3,14);
                    cout<<"FREQUENCIA DA AULA JA LANCADA!";
               }

            }
            inout.read((char *)(&aluno),sizeof(Aluno));
            i++;
        }
        textcolor(BLACK);
        textbackground(LIGHTGRAY);
   }
}

void frequencia(fstream &inout)
{
    int tipoAula;
    system("cls");
    textcolor(BLACK);
    textbackground(LIGHTGRAY);
    quadrado(1,1,34,114);
    gotoxy(46,2);
    cout <<"CONTROLE DE FREQUENCIA";
    gotoxy(3,5);
    cout << "LANCAR FREQUENCIA DAS AULAS (1)TEORICAS (2)PRATICAS: [   ]";
    gotoxy(58,5);
    cin >> tipoAula;

    if(tipoAula==1)
      freq_teorica(inout);
    else if(tipoAula==2)
      freq_pratica(inout);
    else
    {
      cout<<"OPÇÃO INVALIDA!";
      frequencia(inout);
    }

}
void lista_praticas()//lista as aulas praticas
{
    Aluno aluno;
    int l=8;
    int c=0;
    int i;
    int qtaluno=0;
    float P_alunos=0, F_alunos=0;
    float *MediaP_presenca, *MediaP_faltas;
     MediaP_faltas= new float;
     MediaP_presenca= new float;

    fstream in("ALUNOS.txt", ios::in);
    system("cls");
    tela(9,5);
    textbackground(LIGHTGRAY);
    textcolor(BLACK);
    gotoxy(45,2);
    cout<<"FREQUENCIA AULA PRATICAS";
    if(in.is_open())
    {
        qtaluno++;
       in.read((char *)(&aluno),sizeof(Aluno));
       while( in && !in.eof())
        {
            c=0;
            gotoxy(13,l);
            cout<<aluno.matricula;
            Sleep(tmp);
            gotoxy(23,l);
            cout<<aluno.nome;
            Sleep(tmp);
            for(i=0; i<5; i++)
            {
                if(aluno.aula_pratica[i]==0)
                {
                    gotoxy(61+c,l);
                    textcolor(BLACK);
                    textbackground(GREEN);
                    cout<<"  0  ";
                    P_alunos+=1;
                }
                else
                {
                    gotoxy(61+c,l);
                    textcolor(BLACK);
                    textbackground(RED);
                    cout<<"  1  ";
                    F_alunos+=1;
                }
                textbackground(LIGHTGRAY);
                textcolor(BLACK);





                c+=10;
            }

            media_frequencia(P_alunos,F_alunos,qtaluno,MediaP_presenca,MediaP_faltas,20);
            l+=2;
            in.read((char *)(&aluno),sizeof(Aluno));

        }
        gotoxy(18,32);
        cout<<" "<<*MediaP_presenca<<"%";
        gotoxy(18,33);
        cout<<" "<<*MediaP_faltas<<"%";
    }
    else
    {
        gotoxy(4,10);
        cout<<"ARQUIVO NAO FOI ABERTO!";
    }
    in.close();
    getch();
}
void lista()
{
    int tipoAula;
    system("cls");
    textcolor(BLACK);
    textbackground(LIGHTGRAY);
    quadrado(1,1,34,114);
    gotoxy(46,2);
    cout <<"LISTA AS FREQUENCIAS";
    gotoxy(3,5);
    cout << "DESEJA LISTAR FREQUENCIA DAS AULAS (1)TEORICAS (2)PRATICAS: [   ]";
    gotoxy(65,5);
    cin >> tipoAula;
    if(tipoAula==1)
      lista_teorica();
    else if(tipoAula==2)
      lista_praticas();
    else
    {
      cout<<"OPÇÃO INVALIDA!";
      lista();
    }
}
