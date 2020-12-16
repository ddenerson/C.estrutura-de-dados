#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


typedef struct no
{
    int idade;
    char nome[20];
    char genero[10];
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

void insere(lista *l, int valor,char nome[],char genero[])
{

    no *novo=(no*)malloc(sizeof(no));
    strcpy(novo->nome,nome);
    strcpy(novo->genero,genero);
    novo->idade = valor;
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

void exibir(struct lista*l)
{
    struct no*inicio=l->inicio;

    if(lista_vazia(l))
    {
        printf("\n LISTA VAZIA");
    }

    while( inicio != NULL)
    {
        printf("\n |%s - %s - %d|",inicio->nome,inicio->genero,inicio->idade);
        inicio = inicio->prox;

    }

}

int sexof(struct lista*l)
{
    no*aux=(no*)malloc(sizeof(no));
    aux=l->inicio;
    int result = 0;
    int x=0;
    char feminino[20];
    strcpy(feminino,"feminino");

    while(aux != NULL)
    {
        if(strcmp(feminino,aux->genero)==0)
        {
            x=1;
            result++;
        }
        aux=aux->prox;
    }
    if(x==1)
    {
        return result;
    }
    else
    {
        return 0;
    }
}

void menor_idade(struct lista*l)
{
    struct no*inicio=l->inicio;
    int menor = inicio->idade;

    while( inicio != NULL)
    {

        if(inicio->idade < menor)
            menor = inicio->idade;

        inicio = inicio->prox;
    }
    printf("\n A menor idade e: %d",menor);

}

void mais_velho(struct lista*l)
{
    struct no*inicio=l->inicio;
    int maior = inicio->idade;

    while(inicio != NULL)
    {
        if(inicio->idade > maior)
            printf("\n Noma da pessoa mais velha: %s",inicio->nome);
        inicio = inicio->prox;
    }
}


void menu()
{
    int opc;
    int idade;
    int r;
    int SomarI = 0;
    char nome[20];
    char genero[20];
    lista *l=(lista*)malloc(sizeof(lista));
    create_lista(l);

    do
    {
        system("clear");
        printf("\n 0 - Sair");
        printf("\n 1 - Cadastrar");
        printf("\n 2 - Mostrar");
        printf("\n 3 - Somar as idades");
        printf("\n 4 - Numero de mulheres");
        printf("\n 5 - Retornar a menor idade");
        printf("\n 6 - Retornar o nome do aluno mais velho");
        printf("\n Escolha uma opcao:");
        fflush(stdin);
        scanf("%d",&opc);

        switch(opc)
        {
        case 1:
            printf("\n |CADASTRO|");
            printf("\n ");
            printf("\n NOME:");
            scanf("%d");
            fgets(nome,20,stdin);
            printf("\n IDADE:");
            fflush(stdin);
            scanf("%d",&idade);
            printf("\n GENERO:");
            scanf("%d");
            fgets(genero,20,stdin);
            SomarI += idade;
            insere(l,idade,nome,genero);
            break;
        case 2:
            printf("\n |MOSTRAR|");
            exibir(l);
            getchar();
            getchar();
            break;
        case 3:
            printf("\n |SOMA DE IDADE|");
            printf("\n TOTAL DE IDADES: %d",SomarI);
            getchar();
            getchar();
            break;
        case 4:
            printf("\n |NUMERO DE MULHERES|");
            printf("\n");
            r=sexof(l);
            printf("%d",r);
            getchar();
            getchar();
            break;
        case 5:
            printf("\n |RETORNAR MENOR IDADE|");
            printf("\n");
            menor_idade(l);
            getchar();
            getchar();
            break;
        case 6:
            printf("\n |ALUNO MAIS VELHO|");
            printf("\n");
            mais_velho(l);
            getchar();
            getchar();
            break;
        default:
            break;

        }

    }
    while(opc != 0);
}


int main()
{
    menu();

    return 0;
}
