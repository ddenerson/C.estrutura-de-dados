#include "funcao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
/*
Alocação dinâmica
Use-o e faça com que o MENU tenha as seguintes opções:
----------------------------------
0 - Sair
1 - Cadastrar
2 - Mostrar
3 - Retornar os dados do registro do aluno que possui a maior idade
4 - Retornar a quantidade de alunos do sexo F
-------------------------------------
*/



int main()
{
    struct info*inicio;
    struct info bloco;
    int opc,cont=0;
    inicio=NULL;

    do
    {
        system("clear");
        printf("\n 0 - Sair ");
        printf("\n 1 - Cadastrar ");
        printf("\n 2 - Mostrar ");
        printf("\n 3 - Aluno com maior idade");
        printf("\n 4 - Qtd alunas");
        printf("\n Escolha a opcao :");
        fflush(stdin);
        scanf("%d",&opc);
        switch(opc)
        {
        case 1:
            printf("\n ---- CADASTRO ----");
            printf("\n");
            printf("\n Nome :");
            scanf("%d");
            fgets(bloco.nome,40,stdin);
            printf("\n Genero : ");
            fflush(stdin);
            scanf("%c",&bloco.sexo);
            printf("\n Idade :");
            fflush(stdin);
            scanf("%d",&bloco.idade);
            inicio=cadastrar(bloco,inicio);
            printf("---------------------------");
            if(bloco.sexo == 'f' || bloco.sexo == 'F')
            {
                cont++;
            }
            break;
        case 2:
            printf("\n ---- LISTA DE CADASTRO ----");
            printf("\n ");
            mostrar(inicio);
            printf("\n ----------------------------");
            printf("\n APARTE QUALQUER TECLA PARA SAIR");
            getchar();
            getchar();
            break;
        case 3:
            printf("\n ----MAIOR IDADE----");
            printf("\n ");
            maior_idade(inicio);
            printf("\n ------------------------");
            printf("\n APARTE QUALQUER TECLA PARA SAIR");
            getchar();
            getchar();
            break;
        case 4:
            printf("\n ----QTD DE ALUNAS----");
            printf("\n %d - ALUNO[S]",cont);
            printf("\n ------------------------");
            printf("\n APARTE QUALQUER TECLA PARA SAIR");
            getchar();
            getchar();
            break;
        }
    }
    while(opc != 0);




    return 0;
}
