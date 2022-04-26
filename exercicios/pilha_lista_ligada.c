#include <stdio.h>
#include <stdlib.h>


typedef struct pilha
{
    int qtd;
    struct registro * topo;
}pilha;

typedef struct registro
{
    int valor;
    struct registro * ant;
}registro;

pilha *aloca_pilha();
registro *aloca_registro();
int empty(pilha *p);
void push(pilha *p,int x);
int pop(pilha *p);

int main()
{
    pilha *p;
    int opcao, numero;

    p = aloca_pilha();
    do
    {
        printf("\n1-Push");
        printf("\n2-Pop");
        printf("\n3-Stackpop");
        printf("\n4-Sair\n");
        printf("Opcao:");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
            printf("\nDigite um numero:");
            scanf("%d", &numero);
            push(p,numero);
            break;
        case 2:
            if (!empty(p))
            {
                printf("\nNumero que saiu=%d\n",pop(p));
            }
            else
            {
                printf("\nPilha vazia\n");
            }

            break;
        case 3:
            if (!empty(p))
            {
                printf("\nNumero que esta para sair:%d\n",p->topo->valor);
            }
            else
            {
                printf("\nPilha vazia\n");
            }
            break;
        case 4:
            printf("\nSaindo do programa\n");
            break;
        default:
            printf("\nOpcao invalida\n");
            break;
        }
    } while (opcao!=4);
    
}

pilha *aloca_pilha()
{
    pilha *novo;
    novo = (pilha*)calloc(1,sizeof(pilha));
    return novo;
}

registro *aloca_registro()
{
    registro *novo;
    novo = (registro *)calloc(1,sizeof(registro));
    return novo; 
}

int empty(pilha *p)
{
    if(p->topo==NULL)
        return 1;
    else
        return 0;
}

void push(pilha *p, int x)
{
    registro *novo;
    novo = aloca_registro();
    novo->valor=x;
    if (p->topo==NULL)
    {
        p->topo=novo;
        p->qtd++;
    }
    else
    {
        novo->ant=p->topo;
        p->topo=novo;
        p->qtd++;
    }
}
int pop(pilha *p)
{
    registro *aux;

    if (p->topo->ant==NULL)
    {
        p->topo=NULL;
    }
    else
    {
        aux=p->topo;
        p->topo=p->topo->ant;
        p->qtd--;
    }
    return aux->valor;
}

