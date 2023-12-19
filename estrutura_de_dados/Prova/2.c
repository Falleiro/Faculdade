#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
}lista;

typedef struct registro
{
    int valor;
    struct registro *prox;
}registro;

lista *aloca_lista();
registro *aloca_registro();
void incluir(lista *l, int x);
void mostra(lista *l);
lista *primos_no_inicio(lista *l);
int primo(int x);

int main()
{
    int x, qtd;
    lista *l;
    l=aloca_lista();

    printf("Insira a quantidade de numeros da lista:");
    scanf("%d",&qtd);

    for (int i = 0; i < qtd; i++)
    {
        printf("Insira o numero para ser incluido na lista:");
        scanf("%d",&x);
        incluir(l,x);
    }
    l=primos_no_inicio(l);
    mostra(l);
    
    return 0;
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista*)calloc(1,sizeof(lista));
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)calloc(1,sizeof(registro));
    return novo;
}

void incluir(lista *l, int x)
{
    registro *novo,*aux=NULL;
    novo = aloca_registro();
    novo->valor=x;

    if (l->inicio==NULL)
    {
        l->inicio=novo;
    }
    else
    {
        aux=l->inicio;
        while (aux->prox!=NULL)
        {
            aux=aux->prox;
        }
        aux->prox=novo;
    }
    l->qtd++;
}

lista *primos_no_inicio(lista *l)
{
    registro *aux, *ant, *numero_primo;
    if (l->inicio==NULL)
    {
        printf("\nLista vazia\n");
        return 0;
    }
    aux=l->inicio;
    while (aux!=NULL)
    {
        if (primo(aux->valor))
        {
            numero_primo=aux;
            aux=aux->prox;
            ant->prox=aux;
            numero_primo->prox=l->inicio;
            l->inicio=numero_primo;
        }
        else
        {
            ant=aux;
            aux=aux->prox;
        }
    }
    return l;
}

void mostra(lista *l)
{
    registro *aux;
    if (l->inicio==NULL)
    {
        printf("\nA lista esta vazia\n");
    }
    else
    {
        aux=l->inicio;
        printf("\n\n----------------LISTA----------------\n");
        while (aux!=NULL)
        {
            printf("Valor = %d\n",aux->valor);
            aux = aux->prox;
        }
        printf("\n----------------LISTA----------------\n\n");
    }
}

int primo(int x)
{
    if (x==0 || x==1)
    {
        return 0;
    }
    
    for (int i = 2; i < x; i++)
    {
        if (x%i==0)
        {
            return 0;
        }
    }
    return 1;
}