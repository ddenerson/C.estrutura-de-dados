#include <stdio.h>
#include <stdlib.h>

struct Tpilha
{
    int item;
    struct Tpilha *ant;
};

struct pilha
{
    struct Tpilha *topo;
};

struct pilha*createpilha(struct pilha*p)
{
    p->topo = NULL;
    return p;
}

struct pilha*empilha(struct pilha*p,int valor)
{
    struct Tpilha*novo;
    novo=(struct Tpilha*)malloc(sizeof(struct Tpilha));
    novo->item = valor;
    novo->ant  = p->topo;
    p->topo = novo;
    return p;
}

void recebe_pilha(struct pilha*p1,struct pilha*p2, int numero)
{
    if(numero % 2 == 0)
    {
       empilha(p1,numero);
    }
    else
    {
      empilha(p2,numero);
    }
}




int pilha_vazia(struct pilha *p)
{
    if(p->topo == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void mostra_pilha(struct pilha *p)
{

    if(pilha_vazia(p)==1)
    {

        printf("PILHA VAZIA");
    }
    else
    {

        struct Tpilha *aux;
        aux =(struct Tpilha*)malloc(sizeof(struct Tpilha));
        aux= p->topo;

        while(aux != NULL)
        {
            printf("\n %d",aux->item);
            aux = aux->ant;
        }

    }

}


void menu()
{
    int opc;
    int valor;

    struct pilha *p1 =(struct pilha*)malloc(sizeof(struct pilha));
    struct pilha *p2 =(struct pilha*)malloc(sizeof(struct pilha));
    createpilha(p1);
    createpilha(p2);


    do
    {
        opc = 0;
        valor = 0;


        system("clear");
        printf("\n PILHAS");
        printf("\n ----------");
        printf("\n PILHA 1 - PAR");
        printf("\n");
        printf("\n");
        mostra_pilha(p1);
        printf("\n");
        printf("\n");
        printf("\n PILHA 2 - IMPAR");
        printf("\n");
        mostra_pilha(p2);
        printf("\n");
        printf("\n");
        printf("\n 1 - EMPILHAR");
        printf("\n 2 - SAIR");
        printf("\n Informe a opcao :");
        fflush(stdin);
        scanf("%d",&opc);

        switch(opc)
        {
        case 1:

            printf("\n -EMPILHAR");
            printf("\n Informe o valor: ");
            fflush(stdin);
            scanf("%d",&valor);
            recebe_pilha(p1,p2,valor);
            break;
        default:
            break;

        }


    }
    while(opc != 2);

}



int main()
{
    menu();

    return 0;
}

