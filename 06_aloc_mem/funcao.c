#include "funcao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


struct info*cadastrar(struct info bloco,struct info*inicio)
{
    struct info*novo;
    novo =(struct info*)malloc(sizeof(struct info));
    strcpy(novo->nome,bloco.nome);
    (*novo).idade = bloco.idade;
    (*novo).sexo  = bloco.sexo;
    (*novo).prox  = NULL;

    if(inicio == NULL)
    {
        inicio=novo;
    }
    else
    {
        struct info*aux;
        aux = inicio;

        while(aux->prox != NULL)
            aux=aux->prox;
        aux->prox=novo;
    }
    return inicio;

}

void mostrar(struct info*inicio)
{
    struct info*bloco;

    bloco= inicio;


    while(bloco != NULL)
    {
        printf("\n NOME  : %s",bloco->nome);
        printf("\n SEXO  : %c",bloco->sexo);
        printf("\n IDADE : %d",bloco->idade);
        bloco=bloco->prox;
    }
}

void maior_idade(struct info*inicio)
{
    struct info infos;
    struct info*bloco;
    bloco= inicio;
    infos.idade=0;

    while(bloco != NULL)
    {
        if(bloco->idade >= infos.idade)
        {
            infos.idade = bloco->idade;
            strcpy(infos.nome,bloco->nome);
            infos.sexo = bloco->sexo;
            bloco=bloco->prox;
        }
        else
        {
            bloco=bloco->prox;
        }
    }

    printf("\n NOME  : %s",infos.nome);
    printf("\n SEXO  : %c",infos.sexo);
    printf("\n  IDADE : %d",infos.idade);

}

