#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
    struct registro *fim;
}lista;

typedef struct registro
{
    int valor;
    struct registro *ant;
    struct registro *prox;
}registro;

lista *aloca_lista();
registro *aloca_registro();
void incluir(lista *l, int x);
void mostra(lista *l);
lista *inverte_listas(lista *la, lista *lb);

int main()
{
    lista *la, *lb;
    la=aloca_lista();
    lb=aloca_lista();
    int x, qtd;


    printf("Insira a quantidade de numeros da lista 1:");
    scanf("%d",&qtd);
    for (int i = 0; i < qtd; i++)
    {
        printf("Insira o numero para ser incluido na lista 1:");
        scanf("%d",&x);
        incluir(la,x);
    }

    printf("Insira a quantidade de numeros da lista 2:");
    scanf("%d",&qtd);
    for (int i = 0; i < qtd; i++)
    {
        printf("Insira o numero para ser incluido na lista 2:");
        scanf("%d",&x);
        incluir(lb,x);
    }

    inverte_listas(la,lb);


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
    registro *novo;
    novo = aloca_registro();
    novo->valor=x;

    if (l->inicio==NULL)
    {
        l->inicio=novo;
        l->fim=novo;
    }
    else
    {
        l->fim->prox=novo;
        novo->ant = l->fim;
        l->fim=novo;
    }
    l->qtd++;
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
        int contador=0;
        while (contador!=l->qtd)
        {
            printf("Valor = %d\n",aux->valor);
            aux = aux->prox;
            contador++;
        }
    }
}

lista *inverte_listas(lista *la, lista *lb)
{
    lista *novoa, *novob;
    registro *novo, *aux;
    novoa=aloca_lista();
    novob=aloca_lista();

    aux=la->fim;
    while (novob->qtd!=la->qtd)
    {
        novo = aloca_registro();
        novo->valor=aux->valor;
        if (novob->inicio==NULL)
        {
            novob->inicio=novo;
            novob->fim=novo;
        }
        else
        {
            novob->fim->prox=novo;
            novo->ant=novob->fim;
            novob->fim=novo;
        }
        novob->qtd++;
        aux=aux->ant;
        printf("Teste a\n");
    }

    aux=lb->fim;
    while (novoa->qtd!=lb->qtd)
    {
        novo = aloca_registro();
        novo->valor=aux->valor;
        if (novoa->inicio==NULL)
        {
            novoa->inicio=novo;
            novoa->fim=novo;
        }
        else
        {
            novoa->fim->prox=novo;
            novo->ant=novoa->fim;
            novoa->fim=novo;
        }
        novoa->qtd++;
        aux=aux->ant;
        printf("Teste b\n");
    }

     printf("\n\n----------------LISTA A NOVA----------------\n");
    mostra(novoa);
    printf("\n----------------LISTA A NOVA----------------\n\n");
    printf("\n----------------LISTA B NOVA----------------\n");
    mostra(novob);
    printf("\n\n----------------LISTA B NOVA----------------\n");
}