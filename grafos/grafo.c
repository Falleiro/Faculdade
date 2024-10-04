#include <stdio.h>
#include <stdlib.h>

typedef struct vertice{
    int visitado;
    struct lista *adj;
}vertice;

typedef struct lista{
    struct registro *inicio;
    struct registro *fim;
}lista;

typedef struct registro{
    int valor;
    struct registro *prox;
}registro;

void dfs(vertice *v, int raiz);
void inclui_adj(vertice *v, int valor);
void mostrar_lista(vertice *v, int i);

int main(){
    int qtd_vertice, qtd_aresta, a, b;

    scanf("%d %d", &qtd_vertice, &qtd_aresta);

    vertice *vertices;
    vertices = (vertice *)calloc(sizeof(vertice), qtd_vertice + 1);

    for (int i = 0; i < qtd_aresta; i++)
    {
        scanf("%d %d", &a, &b);
        inclui_adj(&vertices[a],b);
        inclui_adj(&vertices[b],a);
    }

    for (int i = 1; i <= qtd_vertice; i++)
    {
        if (vertices[i].visitado != 1)
        {
            dfs(vertices,i);
        }
    }

    for (int i = 1; i <= qtd_vertice; i++)
    {
        printf("\nLista do %d:", i);
        mostrar_lista(vertices,i);
    }
    
    return 0;
}

void dfs(vertice *v, int raiz){
    v[raiz].visitado = 1;
    
    if (v[raiz].adj != NULL)
    {
        registro *aux = v[raiz].adj->inicio;

        while (aux != NULL)
        {   
            if (v[aux->valor].visitado == 0)
            {
                dfs(v,aux->valor);
            }
            aux = aux->prox;
        }
    }
}

void inclui_adj(vertice *v, int valor){
    if (v->adj == NULL)
    {
        v->adj = (lista *)calloc(sizeof(lista),1);
    }
    registro *aux = (registro *)calloc(sizeof(registro),1);
    aux->valor = valor;

    if(v->adj->inicio==NULL){
        v->adj->inicio = aux;
        v->adj->fim = aux;
    }else{
        v->adj->fim->prox = aux;
        v->adj->fim = aux;
    }
    
}

void mostrar_lista(vertice *v, int i){
    if (v[i].adj == NULL)
    {
        return;
    }
    
    registro *aux = v[i].adj->inicio;

    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
}

