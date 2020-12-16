#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct no
{
    int num;
    struct no *prox;
} no;

typedef struct lista
{
    no *inicio;
    no *fim;
} lista;

void create_lista(lista *l)
{
    l->inicio = NULL;
    l->fim =NULL;
}

int lista_vazia(lista *l)
{
    if(l->inicio ==NULL)
    {
        return 1; //lista está vazia
    }
    else
    {
        return 0; //lista não está vazia
    }
}

void insere_inicio(lista *l,int num)
{

    no *novo=(no*)malloc(sizeof(no));
    novo->num = num;
    novo->prox = NULL;

    if(lista_vazia(l)==1) //primeira vez que o no é inserido na lista
    {
        l->fim = novo;
        l->inicio=novo;
    }
    else
    {
        novo->prox =l->inicio;
        l->inicio  =novo;
    }
}

void insere_fim(lista *l, int num)
{

    no *novo=(no*)malloc(sizeof(no));
    novo->num = num;
    novo->prox = NULL;

    if(lista_vazia(l)==1)
    {
        l->fim = novo;
        l->inicio=novo;
    }
    else
    {

        l->fim->prox = novo;
        l->fim       = novo;
    }
}

void exibir(struct lista*l)
{
    struct no*inicio=l->inicio;

    if(lista_vazia(l))
    {
        printf("\n LISTA VAZIA");
    }

    while( inicio != NULL)
    {
        printf("\n|%d|",inicio->num);
        inicio = inicio->prox; //incrementando o ponteiro

    }
}

void maior(struct lista*l)
{
    struct no*inicio=l->inicio;
    int maior = inicio->num;

    while(inicio != NULL)
    {
        if(inicio->num > maior)
            maior = inicio->num;
        inicio = inicio->prox;
    }
    printf("\n O maior numero e: %d",maior);
}

void menor(struct lista*l)
{
    struct no*inicio=l->inicio;
    int menor = inicio->num;

    while( inicio != NULL)
    {

        if(inicio->num < menor)
            menor = inicio->num;

        inicio = inicio->prox;
    }
    printf("\n A menor numero e: %d",menor);

}

void menu()
{

    lista *l=(lista*)malloc(sizeof(lista));
    create_lista(l);
    int num;
    int opcao;

    do
    {
        system("cls");
        printf("0.Sair");
        printf("\n1.Cadastrar elementos (inserir no final)");
        printf("\n2.Listar os elementos cadastrados");
        printf("\n3.Cadastrar elementos (inserir no inicio)");
        printf("\n4.Mostrar o menor elemento");
        printf("\n5.Mostrar o maior elemento");
        printf("\n\nEscolha uma opcao: ");
        scanf("%d",&opcao);
        switch(opcao)
        {
        case 0:
            printf("Encerrando...");
            break;
        case 1:
            printf("\n CADASTRAR |INSERIR NO FIM|");
            printf("\n Numero: ");
            scanf("%d",&num);
            insere_fim(l,num);
            break;
        case 2:
            exibir(l);
            break;
        case 3:
            printf("\n CADASTRAR |INSERIR NO INICIO|");
            printf("\n Numero: ");
            scanf("%d",&num);
            insere_inicio(l,num);
            break;
        case 4:
            printf("\n |MENOR NUMERO|");
            printf("\n");
            menor(l);
            getchar();
            getchar();
            break;
        case 5:
            printf("\n |MAIOR NUMERO|");
            printf("\n");
            maior(l);
            getchar();
            getchar();
            break;
        default:
            printf("Opcao invalida");
        }
        getch();
    }
    while(opcao!=0);

}





int main()
{
    menu();
    return 0;
}
