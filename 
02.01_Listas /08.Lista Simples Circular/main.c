#include <stdio.h>
#include <stdlib.h>


typedef struct no
{
    int dado;
    struct no *prox;
} no;

typedef struct lista
{
    no *inicio;
    no *fim;
} lista;

void inicializa_lista(lista *l)
{
    l->inicio=NULL;
    l->fim=NULL;
}


int lista_vazia(lista *l)
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


void inserir(lista *l, int valor)
{

    no *novo=(no*)malloc(sizeof(no));
    novo->dado = valor;
    novo->prox = NULL;


    if(lista_vazia(l)== 1)
    {
        l->inicio=novo;
        l->fim = novo;
        novo->prox = l->inicio;

    }
    else
    {
        l->fim->prox = novo;
        l->fim = novo;
        l->fim->prox = l->inicio;
    }

}

void removerP(struct no** cabeca)
{
    struct no *anterior = *cabeca,*primNo = *cabeca;


    // checar se a lista não tem nenhum no
    if (*cabeca == NULL)
    {
        printf("\n LISTA VAZIA");

    }
    // checar se a lista tem algum no
    // Se sim então delete
    if (anterior->prox == anterior)
    {
        *cabeca = NULL;

    }
    // alterar o segundo no com primeiro
    while (anterior->prox != *cabeca)
    {

        anterior = anterior->prox;
    }

    anterior->prox = primNo->prox;

    *cabeca = anterior->prox;
    free(primNo);


}

void removeU(struct no**cabeca)
{
    struct no *atual = *cabeca, *temp  = *cabeca, *anterior;


    if (*cabeca == NULL)
    {
        printf("\n LISTA VAZIA");
    }


    if (atual->prox == atual)
    {
        *cabeca = NULL;
    }


    while (atual->prox != *cabeca)
    {
        anterior = atual;
        atual = atual->prox;
    }

    anterior->prox = atual->prox;
    *cabeca = anterior->prox;
    free(atual);
}



void mostra_lista(lista *l)
{

    if(lista_vazia(l)==1)
    {
        printf("Lista Vazia !!!!");
    }
    else
    {
        no *aux = (no*)malloc(sizeof(no));
        aux=l->inicio;

        while(aux!=NULL)
        {
            printf("| %d ",aux->dado);
            aux=aux->prox;
        }
    }
}



void menu()
{

    lista *l=(lista*)malloc(sizeof(lista));
    inicializa_lista(l);
    int opc;
    int valor;

    do
    {
        system("clear");
        printf("\n 1 - ENTRADA");
        printf("\n 2 - MOSTRAR");
        printf("\n 3 - DELETAR PRIMEIRO");
        printf("\n 4 - DELETAR ULTIMO");
        printf("\n 5 - SAIR");
        printf("\n Escolha:");
        fflush(stdin);
        scanf("%d",&opc);


        switch(opc)
        {
        case 1:
            printf("\n Informe o valor: ");
            fflush(stdin);
            scanf("%d",&valor);
            inserir(l,valor);
            break;
        case 2:
            printf("\n MOSTRAR");
            printf("\n");
            mostra_lista(l);
            break;
        case 3:
            printf("\n DELETAR PRIMEIRO");
            printf("\n");
            removerP(l);
            break;
        case 4:
            printf("\n DELETAR ULTIMO");
            printf("\n");
            removeU(l);
            break;
        default:
            break;
        }

    }
    while(opc != 5);

}
int main()
{

    menu();

    return 0;
}
