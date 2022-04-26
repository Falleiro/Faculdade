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
lista *remove_perfeitos(lista*l);
int perfeito(int numero);

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
    l=remove_perfeitos(l);
    mostra(l);
    return 1;
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
        l->qtd++;
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

lista *remove_perfeitos(lista *l)
{
    registro *aux=NULL,*ant=NULL, *apagado=NULL;
    if (l->inicio==NULL)
    {
        printf("\nLista vazia\n");
        return 0;
    }

    aux=l->inicio;
    while (aux!=NULL)
    {
        if (perfeito(aux->valor))
        {
            apagado=aux;
            if (ant==NULL)
            {
                l->inicio=l->inicio->prox;
                aux->prox=NULL;
                aux=l->inicio;
                free(apagado);
                l->qtd--;
            }
            else
            {
                ant->prox=aux->prox;
                aux->prox=NULL;
                aux=ant->prox;
                free(apagado);
                l->qtd--;
            }   
        }
        else
        { 
            ant=aux;
            aux=aux->prox;
        }
        
    }
    return l;
}

int perfeito(int x)
{
    int soma=0;
    for (int i = 1; i <= x/2; i++)
    {
        if (x%i==0)
        {
            soma=soma + i;
        }
    }
    if (soma==x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}