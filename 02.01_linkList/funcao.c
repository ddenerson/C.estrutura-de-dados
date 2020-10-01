#include "header.h"
#include <stdio.h>
#include <stdlib.h>



// Criando função para entrada
struct cadastro*inserirFim(struct cadastro bloco, struct cadastro*inicio)
{
    struct cadastro*novo;
    // Alocando memoria do tamanho do struct
    novo =(struct cadastro*) malloc(sizeof(struct cadastro));
    (*novo).num  = bloco.num;
    (*novo).prox = NULL;

    if(inicio == NULL)
    {
        inicio=novo;
    }
    else
    {
        // Criando um ponteiro auxiliar para reserva o endereco de memoria inicio
        struct cadastro*aux;

        aux=inicio;

        // Enquanto for diferente de nulo continua não linkando o endereco de memoria no
        // outro bloco ou seja não nova entrada
        while(aux->prox != NULL)

            aux=aux->prox;
        aux->prox=novo;
    }

    return inicio;

}

// Criando funcao inserido no comeco
struct cadastro*inserirIni(struct cadastro *bloco,struct cadastro prim)
{
    struct cadastro*novo;
    novo=(struct cadastro*)malloc(sizeof(struct cadastro));
    (*novo).num=prim.num;
    (*novo).prox = NULL;

    // Verificando se o bloco esta vazio, se sim o primeiro valor sera o digitado com a
    // chamada dessa função
    if(bloco == NULL)
    {
        bloco=novo;
    }
    // A função ja esta preenchida,logo vamos apontar para o primeiro valor e empuralo
    // para proxima posição,preenchendo a primeira posição com valor dessa função
    else
    {
        novo->prox=bloco;
        bloco=novo;
    }

    return bloco;
}


void maior(struct cadastro *inicio)
{
    struct cadastro *bloco;
    struct cadastro maiorV;
    bloco= inicio;
    maiorV.num=0;

    while(bloco != NULL)
    {
        if(bloco->num >= maiorV.num)
        {
            maiorV.num=bloco->num;
            bloco=bloco->prox;
        }
        else
        {
            bloco=bloco->prox;
        }
    }

    printf("\n O MAIOR VALOR DE ENTRADA E : [%d]",maiorV.num);

}

void menor(struct cadastro *inicio)
{
    struct cadastro *bloco;
    struct cadastro menorV;
    bloco=inicio;
    menorV.num=0;

    while(bloco != NULL)
    {
        if(bloco->num <= menorV.num)
        {
            menorV.num = bloco->num;
            bloco=bloco->prox;
        }
        else
        {
            bloco=bloco->prox;
        }
    }

    printf("\n O MENOR VALOR DE ENTRADA E : [%d]",menorV.num);
}



void imprimir(struct cadastro *inicio)
{
    struct cadastro *bloco;
    bloco=inicio;


    while(bloco != NULL)
    {
        printf("\n [%d]",bloco->num);
        bloco=bloco->prox;
    }
}



