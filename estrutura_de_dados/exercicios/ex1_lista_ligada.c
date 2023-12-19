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
void mostrar_lista_par(lista *l);

int main()
{
    lista *l1;
    int opcao, x=0;
    
    l1= aloca_lista();

    do
    {
        printf("-----------------------------Menu---------------------------------------\n");
        printf("Digite 1 para incluir um número na lista\nDigite 2 para mostar a lista \nDigite 3 para mostrar os números pares da lista \nDigite um número menor que 0 para parar\n");
        printf("-----------------------------Menu---------------------------------------\n");
        printf("Opcao:");

       scanf("%d",&opcao);

        if (opcao==1)
        {
            printf("\nDigite o numero para incluir na lista:");
            scanf("%d",&x);
            incluir_no_final(l1, x);
        }
        if (opcao==2)
        {
            mostrar_lista(l1);
        }
        if (opcao==3)
        {
            mostrar_lista_par(l1);
        }
        

    } while (opcao>=0);
    return 0;
}

lista *aloca_lista()
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
        printf("\n Lista vazia\n");
    }
    else
    {
        registro *aux;
        aux = l->inicio;

        while (aux != NULL)
        {
            printf("\nValor = %d\n", aux->valor);
            aux = aux->prox;
        }
    }
}

void mostrar_lista_par(lista *l)
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
            if (aux->valor%2==0)
            {
                printf("\nValor par = %d\n", aux->valor);
            }
                aux = aux->prox;
        }
    }
}