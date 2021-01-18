#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *ant;
    struct no *prox;
} no;

no *cabeca;

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


void inserir(lista *l,int valor)
{

    no *novo=(no*)malloc(sizeof(no));
    no *aux=(no*)malloc(sizeof(no));

    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if (l->inicio==NULL)
    {
        l->fim=novo;
        l->inicio=novo;
    }
    else
    {


        if(l->inicio->valor == valor || l->fim->valor == valor)
            printf("\ VALOR DUPLICADO");
        else
        {
            novo->ant = l->fim;
            l->fim->prox = novo;
            l->fim = novo;

        }
    }
}

void contar(lista*ptr)
{
    no *aux=(no*)malloc(sizeof(no));
    aux=ptr->inicio;
    int tam = 0;
    while(aux != NULL)
    {
        tam++;
        aux=aux->prox;
    }

    printf("\n Total numero de elementos %d",tam);
}

void maior(struct lista*ptr)
{
    struct no*maior,*temp;

    temp = maior = ptr;

    while(temp != NULL)
    {
        if(temp->valor > maior->valor)
            maior = temp;
        temp = temp->prox;
    }
    int max = maior->valor;
    printf("\n Maior numero [%d]",max);
    printf("\n Endereco memoria menor [%d]",maior);

}

void menor(struct lista*ptr)
{
    struct no*menor,*temp;

    temp = menor = ptr;

    while(temp != NULL)
    {
        if(temp->valor > menor->valor)
            menor = temp;
        temp = temp->prox;
    }
    int min = menor->valor;
    printf("\n Maior numero [%d]",min);
    printf("\n Endereco memoria maior [%d]",menor);

}


void mostrar_lista(lista *l)
{

    if(lista_vazia(l))
    {

        printf("\n Lista esta vazia");
    }
    else
    {

        no *aux=(no*)malloc(sizeof(no));
        aux=l->inicio;

        while(aux !=NULL)
        {
            printf(" | %d ",aux->valor);
            aux=aux->prox;
        }

    }
}




void menu()
{
    lista *l=(lista*)malloc(sizeof(lista));
    inicializa_lista(l);
    int op;

    do
    {
        system("clear");
        printf("\n LISTA: ");
        printf("\n");
        mostrar_lista(l);
        contar(l);
        maior(l);
        menor(l);
        printf("\n\n");
        printf("1 - Inserir \n");
        printf("2 - Sair \n");

        printf("\n\n Informe a opcao :>_");
        scanf("%d",&op);

        switch(op)
        {
        case 1:
        {
            int x;
            printf("Informe o valor: ");
            scanf("%d",&x);
            inserir(l,x);
            break;
        }
        case 2:
            op=2;
        }

    }
    while(op != 2);
}


int main()
{

    menu();
    printf("\n\n");
    return 0;
}
