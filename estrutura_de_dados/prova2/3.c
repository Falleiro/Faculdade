#include <stdio.h>
#include <stdlib.h>

typedef struct arvore
{
    int qtd_elementos;
    struct no *raiz;
}arvore;

typedef struct no
{
    int valor;
    struct no *esquerda;
    struct no *direita;
}no;

arvore *aloca_arvore();
no *aloca_no();
void incluir(arvore *a, int x);
int qtd_primos(no *a,int qtd);


int main()
{
    arvore *a;
    a=aloca_arvore();
    int opcao,x;

    while (opcao!=3)
    {
        int qtd=0;
        printf("\n1-INCLUIR NUMERO");
        printf("\n2-QUANTOS NUMEROS PRIMOS TEM NA ARVORE");
        printf("\n3-SAIR DO PROGRAMA\n");
        printf("OPCAO:");
        scanf("%d",&opcao);
        
        switch (opcao)
        {
        case 1:
            printf("\n\nDIGITE UM NUMERO PARA INSERIR:");
            scanf("%d",&x);
            incluir(a,x);
            break;

        case 2:
            qtd=qtd_primos(a->raiz,qtd);
            printf("\n\nHÁ %d NUMEROS PRIMOS NA ARVORE\n\n",qtd);
            break;

        case 3:
            printf("\n\nSAINDO DO PROGRAMA\n\n");
            return 0;
            break;
        
        default:
            printf("\n\nOPCAO INVALIDA\n\n");
            break;
        }
    }
}

arvore *aloca_arvore()
{
    arvore *novo;
    novo= (arvore*)calloc(1,sizeof(arvore));
    return novo;
}

no *aloca_no()
{
    no *novo;
    novo= (no*)calloc(1,sizeof(no));
    return novo;
}

void incluir(arvore *a, int x)
{
    no *novo, *aux;
    novo = aloca_no();
    novo->valor=x;
    int inseriu=0;

    if (a->raiz==NULL)
    {
        a->raiz=novo;
        a->qtd_elementos++;
        printf("\n\nO NUMERO %d FOI INCLUIDO\n\n",novo->valor);
    }
    else
    {
        aux = a->raiz;
        while (!inseriu)
        {
            if (aux->valor==x)
            {
                printf("\n\nO NUMERO JA ESTA NA ARVORE\n\n");
                return;
            }
            else
            {
                if (x < aux->valor)
                {
                    if (aux->esquerda==NULL)
                    {
                        aux->esquerda=novo;
                        a->qtd_elementos++;
                        printf("\n\nO NUMERO %d FOI INCLUIDO\n\n",novo->valor);
                        inseriu=1;
                    }
                    else
                        aux=aux->esquerda;
                }
                else
                {
                    if (aux->direita==NULL)
                    {
                        aux->direita=novo;
                        a->qtd_elementos++;
                        printf("\n\nO NUMERO %d FOI INCLUIDO\n\n",novo->valor);
                        inseriu=1;
                    }
                    else
                        aux=aux->direita;
                }
            }
        }
    }
}

int qtd_primos(no *a,int qtd)
{
    if (a==NULL)
        return qtd;

    int isprimo=0;
    for (int i = 1; i <= a->valor; i++)
    {
        if (a->valor%i==0)
            isprimo++;
    }
    if (isprimo==2)
    {
        qtd++;
        printf("\nNUMERO PRIMO %d ENCONTRADO\n",a->valor);
    }
    
    qtd_primos(a->esquerda,qtd);
    qtd_primos(a->direita,qtd);
}