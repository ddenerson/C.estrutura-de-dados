#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 2


/*
  1 - Desenvolva uma rotina para inverter a posição dos elementos de uma pilha P.

  2 - Desenvolva uma função para testar se uma pilha P1 tem mais elementos que
  uma pilha P2.

  3 - Desenvolva uma função para testar se duas pilhas P1 e P2 são iguais.

  4 - Suponha que um dado problema requer o uso de duas pilhas, onde cada pilha
  suporta no máximo 10 elementos.Implementar a estrutura de dados de empilhar
  e desempilhar para estas duas pilhas.

*/


struct Tpilha
{
    int item;
    struct Tpilha *ant;
};

struct pilha
{
    struct Tpilha *topo;
};

typedef struct
{
    int vet[MAX];
    int topo;
} Pilha_limit;

Pilha_limit*criaPilha()
{
    Pilha_limit *p = (Pilha_limit*)malloc(sizeof(Pilha_limit));
    p->topo=-1;
    return p;
}


struct pilha*createpilha(struct pilha*p)
{
    p->topo = NULL;
    return p;
}

struct pilha*empilha(struct pilha*p,int valor)
{
    struct Tpilha*novo;
    novo=(struct Tpilha*)malloc(sizeof(struct Tpilha));
    novo->item = valor;
    novo->ant  = p->topo;
    p->topo = novo;
    return p;
}

int empilha_limitado(Pilha_limit*p)
{
    int n;

    if( p->topo == MAX-1)
    {
        printf("cheia,impossivel inserir elementos\n");
        getchar();
        getchar();
        return 0;
    }
    else
    {
        printf("\n Informe o valor: ");
        fflush(stdin);
        scanf("%d",&n);
        p->vet[p->topo++]=n;
        printf(" Elemento adicionado com sucesso.\n");
        getchar();
        getchar();
        return p;
    }
}

int desempilha_limitado(Pilha_limit*p)
{
    if(p->topo == -1)
    {
        printf("Impossivel retirar, a pilha esta vazia.\n");
        getchar();
        getchar();
        return 0;
    }
    else
    {
        printf("\n O elemento do topo foi retirado");
        getchar();
        getchar();
        return p->vet[p->topo--];
    }
}


int desempilha(struct pilha *p)
{

    int valor;
    struct Tpilha *aux;
    aux =(struct Tpilha*)malloc(sizeof(struct Tpilha));
    aux = p->topo;

    p->topo = aux->ant;
    valor = aux->item;
    aux->ant = NULL;
    free(aux);
    return valor;
}

void mostra_pilha(struct pilha *p)
{

    if(pilha_vazia(p)==1)
    {

        printf("PILHA VAZIA");
    }
    else
    {

        struct Tpilha *aux;
        aux =(struct Tpilha*)malloc(sizeof(struct Tpilha));
        aux= p->topo;

        while(aux != NULL)
        {
            printf("\n %d",aux->item);
            aux = aux->ant;
        }

    }

}

void comparar_igualdade(struct pilha*p1, struct pilha*p2)
{
    if(pilha_vazia(p1)==1)
    {
        printf("\n PILHA VAZIA");
    }
    else
    {
        // estruturando o struct que tem o valores da Pilha que deve comparada
        struct Tpilha*auxI = (struct Tpilha*)malloc(sizeof(struct Tpilha));
        struct Tpilha*auxII = (struct Tpilha*)malloc(sizeof(struct Tpilha));
        // apontando para o topo que sera utilizando como parametro para iniciar a comparacao
        auxI = p1->topo;
        auxII = p2->topo;

        while(auxI != NULL)
        {
            if(auxI->item == auxII->item)
            {
                printf("\n IGUAIS ");
                break;
            }
            else
                printf("\n DIFERENTES ");
            break;
            auxI  = auxI->ant;
            auxII = auxII->ant;
        }
    }
}

