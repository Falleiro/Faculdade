#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
} lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
} registro;

lista *aloca_lista();
registro *aloca_registro();
void incluir_no_final(lista *l, int x);
void mostrar_lista(lista *l1, lista * l2);

int main()
{
    lista * l1, * l2;
    int qtd,x=0;
    printf("Insira a quantidade de números para serem armazenados:");
    scanf("%d",&qtd);
    l1 = aloca_lista();
    l2 = aloca_lista();
    int i;
    for (i = 0; i < qtd/2; i++)
    {
        printf("Número a ser inserido na lista 1:");
        scanf("%d",&x);
        incluir_no_final(l1,x);
    }
    for (int j = i; j < qtd; j++)
    {
        printf("Número a ser inserido na lista 2:");
        scanf("%d",&x);
        incluir_no_final(l2,x);
    }
    
    mostrar_lista(l1,l2);
    printf("\n");

    return 0;
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)callor(1,sizeof(lista));
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)calloc(1,sizeof(registro));
    return novo;
}

void incluir_no_final(lista *l, int x)
{
    registro *novo, *aux=NULL,*ant=NULL;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;
        while (aux->prox != NULL && aux->valor<x)
        {
            ant = aux;
            aux = aux->prox;
        }
        if (aux->valor > x)
        {
            if (ant==NULL)
            {
                l->inicio=novo;
            }
            else
            {
                ant->prox=novo;
            }
            novo->prox=aux;            
        }
        else
        {
            aux->prox=novo;
        }
    }
    l->qtd++;
}

void mostrar_lista(lista *l1, lista * l2)
{
    if (l1->inicio == NULL || l2->inicio == NULL)
    {
        printf("\n Alguma das listas esta vazia");
    }
    else
    {
        registro *aux1, *aux2;
        aux1 = l1->inicio;
        aux2 = l2->inicio;
        
        while (aux1 != NULL && aux2 != NULL )
        {
            if (aux1->valor==aux2->valor)
            {
                printf("\nValor: %d\n",aux1->valor);
                
                aux1 = aux1->prox;
                aux2 = aux2->prox;
            }
            else
            {
                if (aux1->valor < aux2->valor)
                {
                    aux1 = aux1->prox;
                }
                else
                {
                    aux2 = aux2->prox;
                }
            }
        }
    }
}