#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*
a) crie uma função que insira um número no final da lista circular duplamente
encadeada. Não pode haver elementos repetidos na lista, assim antes de inserir, é
necessário verificar se o elemento já está na lista (5 pontos).
b)Crie uma função que insira um número no início da lista circular duplamente
encadeada, não pode haver elementos repetidos na lista, assim antes de inserir, é
necessário verificar se o elemento já está na lista(5 pontos).
*/

typedef struct noc
{
    int valor;
    struct no *ant;
    struct no *prox;
} noc;

typedef struct listac
{
    no *inicio;
    no *fim;
} listac;

void inicializa_lista(listac *l)
{
    l->inicio=NULL;
    l->fim=NULL;
}

int lista_vaziaC(listac *l)
{

    if(l->inicio==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
// Que insira um número no final da lista circular duplamente encadeada.
void inserir_fimC(listac*lc, int vc)
{
    noc *novo=(no*)malloc(sizeof(noc));
    noc *aux=(no*)malloc(sizeof(noc));

    novo->valor = vc;
    novo->prox = NULL;
    novo->ant = NULL;

    if(lista_vaziaC(lc) == 1)
    {
        lc->inicio = novo;
        lc->fim = novo;
        novo->prox = lc->inicio;
    }
    else
    {

        if(lc->inicio->valor == vc || lc->fim == vc)
            printf("\ VALOR DUPLICADO");
        else
        {

            lc->fim->prox = novo;
            lc->fim = novo;
            lc->fim->prox = lc->inicio;
        }

    }
}
// Que insira um número no início da lista circular duplamente encadeada.
void inserir_inicioC(listac*lc, int vc)
{
    noc *novo=(no*)malloc(sizeof(noc));
    noc *aux=(no*)malloc(sizeof(noc));

    novo->valor = vc;
    novo->prox = NULL;
    novo->ant = NULL;

    if(lista_vaziaC(lc) == 1)
    {
        lc->inicio = novo;
        lc->fim = novo;
        novo->prox = lc->inicio;
    }
    else
    {

        if(lc->inicio->valor == vc || lc->fim == vc)
            printf("\ VALOR DUPLICADO");
        else
        {

            lc->inicio->prox = novo;
            lc->inicio = novo;
            lc->inicio->prox = lc->fim;
        }
    }

}

void mostrar_listac(listac *lc)
{

    if(lista_vaziaC(lc))
    {
        printf("\n Lista esta vazia");
    }
    else
    {

        noc*aux =(noc*)malloc(sizeof(noc));
        aux = lc->inicio;

        while(aux != NULL)
        {
            printf("\n %d|",aux->valor);
            aux=aux->prox;
        }
    }
}

void menu()
{

    listac *l=(listac*)malloc(sizeof(listac));
    inicializa_lista(l);
    int opc;
    int valor;

    do
    {
        system("clear");
        printf("\n 1 - ENTRADA NO FIM");
        printf("\n 2 - MOSTRAR");
        printf("\n 3 - SAIR");
        printf("\n Escolha:");
        fflush(stdin);
        scanf("%d",&opc);

        switch(opc)
        {
        case 1:
            printf("\n Informe o valor: ");
            fflush(stdin);
            scanf("%d",&valor);
            inserir_fimC(l,valor);
            inserir_inicioC(l,valor);
            break;
        case 2:
            mostrar_listac(l);
            break;
        default:
            break;

        }
    }
    while(opc != 3);

}

int main()
{
 
    menu();

    return 0;
}

