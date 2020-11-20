#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tam 20

struct fila
{
    int num;
    int numP;
    char nomeLan[20];
    int valorLan;
    struct fila *prox;
};

struct fila *topo = NULL;
struct fila *corpo = NULL;


void inserir_fila(int numCarro,int numPedid,int valorLan,char nomeLan[])
{

    struct fila *link = (struct fila*) malloc(sizeof(struct fila));


    strcpy(link->nomeLan,nomeLan);
    link->num  = numCarro;
    link->numP = numPedid;
    link->valorLan = valorLan;

    link->prox = NULL;


    if(corpo == NULL)
    {
        topo = link;
        corpo = link;
    }
    else
    {
        corpo->prox = link;
        corpo = corpo->prox;

    }
}

void imprimirFila()
{
    struct fila *ptr = topo;
    printf("\n");

    // imprimindo a fila desde o começo
    while(ptr != NULL)
    {
        printf("\n|Carro %d-Pedido %d -%s -R$ %d |",ptr->num,ptr->numP,ptr->nomeLan,ptr->valorLan);
        ptr = ptr->prox;
    }

}



int main()
{
    int opc;
    int numCarro;
    int numPedid;
    int valorLan;
    char nomeLan[20];
    int contC = 0;
    int totFat = 0;

    do
    {
        opc = 0;
        numCarro = 0;
        numPedid = 0;
        valorLan = 0;

        system("clear");
        printf("\n");
        printf("\n");
        printf("\n 1 - PEDIDO");
        printf("\n 2 - RELATORIO");
        printf("\n 3 - SAIR");
        printf("\n Escolha um numero :");
        fflush(stdin);
        scanf("%d",&opc);

        switch(opc)
        {
        case 1:
            printf("\n [PEDIDO]");
            printf("\n");
            printf("\n Numero do carro:");
            fflush(stdin);
            scanf("%d",&numCarro);
            printf("\n Numero do pedido:");
            fflush(stdin);
            scanf("%d",&numPedid);
            printf("\n Nome do lanche:");
            scanf("%d");
            fgets(nomeLan,20,stdin);
            printf("\n Valor:");
            fflush(stdin);
            scanf("%d",&valorLan);
            inserir_fila(numCarro,numPedid,valorLan,nomeLan);
            contC++;
            totFat += valorLan;
            break;
        case 2:
            printf("\n [RELATORIO]");
            printf("\n");
            imprimirFila();
            printf("\n");
            printf("__________________");
            printf("\n Valor total das vendas: R$ %d reais",totFat);
            printf("\n Total de carros: %d ",contC);
            getchar();
            getchar();
            break;
        default:
            break;
        }


    }
    while(opc != 3);



    return 0;
}
