#include <stdio.h>
#include <stdlib.h>


struct pilha
{
    int num;
    struct pilha *prox;
};
typedef struct pilha pilha;
pilha*top;

struct fila
{
    int num;
    struct fila *prox;
};

struct fila *topo = NULL;
struct fila *corpo = NULL;

void iniciar()
{
    top = NULL;
}

void entrada(int valor)
{
    pilha *tmp;
    tmp = malloc(sizeof(pilha));
    tmp -> num = valor;
    tmp -> prox = top;
    top = tmp;
}

int deletar_pilha()
{
    pilha *tmp;
    int n;
    tmp = top;
    n = tmp->num;
    top = top->prox;
    free(tmp);
    return n;
}

void mostrar_pilha(struct pilha*topo)
{
    if(topo == NULL)
    {
        printf("");
    }
    else
    {
        //Chamando recursivamente
        printf("| %d | \n", topo->num);
        mostrar_pilha(topo->prox);
    }
}

// inserir no comeco da fila
void inserir_fila(int dados)
{
    // criando o link
    struct fila *link = (struct fila*) malloc(sizeof(struct fila));

    // apontando para o primeiro valor
    link->num = dados;
    
    link->prox = NULL;

    // coferindo a  nulidade do espaco
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
        printf(" | %d | ",ptr->num);
        ptr = ptr->prox;
    }

}


struct fila*deletar_fila()
{

    // referencia para o primeiro link
    struct fila *link = topo;

    // marcando ao lado do primeiro link como o primeiro
    topo = topo->prox;

    //retornando o numero deletado
    return link;
}


int main()
{
    int opc = 0;
    int v = 0;
    iniciar();
    do
    {
        system("clear");
        printf("\n PILHA ");
        printf("\n ----------");
        printf("\n");
        mostrar_pilha(top);
        printf("\n");
        printf("\n FILA ");
        printf("\n ----------");
        imprimirFila();


        printf("\n");
        printf("\n 1 - Empilhar");
        printf("\n 2 - Desempilhar");
        printf("\n 3 - Enfileirar");
        printf("\n 4 - Desenfileirar");
        printf("\n 5 - Sair");
        printf("\n Escolha um numero :");
        fflush(stdin);
        scanf("%d",&opc);

        switch(opc)
        {
        case 1:
            printf("\n [EMPILHAR]");
            printf("\n VALOR:");
            fflush(stdin);
            scanf("%d",&v);
            entrada(v);
            break;
        case 2:
            printf("\n [DESEMPILHAR]");
            v = deletar_pilha();
            inserir_fila(v);
            break;
        case 3:
            printf("\n [ENFILEIRAR]");
            printf("\n VALOR:");
            fflush(stdin);
            scanf("%d",&v);
            inserir_fila(v);
            break;
        case 4:
            printf("\n [DESENFILEIRAR]");
            deletar_fila();
            break;

        }
    }
    while(opc != 5);




    return 0;
}
