#include <stdio.h>
#include <stdlib.h>


typedef struct no
{
    int valor;
    struct no *esq;
    struct no *dir;
} no;

// Escreva uma função que conta o número de nós de uma árvore binaria de busca
int contar_TdNo(no*raiz)
{
    int n = 1;
    if(raiz->esq != NULL)
    {
        n += contar_TdNo(raiz->esq);
    }
    if(raiz->dir != NULL)
    {
        n += contar_TdNo(raiz->dir);
    }

    return n;
}

// Escreva uma função que conta o número de nós folha de uma árvore binaria de busca
int contar_InNO(no*raiz)
{
    int cont = 0;
    if(raiz->esq != NULL || raiz->dir != NULL)
    {
        cont = 1;
        if(raiz->esq != NULL)
        {
            cont += contar_InNO(raiz->esq);
        }
        if(raiz->dir != NULL)
        {
            cont += contar_InNO(raiz->dir);
        }
    }
    return cont;
}


// Imprimir todos os numeros impares da arvore
void impares(no*raiz)
{
    if(raiz != NULL)
    {
        impares(raiz->esq);
        if(raiz->valor %2 != 0)
            printf("\n [%d]",raiz->valor);

        impares(raiz->dir);
    }
}

void inorder(struct no*raiz)
{
    if(raiz != NULL)
    {
        inorder(raiz->esq);
        printf(" %d ",raiz->valor);
        inorder(raiz->dir);
    }
}

struct no*inserir(no*raiz, int num)
{
    if(raiz == NULL)
    {
        no*novo =(no*)malloc(sizeof(no));
        novo->valor = num;
        novo->esq = NULL;
        novo->dir = NULL;
        raiz = novo;
    }
    else
    {
        if(num == raiz->valor)
        {
            printf("\n O numero ja foi inserido");
        }
        else if(num > raiz->valor) // Inserir o numero a direita da raiz
        {
            raiz->dir = inserir(raiz->dir,num);

        }
        else if(num < raiz->valor) // Inserir o numero a esquerda da raiz
        {
            raiz->esq = inserir(raiz->esq,num);
        }

    }
    return(raiz);
}

int main()
{
    int num;
    int nTodos = 0;
    int nInte  = 0;
    int opc;
    struct no*raiz =(struct no*)malloc(sizeof(struct no));
    raiz = NULL;
    nTodos = contar_TdNo(raiz);
    nInte  = contar_InNO(raiz);
    do
    {
        system("clear");
        printf("\n");
        printf("\n [%d]",n);
        printf("\n ARVORE");
        printf("\n");
        inorder(raiz);
        printf("\n");
        printf("\n ------------------");
        printf("\n IMPARES");
        printf("\n");
        impares(raiz);
        printf("\n");
        printf("\n ------------------");
        printf("\n SOMA DE TODOS OS NO");
        printf("\n");
        printf("\n %d",nTodos);
        printf("\n ------------------");
        printf("\n SOMA DE TODOS OS NO INTERNO");
        printf("\n");
        printf("\n %d",nInte);
        printf("\n ------------------");

        printf("\n 1 - ENTRADA");
        printf("\n 2 - SAIR");
        printf("\n ESCOLHA:");
        fflush(stdin);
        scanf("%d",&opc);
        switch(opc)
        {
        case 1:
            printf("\n Informe o valor:");
            fflush(stdin);
            scanf("%d",&num);
            raiz = inserir(raiz,num);
            break;
        default:
            break;
        }
    }
    while(opc != 2);

    return 0;
}
