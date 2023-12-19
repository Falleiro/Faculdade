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

void mostrar_lista(lista *l);

int main()
{
    lista *par, *impar;
    int x;

    par=aloca_lista();
    impar=aloca_lista();

    for(int i=0; i<10; i++)
    {
        printf("Qual numero deseja inserir:");
        scanf("%d",&x);
        if (x%2==0 && x>0)
        {
            incluir_no_final(par,x);
        }
        if (x%2!=0 && x>0)
        {
            incluir_no_final(impar,x);
        }
    } 
    printf("\n\nPares:");
    mostrar_lista(par);
    printf("\n\nImpares:");
    mostrar_lista(impar);

    printf("\n");
    return 0;
}

lista * aloca_lista()
{
    lista *novo;
    novo = (lista *)malloc(sizeof(lista));
    novo->qtd = 0;
    novo->inicio = NULL;
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)malloc(sizeof(registro));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;
}

void incluir_no_final(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio == NULL)
    {
        l->inicio = novo;
    }
    else
    {
        aux = l->inicio;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
    l->qtd++;
}

void mostrar_lista(lista *l)
{
    if (l->inicio == NULL)
    {
        printf("\n Lista vazia");
    }
    else
    {
        registro *aux;
        aux = l->inicio;

        while (aux != NULL)
        {
            printf("\nValor = %d", aux->valor);
            aux = aux->prox;
        }
    }
}
