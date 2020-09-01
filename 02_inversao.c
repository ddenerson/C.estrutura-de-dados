#include <stdio.h>
#include <stdlib.h>

/*
O seu programa deve implementar uma função chamada inverte_vetor, que
Cria dois vetores dinamicamente V1 e V2, ambos de tamanho N.
A função deve copiar os elementos de V1 para V2 na ordem inversa. Ou seja, se
a função receber V1 = {1,2,3,4,5}, a função deve copiar os elementos para V2 na
seguinte ordem: V2 = {5,4,3,2,1}.
Além disso,encontre o maior valor em V1
*/

void inverte_vetor(int *v1,int n)
{
    int *v2;

    v2 = (int*)malloc(n*sizeof(int));

    for(int i = 0; i < n ; i++)
    {
        v2[i] = v1[n-i-1];
    }
    for(int i = 0; i < n ; i++)
    {
        v1[i] = v2[i];

    }

    free(v1);
}


int main()
{
    int *vet,n,maior;

    printf("Digite qtd de espaco no vetor:");
    fflush(stdin);
    scanf("%d",&n);

    vet = (int*)malloc(n*sizeof(int));

    for(int i = 0; i < n ; i++)
    {
        system("clear");
        printf("\n [%d]",(i+1));
        fflush(stdin);
        scanf("%d",&vet[i]);
    }
    for(int i = 0; i < n ; i++)
    {
        if(i == 0)
        {
            maior = vet[i];
        }
        else
        {
            if(vet[i] > maior)
            {
                maior = vet[i];
            }
        }
    }

    inverte_vetor(vet,n);

    for(int i = 0; i < n ; i++)
    {
        printf("\n [%d]",vet[i]);
        vet[i]++;
    }

    printf("\n O maior valor  : [%d]",maior);


    return 0;
}
