#include <stdio.h>
#include <stdlib.h>

typedef struct fila
{
    int qtd;
    struct elemento *inicio;
    struct elemento *fim;
}fila;

typedef struct elemento
{
    int valor;
    struct elemento * prox;
}elemento;

fila *aloca_pilha();
elemento *aloca_elemento();
void cria(fila *baralho, int n);
void operacao(fila *baralho, int n);

int main()
{
    int n;
    fila *baralho;
    printf("Insira a quantidade de cartas:");
    scanf("%d",&n);
    baralho=aloca_pilha();
    cria(baralho,n);
    operacao(baralho,n);

    return 0;
}

fila *aloca_pilha()
{
    fila *novo;
    novo = (fila *)calloc(1,sizeof(fila));
    return novo;
}

elemento *aloca_elemento()
{
    elemento *novo;
    novo = (elemento*)calloc(1,sizeof(elemento));
    return novo;
}

void cria(fila *baralho, int n)
{
    for (int i = 1; i <= n; i++)
    {
        elemento *novo;
        novo = aloca_elemento();
        novo->valor=i;
        if (baralho->inicio == NULL && baralho->fim == NULL)
        {
            baralho->inicio= novo;
            baralho->fim= novo;
        }
        else
        {
            baralho->fim->prox=novo;
            baralho->fim=novo;
        }
        baralho->qtd++;
    }
}

void operacao(fila *baralho, int n)
{
    for (n; n >= 2; n--)
    {
        elemento *aux;
        aux = aloca_elemento();
        printf("%d\n", baralho->inicio->valor);
        aux = baralho->inicio;
        baralho->inicio=baralho->inicio->prox;
        free(aux);
        baralho->qtd--;
        aux = baralho->inicio;
        baralho->inicio=baralho->inicio->prox;
        baralho->fim->prox=aux;
        baralho->fim=aux;
    }
    printf("Carta q sobrou:%d",baralho->fim->valor);
}