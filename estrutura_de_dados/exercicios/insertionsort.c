#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int *cria_vetor(long long int n);
void mostrar_vetor(long long int *vet, long long int n);
void insertionsort(long long int *vet, long long int n);

int main()
{
    long long int n, *vet;

    srand(time(NULL));
    double t1,t2;

    FILE * arq;

    arq = fopen("tempos.csv","a+");
    if ( arq==NULL)
        return 0;
    

    for (n = 10000; n < 200000; n = n + 10000)
    {
        printf("\n Tamanho do vetor: %lld",n);
        vet=cria_vetor(n);
        t1 = omp_get_wtime();
        insertionsort(vet,n);
        t2 = omp_get_wtime();
        printf("\n Tempo para ordenar: %f",t2-t1);
        fprintf(arq,"%lld;%f\n",n,t2-t1);
        free(vet);
    }
    
    fclose(arq);
    printf("\n");
    return 0;
}

long long int *cria_vetor(long long int n)
{
    long long int *vet, sorteio, aux;

    vet = (long long int *)calloc(n, sizeof(long long int));

    for (int i = 0; i < n; i++)
    {
        vet[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        sorteio = rand() % n;
        aux = vet[i];
        vet[i] = vet[sorteio];
        vet[sorteio] = aux;
    }
    return vet;
}

void mostrar_vetor(long long int *vet, long long int n)
{
    for (long long int i = 0; i < n; i++)
    {
        printf(" %lld", vet[i]);
    }
}

void insertionsort(long long int *vet, long long int n)
{
    long long int aux, i, j;
    for (i = 1; i < n; i++)
    {
        aux=vet[i];
        for (j = i-1; j >= 0 && aux < vet[j]; j--)
        {
            vet[j+1]=vet[j];
        }
        vet[j+1]=aux;
    }
    return;
}