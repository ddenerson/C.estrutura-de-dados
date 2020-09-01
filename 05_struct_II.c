#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#define TAM 10

/*
Com base em structs, suponha que � necess�rio armazenar
informa��es relacionadas � ve�culos, totalizando, no m�ximo, 10
ve�culos.

- Para cada ve�culo, dever�o ser fornecidos os seguintes dados:
- marca do ve�culo;
- Modelo;
- ano de fabrica��o;

placa (formato XXX-YYYY; onde X denota as letras e Y denota os
n�meros da placa).
*/





typedef struct
{
    char marca[20];
    char modelo[10];
    char placa[7];
    int  ano;
} Veiculo;

void ordernar(Veiculo *c)
{
    Veiculo aux;
    int i,j;

    for(i=0; i<TAM; i++)
    {
        for(j=i+1; j<TAM; j++)
        {
            if(c[i].ano > c[j].ano)
            {
                aux  = c[i];
                c[i] = c[j];
                c[j] = aux;
            }
        }
    }
}


void menu(int x)
{

    setlocale(LC_ALL,"portuguese");

    Veiculo v[TAM];

    char modelo[10];
    int n,c,p,i,j,ano,menor;
    ano=menor=j=i= p = c = n = 0;


    for(i = 0; i < TAM; i++)
    {
        strcpy(v[i].marca,"VAZIO");
        strcpy(v[i].modelo,"VAZIO");
        strcpy(v[i].placa,"VAZIO");
        v[i].ano = 0;
    }

    do
    {

        printf("\n ----- GARAGEM -------");
        printf("\n 01 -   Cadastro veiculos");
        printf("\n 02 -   Listar os veiculos");
        printf("\n 03 -   Listar os veiculos por ano de fabricacao");
        printf("\n 04 -   Listar os veiculos com o ano de fabricacao especificado pelo usuario");
        printf("\n 05 -   Listar os veiculos filtrando-se pelo modelo");
        printf("\n Escolha uma das op�oes ou aparte [0] para sair:");
        fflush(stdin);
        scanf("%d",&x);
        while(x < 0 || x > 5)
        {
            system("cls");
            printf("\n DIGITE ENTRE AS OPCOES [1-5],REDIGITE : ");
            fflush(stdin);
            scanf("%d",&x);
        }
        if(x != 0 || x != 5)
        {
            switch(x)
            {

            case 1:
                printf("\n _______________________");
                printf("\n CADASTRO");
                printf("\n ___________________");
                printf("\n Quantas carros deseja cadastra ?");
                fflush(stdin);
                scanf("%d",&n);

                p = c;

                while(n < 0)
                {
                    system("cls");
                    printf("\n VALOR DEVE SER MAIOR QUE ZERO,REDIGITE :");
                    fflush(stdin);
                    scanf("%d",&n);
                }

                for(i = p ; i < p + n; i++)
                {
                    system("cls");
                    printf("\n [%d] � Marca do veiculo:",(i+1));
                    fflush(stdin);
                    gets(v[i].marca);
                    printf("\n [%d]� Modelo:",(i+1));
                    fflush(stdin);
                    gets(v[i].modelo);
                    printf("\n [%d]� Ano:",(i+1));
                    fflush(stdin);
                    scanf("%d",&v[i].ano);
                    printf("\n [%d]� Placa:",(i+1));
                    fflush(stdin);
                    gets(v[i].placa);
                    c++;
                }

                printf("\n CADASTRO FEITO COM SUCESSO");
                printf("\n APARTE QUALQUER TECLA PARA SAIR ");
                getch();

                // ordernar(&v);

                break;
            case 2:
                printf("\n-----------------------------------");
                printf("\n |LISTA DE VEICULOS CADASTRADO| ");
                printf("\n___________________________________");
                printf("\n___________________________________");

                printf("\n ------------------------------------");

                if(v[0].ano == 0)
                {
                    printf("\n A LISTA AINDA N�O FOI PRENCHIDA, POR FAVOR CADASTRE VE�CULOS");
                }
                else
                {
                    if(v[0].ano == 0)
                    {

                        getch();
                    }
                    else
                    {
                        for(i = 0; i < c; i++)
                        {
                            printf("\n [%d]� MARCA DO VE�CULO:%s ",(i+1),v[i].marca);
                            printf("\n [%d]� MODELO:%s",(i+1),v[i].modelo);
                            printf("\n [%d]� ANO:%d",(i+1),v[i].ano);
                            printf("\n [%d]� PLACA :%s",(i+1),v[i].placa);
                            printf("\n /-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/");
                        }
                    }
                }
                printf("\n -----------------------------------");
                printf("\n APARTE QUALQUER TECLA PARA SAIR ");
                getch();
                break;
            case 3:
                printf("\n-----------------------------------");
                printf("\n LISTA DE VEICULO POR ANO DE FABRICA��O");
                printf("\n___________________________________");
                printf("\n___________________________________");
                printf("\n ------------------------------------");

                if(v[0].ano == 0)
                {
                    printf("\n A LISTA AINDA N�O FOI PRENCHIDA, POR FAVOR CADASTRE VE�CULOS");
                }
                else
                {
                    if(v[0].ano == 0)
                    {

                        getch();
                    }
                    else
                    {
                        for(i = 0; i < c; i++)
                        {
                            printf("\n [%d]� MARCA DO VE�CULO:%s ",(i+1),v[i].marca);
                            printf("\n [%d]� MODELO:%s",(i+1),v[i].modelo);
                            printf("\n [%d]� PLACA:%s",(i+1),v[i].placa);
                            printf("\n [%d]� ANO:%d",(i+1),v[i].ano);
                            printf("\n /-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/");

                        }
                    }
                }
                printf("\n -----------------------------------");
                printf("\n APARTE QUALQUER TECLA PARA SAIR ");
                getch();

                break;
            case 4:

                printf("\n-----------------------------------");
                printf("\n LISTAGEM VEICULOS");
                printf("\n___________________________________");
                printf("\n ");
                if(v[0].ano == 0)
                {
                    printf("\n A LISTA AINDA N�O FOI PRENCHIDA, POR FAVOR CADASTRE VE�CULOS");
                }
                else
                {
                    if(v[0].ano == 0)
                    {

                        getch();
                    }
                    else
                    {
                        ano = 0;
                        printf("\n Digite o ano de fabrica��o:");
                        fflush(stdin);
                        scanf("%d",&ano);
                        while(ano < 0)
                        {
                            system("cls");
                            printf("\n O VALOR DEVE SER SUPERIOR A ZERO,REDIGITE:");
                            fflush(stdin);
                            scanf("%d",&ano);
                        }
                        printf("\n");

                        for(int i = 0; i < c; i++)
                        {
                            if(v[i].ano == ano)
                            {
                                printf("\n ESSE S�O OS VE�CULOS FABRICADOS NESSE PERIODO:");
                                printf("\n [%d]� MARCA DO VE�CULO:%s ",(i+1),v[i].marca);
                                printf("\n [%d]� MODELO:%s",(i+1),v[i].modelo);
                                printf("\n [%d]� PLACA:%s",(i+1),v[i].placa);
                                printf("\n /-/-/-/-/-/-/-/-/APARTE TECLA PARA CONTINUAR A LISTAGEM-/-/-/-/-/-/-/-/-/-/-/-/");
                                getch();
                            }
                        }
                    }
                }
                printf("\n --------------FINALIZADO---------------------");
                printf("\n APARTE QUALQUER TECLA PARA SAIR ");
                getch();

                break;
            case 5:

                printf("\n-----------------------------------");
                printf("\n VEICULOS FILTRADO POR MODELO");
                printf("\n___________________________________");
                printf("\n ");

                printf("\n DIGITE O NOME DO MODELO,QUE DESEJA BUSCAR:");
                fflush(stdin);
                gets(modelo);

                for(i = 0; i < TAM; i++)
                {
                    if(strcmp(modelo,v[i].modelo)==0)
                    {
                        printf("\n ENCONTRADO");
                        printf("\n [%d]� MODELO:%s",(i+1),v[i].modelo);
                        printf("\n [%d]� PLACA:%s",(i+1),v[i].placa);
                        printf("\n [%d]� Ano:%d",(i+1),v[i].ano);
                        printf("\n /-/-/-/-/-/-/-/-/APARTE TECLA PARA CONTINUAR A LISTAGEM-/-/-/-/-/-/-/-/-/-/-/-/");
                        getch();
                    }
                }
                printf("\n --------------FINALIZADO---------------------");
                printf("\n APARTE QUALQUER TECLA PARA SAIR ");
                getch();

                break;
            default:
                break;
            }

        }
        system("cls");
    }
    while(x != 0);


}


int main()
{
    int opc;

    menu(opc);


    return 0;
}






