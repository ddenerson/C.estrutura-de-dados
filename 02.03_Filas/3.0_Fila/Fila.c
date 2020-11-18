#include <stdio.h>
#include <stdlib.h>

/*
3.Implemente um método que receba duas pilhas,
remova os elementos destas duas pilhas em ordem crescente em uma fila;
*/

struct pilha
{
    int num;
    struct pilha *prox;
};
typedef struct pilha pilha;
pilha*top;
pilha*top2;

void iniciar()
{
    top  = NULL;
    top2 = NULL;
}

struct fila
{
    int num;
    struct fila *prox;
};

struct fila *topo = NULL;
struct fila *corpo = NULL;

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

void entrada(int valor, int esc)
{
    if(esc == 1)
    {
        pilha *tmp;
        tmp = malloc(sizeof(pilha));
        tmp -> num = valor;
        tmp -> prox = top;
        top = tmp;
    }
    else
    {
        pilha *tmp;
        tmp = malloc(sizeof(pilha));
        tmp -> num = valor;
        tmp -> prox = top2;
        top2 = tmp;
    }
}

int deletar_pilha(int esc)
{
    if(esc == 1)
    {
        pilha *tmp;
        int n;
        tmp = top;
        n = tmp->num;
        top = top->prox;
        free(tmp);
        return n;
    }
    else
    {
        pilha *tmp;
        int n;
        tmp = top2;
        n = tmp->num;
        top2 = top2->prox;
        free(tmp);
        return n;
    }
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

void ordenar(struct fila *comeco)
{
    int mudanca;
    struct fila *ptr1;
    struct fila *lptr1 = NULL;

    // conferindo fila vazia
    if (comeco == NULL)
        return;

    do
    {
        mudanca = 0;
        ptr1 = comeco;

        // so entra se a fila não esta vazia
        while(ptr1->prox != lptr1)
        {
            // comparando elementos futuros
            if(ptr1->num > ptr1->prox->num)
            {
                // chamando a funcao para fazer a mudanca dos elementos
                mudanca_dados(ptr1,ptr1->prox);
                comeco = 1;
            }
            ptr1 = ptr1->prox;
        }
        lptr1 = ptr1;


    }
    while(mudanca);
}

// função que faz mudança de dados entre os nos
void mudanca_dados(struct fila *a,struct fila *b)
{
    // fazendo a mudança dos numeros dentro da fila
    int temp = a->num;
    a->num = b->num;
    b->num = temp;
}

void imprimirFila(); 
int deletar_pilha(int esc);
void entrada(int valor,int esc);
void mostrar_pilha(struct pilha*topo);
void imprimir(struct cadastro *inicio);
void ordenar(struct fila *comeco);
void mudanca_dados(struct fila *a,struct fila *b);




int main()
{
    int opc = 0;
    int valor;
    int esc;

    do
    {
        system("clear");
        ordenar(topo);
        printf("\n FILA ");
        printf("\n ----------");
        printf("\n");
        imprimirLista();
        printf("\n");
        printf("\n PILHA 1");
        printf("\n ----------");
        printf("\n");
        mostrar_pilha(top);
        printf("\n");
        printf("\n PILHA 2");
        printf("\n ----------");
        printf("\n");
        mostrar_pilha(top2);
        printf("\n");
        printf("\n");
        printf("\n 1 - [EMPILHAR]");
        printf("\n 2 - [DESEMPILHAR]");
        printf("\n 3 - [SAIR]");
        printf("\n Escolha um numero :");
        fflush(stdin);
        scanf("%d",&opc);


        switch(opc)
        {
        case 1:
            printf("1 - [PILHA-1] | 2 - [PILHA2]");
            printf("\n ESCOLHA:");
            fflush(stdin);
            scanf("%d",&esc);
            if(esc == 1)
            {
                printf("\n [EMPILHAR 1 ]");
                printf("\n VALOR:");
                fflush(stdin);
                scanf("%d",&valor);
                entrada(valor,esc);
            }
            else
            {
                printf("\n [EMPILHAR 2 ]");
                printf("\n VALOR:");
                fflush(stdin);
                scanf("%d",&valor);
                entrada(valor,esc);
            }

            break;
        case 2:
            printf("\n [DESEMPILHAR]");
            printf("1 - [PILHA-1] | 2 - [PILHA2]");
            printf("\n ESCOLHA:");
            fflush(stdin);
            scanf("%d",&esc);
            if(esc == 1)
            {
                printf("\n [DESEMPILHAR - 1]");
                valor = deletar_pilha(esc);
                inserir_fila(valor);
            }
            else
            {
                printf("\n [DESEMPILHAR - 2]");
                valor = deletar_pilha(esc);
                printf("\n %d");
                inserir_fila(valor);
            }
            break;
        default:
            break;
        }
    }
    while(opc != 3);
    return 0;
}
