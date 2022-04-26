#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct sanduiche{
    char nome[30];
    float valor, peso, avaliacao;
}sanduiche;

void preenche (sanduiche * lista, int qtd_sanduiche);
void letra (sanduiche * lista, int qtd_sanduiche);
void avaliacao (sanduiche * lista, int qtd_sanduiche);
void peso_medio (sanduiche * lista, int qtd_sanduiche);
void tres_precos (sanduiche * lista, int qtd_sanduiche);

int main()
{
    sanduiche *lista;
    int qtd_sanduiche;
    printf("Insira a quantidade de sanduiches:");
    scanf("%d",&qtd_sanduiche);
    lista=(sanduiche*)malloc(sizeof(sanduiche)*qtd_sanduiche);

    preenche(lista,qtd_sanduiche);
    letra(lista,qtd_sanduiche);
    avaliacao(lista,qtd_sanduiche);
    peso_medio(lista,qtd_sanduiche);
    tres_precos(lista,qtd_sanduiche);
    
    return 0;
}

void preenche(sanduiche * lista, int qtd_sanduiche)
{
    for (int i = 0; i < qtd_sanduiche; i++)
    {
        printf("\n\nInsira o nome do sanduiche %d:",i+1);
        __fpurge(stdin);
        fgets(lista[i].nome,30,stdin);
        lista[i].nome[strlen(lista[i].nome)-1]='\0';
        printf("\nInsira o valor do sanduiche %d:",i+1);
        scanf("%f",&lista[i].valor);
        printf("\nInsira o peso do sanduiche %d:",i+1);
        scanf("%f",&lista[i].peso);
        printf("\nInsira a avaliacao do sanduiche %d:",i+1);
        scanf("%f",&lista[i].avaliacao);
    }
}

void letra (sanduiche * lista, int qtd_sanduiche)
{
    printf("\n------------------------------------------------------------------------");
    for (int i = 0; i < qtd_sanduiche; i++)
    {
        if (lista[i].nome[0]=='a' || lista[i].nome[0]=='A')
        {
            printf("\n\nO sanduiche '%s' começa com a letra A\n\n",lista[i].nome);
        }
    }
}

void avaliacao (sanduiche * lista, int qtd_sanduiche)
{
    int melhor=0, qual_melhor;
    for (int i = 0; i < qtd_sanduiche; i++)
    {
        if (lista[i].avaliacao > melhor)
        {
            melhor=lista[i].avaliacao;
            qual_melhor=i;
        }
    }
    printf("\nO sanduiche melhor avaliado é:%s\n\n",lista[qual_melhor].nome);
}

void peso_medio (sanduiche * lista, int qtd_sanduiche)
{
    int total=0;
    for (int i = 0; i < qtd_sanduiche; i++)
    {
        total=total+lista[i].peso;
    }
    printf("\nO peso medio dos sanduiches é:%d\n\n",total/qtd_sanduiche);
}

void tres_precos (sanduiche * lista, int qtd_sanduiche)
{
    for (int i = 0; i < qtd_sanduiche; i++)
    {
        int sanduiche_triplo=0;
        sanduiche_triplo=lista[i].valor*3;
        printf("\nO valor de 3 sanduiches %s é de:%d\n\n",lista[i].nome, sanduiche_triplo);
    }
}






