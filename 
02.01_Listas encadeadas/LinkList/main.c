#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Implemente uma lista ligada para armazenar números inteiros.
Seu programa deve ter o seguinte MENU de opções:

1 - Cadastrar elementos (inserir no final)

2 - Listar os elementos cadastrados

3 - Cadastrar elementos (inserir no início)

4 - Mostrar o menor elemento

5 - Mostrar o maior elemento

0 - Sair
*/

int main()
{
    struct cadastro *entrada;
    struct cadastro bloco;
    int opc = 0;
    do
    {
        system("clear");
        printf("\n  0 - Sair");
        printf("\n  1 - Cadastrar elementos[INSERIR NO FINAL]");
        printf("\n  2 - Listar os elementso cadastros");
        printf("\n  3 - Cadastrar elementos[INSERIR NO INICIO]");
        printf("\n  4 - Monstrar o menor elemento");
        printf("\n  5 - Mostrar o maior elemento");
        printf("\n  Escolha uma das opções:");
        fflush(stdin);
        scanf("%d",&opc);

        switch(opc)
        {
        case 1:
            printf("\n [INSERIR NO FINAL]");
            printf("\n Insira o numero:");
            fflush(stdin);
            scanf("%d",&bloco.num);
            entrada=inserirFim(bloco,entrada);
            printf("\n PRESIONE QUALQUER TECLA PARA SAIR");
            getchar();
            getchar();
            break;
        case 2:
            printf("\n [CADASTRO]");
            imprimir(entrada);
            printf("\n PRESIONE QUALQUER TECLA PARA SAIR");
            getchar();
            getchar();
            break;
        case 3:
            printf("\n [INSERIR NO INICIO]");
            printf("\n Insira o numero:");
            fflush(stdin);
            scanf("%d",&bloco.num);
            entrada=inserirIni(entrada,bloco);
            printf("\n PRESIONE QUALQUER TECLA PARA SAIR");
            getchar();
            getchar();
            break;
        case 4:
            menor(entrada);
            printf("\n PRESIONE QUALQUER TECLA PARA SAIR");
            getchar();
            getchar();
            break;
        case 5:
            maior(entrada);
            printf("\n PRESIONE QUALQUER TECLA PARA SAIR");
            getchar();
            getchar();
            break;
        default:
            break;
        }
    }
    while(opc != 0 );

    return 0;
}
