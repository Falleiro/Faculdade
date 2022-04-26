#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
    int qtd, dados[10];
}pilha;

pilha *aloca_pilha();
int empty(pilha *p);
int push(pilha *p,int x);
int pop(pilha *p);
int stackpop(pilha *p);
pilha *inverter_ordem(pilha *p);
pilha *inverte_primeiro_ultimo(pilha *p);
pilha *pares_base(pilha*p);
void mostrar(pilha *p);

int main()
{
    int opcao, numero;
    pilha *p;
    p = aloca_pilha();

    do
    {
        printf("\n1-Push");
        printf("\n2-Pop");
        printf("\n3-Stackpop");
        printf("\n4-Inverter ordem da pilha");
        printf("\n5-Inverter o primeiro elemento com o ultimo da pilha");
        printf("\n6-Colocar os pares na base da pilha e os impares no topo");
        printf("\n7-Mostrar pilha");
        printf("\n8-Sair\n");
        printf("Opcao:");
        scanf("%d", &opcao);

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
                numero = pop(p);
                printf("\nNumero que saiu da pilha:%d\n", numero);
            }
            else
            {
                printf("\nPilha vazia\n");
            }
            break;
        case 3:
            if (!empty(p))
            {
                numero = stackpop(p);
                printf("\nNumero que esta pra sair:%d\n", numero);
            }
            else
            {
                printf("\nPilha vazia\n");
            }
            break;
        case 4:
            if (!empty(p))
            {
                p = inverter_ordem(p);
                printf("\nPilha invertida\n");
            }
            else
            {
                printf("\nPilha vazia\n");
            }
            break;
        case 5:
            if (!empty(p))
            {
                p = inverte_primeiro_ultimo(p);
                printf("\nPrimeiro e ultimo elementos invertidos\n");
            }
            else
            {
                printf("\nPilha vazia\n");
            }
            break;
        case 6:
            if (!empty(p))
            {
                printf("\nPares na base e impares no topo\n");
                p = pares_base(p);
            }
            else
            {
                printf("\nPilha vazia\n");
            }
            break;
        case 7:
            if (!empty(p))
            {
                printf("\nMostrando lista\n");
                mostrar(p);
            }
            else
            {
                printf("\nPilha vazia\n");
            }
            break;
        case 8:
            printf("\nSaindo do programa\n");
            break;
        default:
            printf("\nOpcao invalida\n");
            break;
        }
    } while (opcao!=8);
    
    return 0;
}

pilha *aloca_pilha()
{
    pilha *novo;
    novo = (pilha*)calloc(1,sizeof(pilha));
    return novo;
}

int empty(pilha *p)
{
    if (p->qtd==0)
        return 1;
    else
        return 0;
}

int push(pilha *p,int x)
{
    if(p->qtd==10)
    {
        printf("\nPilha cheia\n");
    }
    else
    {
        p->dados[p->qtd]=x;
        p->qtd++;
    }
}

int pop(pilha *p)
{
    return p->dados[--p->qtd];
}

int stackpop(pilha *p)
{
    return p->dados[p->qtd-1];
}

pilha *inverter_ordem(pilha *p)
{
    pilha * invertida = aloca_pilha();
    while (p->qtd > 0)
    {
        invertida->dados[invertida->qtd] = p->dados[p->qtd-1];
        p->qtd--;
        invertida->qtd++;
    }
    return invertida;
}

pilha *inverte_primeiro_ultimo(pilha *p)
{
    int aux;
    aux=p->dados[0];
    p->dados[0]=p->dados[p->qtd-1];
    p->dados[p->qtd-1]=aux;
}

pilha *pares_base(pilha *p)
{
    pilha *par = aloca_pilha(), *impar = aloca_pilha();
    while (p->qtd > 0)
    {
        if (p->dados[p->qtd-1]%2==0)
        {
            par->dados[par->qtd]=p->dados[p->qtd-1];
            par->qtd++;
        }
        else
        {
            impar->dados[impar->qtd]=p->dados[p->qtd-1];
            impar->qtd++;
        }
        p->qtd--;
    }
    while (par->qtd > 0 || impar->qtd > 0)
    {
        if (par->qtd > 0)
        {    
            p->dados[p->qtd]=par->dados[par->qtd-1];
            par->qtd--;
        }
        else
        {
            p->dados[p->qtd]=impar->dados[impar->qtd-1];
            impar->qtd--;
        }
        p->qtd++;
    }
    return p;
}

void mostrar(pilha *p)
{   
    printf("\n\n\n-----------------MOSTRANDO PILHA-------------------\n");
    for (int i = p->qtd-1; i >= 0; i--)
    {
        printf("Valor:%d\n",p->dados[i]);
    }
    printf("\n-----------------MOSTRANDO PILHA-------------------\n\n\n");
}