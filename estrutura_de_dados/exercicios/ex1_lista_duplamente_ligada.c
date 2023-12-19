#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
    int qtd;
    struct registro * inicio;
    struct registro * fim;
}lista;

typedef struct registro
{
    int valor;
    struct registro * ant;
    struct registro * prox;
}registro;

lista *aloca_lista();
registro *aloca_registro();
void incluir_no_inicio(lista *l, int x);
void incluir_no_final(lista *l, int x);
void mostrar_lista(lista *l);
void mostrar_primo_lista(lista *l);
void mostrar_lista_contrario(lista *l);
void remover_elemento(lista *l, int x);
void remover_primos(lista *l);

int main()
{
    lista *l;
    int opcao,x;
    
    l= aloca_lista();

    do
    {
        printf("\n\n1-INCLUIR NO INICIO DA LISTA\n2-INCLUIR NO FINAL DA LISTA\n3-MOSTRAR LISTA\n4-MOSTRAR PRIMOS DA LISTA\n5-MOSTRAR LISTA DE TRAS PRA FRENTE\n6-REMOVER ELEMENTO DA LISTA\n7-REMOVER PRIMOS DA LISTA\n8-SAIR DO PROGRAMA\n\n\nOPCAO:");
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            printf("\n\nDigite o número que deseja inserir no inicio:");
            scanf("%d",&x);
            incluir_no_inicio(l,x);
            break;
        case 2:
            printf("\n\nDigite o número que deseja inserir no final:");
            scanf("%d",&x);
            incluir_no_final(l,x);
            break;
        case 3:
            mostrar_lista(l);
            break;
        case 4:
            mostrar_primo_lista(l);
            break;
        case 5:
            mostrar_lista_contrario(l);
            break;
        case 6:
            printf("\n\nDigite o número que deseja remover:");
            scanf("%d",&x);
            remover_elemento(l,x);
            break;
        case 7:
            remover_primos(l);
            break;
        case 9:
            printf("\nSaindo do programa\n");
            break;
        
        default:
            printf("\nOpcao invalida\n");
            break;
        }
    } while (opcao!=9);

    return 0;
}

lista *aloca_lista()
{
    lista *novo;
    novo = (lista *)calloc(1,sizeof(lista));
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)calloc(1,sizeof(registro));
    return novo;
}

void incluir_no_inicio(lista *l, int x)
{
    registro *novo, *aux;
    novo = aloca_registro();
    novo->valor = x;

    if (l->inicio==NULL)
    {
        l->inicio=novo;
        l->fim=novo;
        l->qtd++;
    }
    else
    {
        aux=l->inicio;
        aux->ant=novo;
        novo->prox=aux;
        l->inicio=novo;
        l->qtd++;
    }
}

void incluir_no_final(lista *l, int x)
{
    registro *novo,*aux;
    novo = aloca_registro();
    novo->valor = x;
    if (l->fim==NULL)
    {
        l->inicio=novo;
        l->fim=novo;
        l->qtd++;
    }
    else
    {
        aux=l->fim;
        aux->prox=novo;
        novo->ant=aux;
        l->fim=novo;
        l->qtd++;
    }
}

void mostrar_lista(lista *l)
{
    if (l->inicio == NULL)
    {
        printf("\nLista vazia\n");
    }
    else
    {
        registro *aux;
        aux = l->inicio;
        printf("\n\n\n-----------------------------LISTA---------------------------\n\n");
        while (aux)
        {
            printf("Valor = %d\n", aux->valor);
            aux = aux->prox;
        }
        printf("\n-----------------------------LISTA---------------------------\n\n\n");
    }
}

void mostrar_primo_lista(lista *l)
{
    registro *aux;
    if (l->inicio == NULL)
    {
        printf("\nLista vazia\n");
    }
    else
    {
        printf("\n\n\n-----------------------------LISTA PRIMOS---------------------------\n\n");
        aux=l->inicio;
        while (aux)
        {
            int contador=0;
            for (int i = 1; i <= aux->valor; i++)
            {
                if (aux->valor%i==0)
                {
                    contador++;
                }
            }
            if (contador==2)
            {
                printf("Valor:%d\n",aux->valor);
            }
            aux=aux->prox;
        }
        printf("\n-----------------------------LISTA PRIMOS---------------------------\n\n\n");
    }
}

void mostrar_lista_contrario(lista *l)
{
    if (l->inicio == NULL)
    {
        printf("\nLista vazia\n");
    }
    else
    {
        registro *aux;
        aux = l->fim;
        printf("\n\n\n-----------------------------LISTA CONTARIO---------------------------\n\n");
        while (aux)
        {
            printf("Valor = %d\n", aux->valor);
            aux = aux->ant;
        }
        printf("\n-----------------------------LISTA CONTARIO---------------------------\n\n\n");
    }
}

void remover_elemento(lista *l, int x)
{
    registro *aux, *aux2;
    
    if (l->inicio->valor==x)
    {
        aux=l->inicio;
        aux2=aux->prox;
        aux2->ant=NULL;
        l->inicio=aux2;
        free(aux);
        l->qtd--;
    }
    else if(l->fim->valor==x)
    {
        aux=l->fim;
        aux2=aux->ant;
        aux2->prox=NULL;
        l->fim=aux2;
        free(aux);
        l->qtd--;
    }
    else
    {
        aux=l->inicio;
        while(aux)
        {
            if (aux->valor==x)
            {
                aux2=aux->ant;
                aux2->prox=aux->prox;
                aux2=aux->prox;
                aux2->ant=aux->ant;
                free(aux);
                l->qtd--;
            }
            aux=aux->prox;
        }
    }
    printf("\n\nO numero %d foi removido\n\n",x);
}

void remover_primos(lista *l)
{
    registro *aux, *aux2;
    aux = l->inicio;

    while(aux!=NULL)
    {
        int contador=0;
        for (int i = 1; i <= aux->valor; i++)
        {
            if (aux->valor%i==0)
            {
                contador++;
            }
        }
        if (contador==2 && l->inicio->valor==aux->valor)
        {
            aux=l->inicio;
            aux2=aux->prox;
            aux2->ant=NULL;
            l->inicio=aux2;
            free(aux);
            l->qtd--;
        }
        else if(contador==2 && l->fim->valor==aux->valor)
        {
            aux=l->fim;
            aux2=aux->ant;
            aux2->prox=NULL;
            l->fim=aux2;
            free(aux);
            l->qtd--;
        }
        else if(contador==2)
        {
            aux2=aux->ant;
            aux2->prox=aux->prox;
            aux2=aux->prox;
            aux2->ant=aux->ant;
            free(aux);
            l->qtd--;
        }
        aux=aux->prox;
    }
    printf("\nTODOS OS PRIMOS FORAM REMOVIDOS DA LISTA\n");
}


