#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Suponha que criamos uma estrutura para armazenar cadastros de alunos de
um curso.Implemente uma para inserir e mostrar os vetores
criados dinamicamente.

Implemente duas funções, uma para inserir e uma para mostrar os vetores
criados dinamicamente.

*/



struct Cadastro
{
    char nome[40];
    int idade;
    char sexo;
};

typedef struct Cadastro cadastro;

void entrada(cadastro *c)
{
    int n = 0;

    printf("Quantidade para o cadastro:");
    fflush(stdin);
    scanf("%d",&n);

    c =(cadastro*)malloc(n * sizeof(cadastro));

    for(int i = 0; i < n ; i++)
    {
        system("clear");
        printf("\n [%d]° Nome: ",(i+1));
        scanf("%d");
        fgets(c[i].nome,40,stdin);
        printf("\n [%d]° Idade:",(i+1));
        fflush(stdin);
        scanf("%d",&c[i].idade);
        printf("\n [%d]° Genero:",(i+1));
        fflush(stdin);
        scanf("%s",&c[i].sexo);
    }

    free(c);
}

void imprimir()
{
    cadastro *p;
    int q = 0;

    printf("\n Quantidade para o cadastro:");
    fflush(stdin);
    scanf("%d",&q);

    p =(cadastro*) malloc(q * sizeof(cadastro));


    for(int i = 0; i < q; i++)
    {
       printf("\n [%d]° Nome:   %s",(i+1), p[i].nome);
       printf("\n [%d]° Idade:  %d ",(i+1),p[i].idade);
       printf("\n [%d]° Genero: %c",(i+1),p[i].sexo);
       printf("\n ---------------------------------");

    }

    free(p);
}



int main()
{
    cadastro *c;

    entrada(c);
    imprimir();

    return 0;
}
