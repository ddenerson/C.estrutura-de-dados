#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <string.h>
#define  TAM 10

/*

Desenvolva um programa para vendas de passagens de ônibus. Defina uma
STRUCT, crie o menu de opções e todas as funções necessárias para manipular
esta STRUCT;

Cadastrar pessoa;

Vender passagem;

Imprimir comprovante;


*/



typedef struct
{
    char nome[20];
    int id;
    char tel[11];
    char ori[20];
    char des[20];
} Cliente;


void menu(int opc)
{

    setlocale(LC_ALL,"portuguese");


    Cliente c[TAM];
    char nome[20];
    int i,n,p,pos,aux;
    i = aux = p=0;

    for(int i = 0 ; i < TAM; i++)
    {
        strcpy(c[i].nome,"VAZIO");
        strcpy(c[i].tel,"VAZIO");
        strcpy(c[i].ori,"VAZIO");
        strcpy(c[i].des,"VAZIO");
        c[i].id  = 0;
    }
    do
    {


        printf("\n 01 - |CADASTRO|");
        printf("\n 02 - |VENDAS DE PASSAGEM|");
        printf("\n 03 - |IMPRIMIR COMPROVANTE|");
        printf("\n DIGITE UMA DAS OPCOES OU [ZERO]PARA SAIR:");
        fflush(stdin);
        scanf("%d",&opc);
        while(opc < 0 || opc > 3)
        {
            system("cls");
            printf("\n COLOCA UMA DAS OPCOES [1-3],REDIGITE OU [ZERO] PARA SAIR:");
            fflush(stdin);
            scanf("%d",&opc);
        }
        if(opc != 0)
        {
            switch(opc)
            {
            case 1:

                printf("\n Quantos clientes deseja cadastrar:");
                fflush(stdin);
                scanf("%d",&n);

                aux = p;

                for(i = p; i < aux + n; i++)
                {

                    system("cls");
                    printf("\n ---------------");
                    printf("\n [%d°] Nome:",(i+1));
                    fflush(stdin);
                    gets(c[i].nome);
                    printf("\n [%d°] Telefone:",(i+1));
                    fflush(stdin);
                    gets(c[i].tel);
                    p++;
                }
                printf("-----------------------");
                printf("\n CADASTRO FEITO COM SUCESSO");
                printf("\n");
                printf("\n APERTE QUALQUER TECLA");
                getch();
                system("cls");
                break;

            case 2:



                printf("\n --- E NECESSARIO TER CADASTRO PARA COMPRAR PASSAGEM ---");
                printf("\n --------------------------------------------------------");
                printf(" \n Digite um nome: ");
                fflush(stdin);
                gets(nome);

                for(i=0; i<TAM; i++)
                {
                    if(strcmp(nome,c[i].nome)== 0)
                    {
                        pos = i;

                        printf("\n REGISTRO ENCONTRADO");
                        printf("\n Idade:");
                        fflush(stdin);
                        scanf("%d",&c[pos].id);
                        printf("\n Origem:");
                        fflush(stdin);
                        gets(c[pos].ori);
                        printf("\n Destino:");
                        fflush(stdin);
                        gets(c[pos].des);
                        printf("\n -\-\-\-\-\-\-APERTE QUALQUER BOTAO PARA CONTINUAR O PROCEDIMENTO");
                        getch();
                    }
                }
                printf("\n -- FINALIZADO --");
                printf("\n APERTE QUALQUER TECLA");
                getch();
                system("cls");

                break;

            case 3:


                printf("\n --- E NECESSARIO TER CADASTRO PARA IMPRIMIR COMPROVANTE---");
                printf("\n --------------------------------------------------------");
                printf(" \n Digite um nome: ");
                fflush(stdin);
                gets(nome);

                for(i=0; i<TAM; i++)
                {
                    if(strcmp(nome,c[i].nome)== 0)
                    {
                        pos = i;
                        printf("\n REGISTRO ENCONTRADO");
                        printf("\n Nome: %s",c[pos].nome);
                        printf("\n Origem: %s",c[pos].ori);
                        printf("\n Destino: %s",c[pos].des);
                        printf("\n -\-\-\-\-\-\-APERTE QUALQUER BOTAO PARA CONTINUAR O PROCEDIMENTO");
                        getch();
                    }

                }
                printf("\n -- FINALIZADO --");
                printf("\n APERTE QUALQUER TECLA");
                getch();
                system("cls");

                break;

            default:
                break;
            }
        }
    }
    while(opc != 0);
}

int main()
{
    int x;

    menu(x);

    return 0;
}
