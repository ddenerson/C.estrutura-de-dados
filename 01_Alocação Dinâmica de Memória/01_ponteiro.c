#include <stdio.h>
#include <stdlib.h>
#define TAM 99

/*
O seu programa deve implementar uma função chamada inverte_vetor,
que cria dois vetores dinamicamente V1 e V2, ambos de tamanho N.
A função deve copiar os elementos de V1 para V2 na ordem inversa. Ou seja, se
a função receber V1 = {1,2,3,4,5}, a função deve copiar os elementos para V2 na
seguinte ordem: V2 = {5,4,3,2,1}.
*/



void inverte_vetor(int *v1, int *v2, int n)
{

    int i;

    for(i = 0; i < n ; i++)
    {
        system("clear");
        printf("\n [%d] :",(i+1));
        scanf("%d",&v1[i]);
    }

    printf("\n SEM INVERTER A ORDEM");
    for(int i = 0; i < n; i++)
    {
        printf("\n [%d]",v1[i]);
    }
    for(i = 0 ; i < n ; i++)
    {
        v2[i] = v1[n-i-1];
    }
    printf("\n ---------------");
    printf("\n FORMA INVERTIDA");
    for( i = 0 ; i < n ; i++)
    {
        printf("\n -  [%d] ",v2[i]);
        v2++;
    }

}

void multiplica_escalar(int *v1, int *v2, int n,int x)
{

    for(int i = 0; i < n ; i++)
    {
        v2[i] = v1[i] * x;
    }
    printf("\n ----------");
    printf("\n SEM MULTIPLICAR");
    for(int i = 0; i < n ; i++)
    {
        printf("\n - [%d]",v1[i]);
    }
    printf("\n -------------------");
    printf(" \n VETOR MULTIPLICADO");
    for(int i = 0; i < n ; i++)
    {
        printf("\n - [%d]",v2[i]);
    }
}



int main()
{
    int v[TAM];
    int v2[TAM];


    inverte_vetor(v,v2,3);
    multiplica_escalar(v,v2,3,4);



    return 0;
}