void comparar_tamanho(struct pilha*p1,struct pilha*p2)
{
    int len1 = 0;
    int len2 = 0;
    // conferindo pilha vazia
    if(pilha_vazia(p1) == 1)
    {
        printf("\n PILHA VAZIA");
    }
    else
    {
        // estruturando o struct que tem o valores da Pilha que deve comparada
        struct Tpilha*auxI = (struct Tpilha*)malloc(sizeof(struct Tpilha));
        struct Tpilha*auxII = (struct Tpilha*)malloc(sizeof(struct Tpilha));
        // apontando para o topo que sera utilizando como parametro para iniciar a comparacao
        auxI  = p1->topo;
        auxII = p2->topo;
        // contando a qtd de elementos na primeira Pilha
        while(auxI != NULL)
        {
            auxI = auxI->ant;
            len1++;
        }
        // contando a qtd de elementos na segunda Pilha
        while(auxII != NULL)
        {
            auxII = auxII->ant;
            len2++;
        }
        // comparando o tamanho dos vetores
        if(len1 > len2)
        {
            printf("\n  PILHA[1] E MAIOR");
        }
        else if(len1 == len2)
            printf("\n  PILHA[1] E PILHA[2] SAO DE TAMANHOS IGUAIS");
        else
            printf("\n PILHA[2] E MAIOR");
    }
}



int pilha_vazia(struct pilha *p)
{
    if(p->topo == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



void menu()
{
    int opc;
    int valor;
    int x;
    int i = 0;
    int cho  = 0;
    struct pilha *p =(struct pilha*)malloc(sizeof(struct pilha));
    struct pilha *p2 =(struct pilha*)malloc(sizeof(struct pilha));
    Pilha_limit*P = criaPilha();
    Pilha_limit*P2 = criaPilha();
    createpilha(p);
    createpilha(p2);

    do
    {
        system("clear");
        printf("\n PILHA");
        printf("\n\n");
        printf("\n 1 - EMPILHAR");
        printf("\n 2 - EMPILHAR SEGUNDA PILHA");
        printf("\n 3 - DESEMPILHA");
        printf("\n 4 - MOSTRAR");
        printf("\n 5 - COMPARAR PILHAS");
        printf("\n 6 - COMPARAR TAMANHO DE PILHAS ");
        printf("\n 7 - INVERTER ELEMENTOS DA PILHA ");
        printf("\n 8 - EMPILHAR LIMITADO");
        printf("\n 9 - DESEMPILHAR PILHA LIMITADA");

        printf("\n Informe a opcao :");
        fflush(stdin);
        scanf("%d",&opc);

        switch(opc)
        {
        case 1:
            printf("\n -EMPILHAR");
            printf("\n Informe o valor: ");
            fflush(stdin);
            scanf("%d",&valor);
            p = empilha(p,valor);
            printf("\n PRESIONE QUALQUER TECLA PARA SAIR");
            getchar();
            getchar();
            break;
        case 2:
            printf("\n -EMPILHAR SEGUNDA PILHA");
            printf("\n Informe o valor: ");
            fflush(stdin);
            scanf("%d",&valor);
            p2 = empilha(p2,valor);
            break;
        case 3:
            printf("\n -DESEMPILHA");
            x = desempilha(p);
            printf("\n O valor foi retirado");
            printf("\n PRESIONE QUALQUER TECLA PARA SAIR");
            getchar();
            getchar();
            break;
        case 4:
            printf("\n - MOSTRAR");
            printf("\n - PILHA [1]:");
            mostra_pilha(p);
            printf("\n ----------------------");
            printf("\n  - PILHA [2]:");
            mostra_pilha(p2);
            getchar();
            getchar();
            break;
        case 5:
            printf("\n - COMPARAR PILHAS");
            comparar_igualdade(p,p2);
            getchar();
            getchar();
            break;
        case 6:
            printf("\n - COMPARAR TAMANHO DE PILHAS");
            comparar_tamanho(p,p2);
            getchar();
            getchar();
            break;
        case 7:
            printf("\n  - INVERTER ELEMENTOS DA PILHA ");

            while(pilha_vazia(p) == 0)
            {
                x = desempilha(p);
                empilha(p,valor);
            }
            break;
        case 8:
            printf("\n - EMPILHAR LIMITADO");
            printf("\n ESCOLHA DA PILHA : 1- PILHA[1] 2- PILHA[2]:");
            fflush(stdin);
            scanf("%d",&cho);
            if(cho == 1)
            {
                printf("\n PILHA[1] ");
                empilha_limitado(P);
            }
            else
            {
                printf("\n PILHA[2] ");
                empilha_limitado(P2);
            }
            break;
        case 9:
            printf("\n - DESEMPILHA ");
            printf("\n ESCOLHA DA PILHA : 1- PILHA[1] 2- PILHA[2]:");
            fflush(stdin);
            scanf("%d",&cho);
            if(cho == 1)
            {
                desempilha_limitado(P);
            }
            else
            {
                desempilha_limitado(P2);
            }
            break;
        default:
            break;
        }
    }
    while(opc != 6);
}

int main()
{
    menu();


    return 0;
}

