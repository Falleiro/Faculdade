#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int *cria_vetor(long long int n);
void mostrar_vetor(long long int *vet, long long int n);
int buscabinaria(long long int *vet,long long int inicio, long long int n, long long int x);
int buscapadrao(long long int *vet, long long int n, long long int x);

int main()
{
    long long int n, *vet, x;
    double t1,t2,temponormal1,tempornormal2;
    int resultado;

    srand(time(NULL));
    printf("\nDigite o tamanho do vetor:");
    scanf("%lld",&n);
    vet=cria_vetor(n);
    mostrar_vetor(vet,n);
    printf("\nDigite um numero para ser buscado no vetor:");
    scanf("%lld",&x);
    
    t1=omp_get_wtime();
    resultado=buscabinaria(vet,0,n,x);
    t2=omp_get_wtime();
    if (resultado)
        printf("\nO numero %lld foi encontrado no vetor por meio da busca binaria\n",x);
    else
        printf("\nO numero %lld nao foi encontrado no vetor por meio da busca binaria\n",x);

    temponormal1=omp_get_wtime();
    resultado=buscapadrao(vet,n,x);
    tempornormal2=omp_get_wtime();
    if (resultado)
        printf("\nO numero %lld foi encontrado no vetor por meio da busca sequencial\n",x);
    else
        printf("\nO numero %lld nao foi encontrado no vetor por meio da busca sequencial\n",x);

    printf("\nO tempo de busca pela forma binaria foi de:%f",t2-t1);
    printf("\n\nO tempo de busca pela forma sequencial foi de:%f",tempornormal2-temponormal1);
    printf("\n");
    return 0;
}

long long int *cria_vetor(long long int n)
{
    long long int *vet, sorteio, aux;

    vet = (long long int *)calloc(n, sizeof(long long int));

    sorteio = rand() % 5;
    vet[0]=sorteio;
    for (int i = 1; i < n; i++)
    {
        sorteio = vet[i-1]+(rand() % 5);
        vet[i]=sorteio;
    }
    return vet;
}

void mostrar_vetor(long long int *vet, long long int n)
{
    for (long long int i = 0; i < n; i++)
    {
        printf("%lld ", vet[i]);
    }
}

int buscabinaria(long long int *vet,long long int inicio, long long int fim, long long int x)
{
    long long int parcial = (fim + inicio) /2;
    
    if (vet[parcial]==x)
    {
        return 1;
    }
    if (inicio==fim-1)
    {
        return 0;
    }
    else if(vet[parcial]<x)
    {
        buscabinaria(vet,parcial,fim,x);
    }
    else
    {
        buscabinaria(vet,inicio,parcial,x);
    }
}

int buscapadrao(long long int *vet, long long int n, long long int x)
{
    for (int i = 0; i < n; i++)
        if (vet[i]==x)
            return 1;
    return 0;
}

