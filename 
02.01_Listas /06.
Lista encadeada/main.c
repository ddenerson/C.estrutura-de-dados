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
        return 1;
    }
    else
    {
        return 0;
    }
}

void insere(lista *l,char nome[],int idade,char genero[])
{

    no *novo=(no*)malloc(sizeof(no));
    strcpy(novo->nome,nome);
    novo->idade = idade;
    strcpy(novo->genero,genero);

    novo->prox = NULL;

    if(lista_vazia(l)==1)
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
        printf("\n|%s - %s - %d|",inicio->nome,inicio->genero,inicio->idade);
        inicio = inicio->prox;

    }

}

void mais_velho(struct lista*l)
{
    struct no*inicio=l->inicio;
    int maior = inicio->idade;

    while(inicio != NULL)
    {
        if(inicio->idade > maior)
            printf("\n Noma do aluno mais velha: %s",inicio->nome);
        inicio = inicio->prox;
    }
}



void menu()
{

    lista *l=(lista*)malloc(sizeof(lista));
    create_lista(l);
    char nome[20];
    char genero[10];
    int idade;
    int opcao;
    int cont;


    do
    {
        system("cls");
        printf("0.Sair");
        printf("\n1.Cadastrar");
        printf("\n2.Mostrar");
        printf("\n3.Aluno que possui a maior idade");
        printf("\n4.Quantidade de alunos do sexo F");
        printf("\n\nEscolha uma opcao: ");
        scanf("%d",&opcao);
        switch(opcao)
        {
        case 0:
            printf("Encerrando...");
            break;
        case 1:
            printf("Nome: ");
            scanf("%d");
            fgets(nome,40,stdin);
            printf("Idade: ");
            scanf("%d",&idade);
            printf("Sexo: ");
            scanf("%d");
            fgets(genero,20,stdin);
            insere(l,nome,idade,genero);
            if(genero == 'feminino' || genero == 'FEMININO')
            {
                cont++;
            }
            break;
        case 2:
            exibir(l);
            break;
        case 3:
            printf("\n |ALUNO MAIS VELHO|");
            printf("\n");
            mais_velho(l);
            getchar();
            getchar();
            break;
        case 4:
            printf("\n |QTD DE ALUNAS|");
            printf("\n ALUNO[S]: %d ",cont);
            printf("\n ------------------------");
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
