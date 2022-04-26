#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct lista
{
    int qtd;
    struct registro *inicio;
}lista;

typedef struct registro
{
    char valor;
    struct registro *prox;
}registro;

lista *aloca_lista();
registro *aloca_registro();
lista *separa_vogais_consoantes(lista *la, lista *lb, lista *lc);
void incluir(lista *la, char x);
void mostrar_a(lista *la);
void mostrar_vogais(lista *lb);
void mostrar_consoantes(lista *lc);

int main(){
    int opcao;
    char x;
    lista *la, *lb, *lc;
    la = aloca_lista();
    lb = aloca_lista();
    lc = aloca_lista();

    do
    {
        printf("\n1-Inserir caractere na lista A\n");
        printf("2-Separar vogais e consoantes\n");
        printf("3-Mostrar vogais\n");
        printf("4-Mostrar consoantes\n");
        printf("5-Sair do programa\n");
        printf("6-Mostrar lista LA\n");
        printf("Opcao:");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
            printf("\nInsira o caractere que deseja colocar na lista A:");
            __fpurge(stdin);
            scanf("%c",&x);
            printf("\nInserindo caractere '%c' na lista A\n",x);
            incluir(la,x);
            break;
        case 2:
            printf("\nSeparando vogais e consoantes\n");
            separa_vogais_consoantes(la,lb,lc);
            break;
        case 3:
            printf("\nMostrando vogais\n");
            mostrar_vogais(lb);
            break;
        case 4:
            printf("\nMostrando consoantes\n");
            mostrar_consoantes(lc);
            break;
        case 5:
            printf("\nSaindo do programa\n");
            break;
        case 6:
            printf("\nMostrando Lista A\n");
            mostrar_a(la);
            break;
        
        default:
            printf("\nOpcao invalida\n");
            break;
        }
    } while (opcao!=5);
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

void incluir(lista *la, char x)
{
    registro *novo,*aux=NULL;
    novo = aloca_registro();
    novo->valor=x;

    if (la->inicio==NULL)
    {
        la->inicio=novo;
        la->qtd++;
    }
    else
    {
        aux=la->inicio;
        while (aux->prox!=NULL)
        {
            aux=aux->prox;
        }
        aux->prox=novo;
    }
    la->qtd++;
}

void mostrar_a(lista *la)
{
    registro *aux=NULL;
    if (la->inicio==NULL)
    {
        printf("\nA lista esta vazia\n");
    }
    else
    {
        aux=la->inicio;
        printf("\n\n----------------LISTA----------------\n");
        while (aux!=NULL)
        {
            printf("Valor = %c\n",aux->valor);
            aux = aux->prox;
        }
        printf("\n----------------LISTA----------------\n\n");
    }
}
void mostrar_vogais(lista *lb)
{
    registro *aux=NULL;
    if (lb->inicio==NULL)
    {
        printf("\nA lista esta vazia\n");
    }
    else
    {
        aux=lb->inicio;
        printf("\n\n----------------LISTA VOGAIS----------------\n");
        while (aux!=NULL)
        {
            printf("Valor = %c\n",aux->valor);
            aux = aux->prox;
        }
        printf("\n----------------LISTA VOGAIS----------------\n\n");
    }
}
void mostrar_consoantes(lista *lc)
{
    registro *aux=NULL;
    if (lc->inicio==NULL)
    {
        printf("\nA lista esta vazia\n");
    }
    else
    {
        aux=lc->inicio;
        printf("\n\n----------------LISTA CONSOANTES----------------\n");
        while (aux!=NULL)
        {
            printf("Valor = %c\n",aux->valor);
            aux = aux->prox;
        }
        printf("\n----------------LISTA CONSOANTES----------------\n\n");
    }
}

lista *separa_vogais_consoantes(lista *la, lista *lb, lista *lc)
{
    registro *aux;

    if (la->inicio==NULL)
    {
        printf("\nLista A vazia\n");
        return 0;
    }
    
    aux=la->inicio;
    while (aux!=NULL)
    {
        if (aux->valor=='a'||aux->valor=='e'||aux->valor=='i'||aux->valor=='o'||aux->valor=='u'||aux->valor=='A'||aux->valor=='E'||aux->valor=='I'||aux->valor=='O'||aux->valor=='U')
        {
            registro *novo;
            novo = aloca_registro();
            novo->valor=aux->valor;
            if (lb->inicio==NULL)
            {
                lb->inicio=novo;
                lb->qtd++;
            }
            else
            {
                registro *aux2;
                aux2=lb->inicio;
                while (aux2!=NULL)
                {
                    if (aux2->prox==NULL)
                    {
                        aux2->prox=novo;
                        lb->qtd++;
                        aux2=aux2->prox;
                    }
                    aux2=aux2->prox;
                }
            }
        }
        else
        {
            registro *novo;
            novo = aloca_registro();
            novo->valor=aux->valor;
            if (lc->inicio==NULL)
            {
                lc->inicio=novo;
                lc->qtd++;
            }
            else
            {
                registro *aux2;
                aux2=lc->inicio;
                while (aux2!=NULL)
                {
                    if (aux2->prox==NULL)
                    {
                        aux2->prox=novo;
                        lc->qtd++;
                        aux2=aux2->prox;
                    }
                    aux2=aux2->prox;
                }
            }
        }
        aux=aux->prox;
    }
}