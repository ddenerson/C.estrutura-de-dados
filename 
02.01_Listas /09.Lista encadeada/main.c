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

// 2 - Crie uma função que imprime recursivamente uma lista de inteiros
void exibir(struct no*cab)
{

    printf("\n %d",cab->num);
    if(cab->prox == NULL)
    {
        return;
    }
    exibir(cab->prox);
}

//3-Implemente uma função que tenha como retorno o número de nós de uma lista simplesmente ou duplamente) encadeada
int contar(struct lista*l)
{
    struct no*inicio=l->inicio;
    int cont = 0;

    if(lista_vazia(l))
    {
        return NULL;
    }
    else
    {
        while( inicio != NULL)
        {
            inicio = inicio->prox;
            cont++;
        }
        return cont;
    }
}

// 4) Implemente uma função em uma lista simplesmente encadeada de valores
// inteiros para retornar o número de nós da lista que possuem o campo (info ou
// dado) com valores maiores que n.
int maiores_num(struct lista*l,int num)
{

    struct no*inicio=l->inicio;
    int cont = 0;

    if(lista_vazia(l))
    {
        return NULL;
    }
    else
    {
        while(inicio != NULL)
        {
            if(inicio->num > num)
            {
                printf("\n %d",cont);
                inicio = inicio->prox;
                cont++;
            }
            else
            {
                return 0;
                break;
            }
        }
        return cont;
    }
}

void menu()
{

    lista *l=(lista*)malloc(sizeof(lista));
    create_lista(l);
    int num;
    int x;
    int opcao;

    do
    {
        system("clear");
        printf("\n 0.Sair");
        printf("\n 1. Cadastrar elementos (inserir no inicio)");
        printf("\n 2. Listar os elementos cadastrados");
        printf("\n 3. Numero de Nós");
        printf("\n 4. Comparacao <<numero>> na lista");
        printf("\n\n Escolha uma opcao: ");
        fflush(stdin);
        scanf("%d",&opcao);
        switch(opcao)
        {
        case 0:
            printf("\n Encerrando");
            break;
        case 1:
            printf("\n CADASTRAR |INSERIR NO INICIO|");
            printf("\n Numero: ");
            scanf("%d",&num);
            insere_inicio(l,num);
            break;
        case 2:
            exibir(l);
            break;
        case 3:
            num = contar(l);
            printf("\n NUMERO DE NÓS: [%d]",num);
            break;
        case 4:
            printf("\n COMPARACAO MAIOR NUMEROS");
            printf("\n Insira o numero p/ comparacao: ");
            scanf("%d",&num);
            l,num = maiores_num(l,num);
            break;
        default:
            printf("Opcao invalida");

        }
        getchar();
    }
    while(opcao!=0);
}

int main()
{
 
    menu();

    return 0;
}

