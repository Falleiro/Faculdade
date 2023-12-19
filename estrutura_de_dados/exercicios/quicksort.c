#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "omp.h"

long long int *cria_vetor(long long int n);
void mostrar_vetor(long long int *vet, long long int n);
void quicksort(long long int *vet, long long int inicio, long long int fim);
void troca (long long int *vet, long long int i, long long int j);
int divide(long long int *vet, long long int inicio, long long int fim);

int main()
{
    long long int n, *vet;

    srand(time(NULL));
    double t1,t2;

    FILE * arq;

    arq = fopen("temposquick.csv","a+");
    if ( arq==NULL)
        return 0;
    

    for (n = 1000000; n <= 100000000; n = n + 1000000)
    {
        printf("\n Tamanho do vetor: %lld",n);
        vet=cria_vetor(n);
        // printf("\n Vetor desordenado:");
        // mostrar_vetor(vet,n);
        t1 = omp_get_wtime();
        quicksort(vet,0,n-1);
        t2 = omp_get_wtime();
        // printf("\n Vetor ordenado:");
        // mostrar_vetor(vet,n);
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

void quicksort(long long int *vet, long long int inicio, long long int fim)
{
    if (inicio >= fim)
        return;
    int pivo=divide(vet,inicio,fim);
    quicksort(vet,inicio,pivo-1);
    quicksort(vet,pivo+1,fim);
}

int divide(long long int *vet, long long int inicio, long long int fim)
{
    int i=inicio;

    for (int j = inicio; j < fim; j++)
    {
        if (vet[j] <= vet[fim])
        {
            troca(vet,i++,j);
        }
    }
    troca(vet,i,fim);

    return i;
}

void troca(long long int *vet, long long int i, long long int j)
{
    int k=vet[i];
    vet[i]=vet[j];
    vet[j]=k;
}