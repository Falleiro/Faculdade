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
    struct registro *prox;
    int valor;
}registro;

void inclui_adj(vertice *v, int valor);
void dfs(vertice *v, int raiz, int pai);
int main(){
    int qtd_vertice, qtd_aresta, a, b;
    scanf("%d %d", &qtd_vertice, &qtd_aresta);

    vertice *vertices = (vertice *)calloc(qtd_vertice + 1, sizeof(vertice));
    for (int i = 0; i < qtd_aresta; i++)
    {
        scanf("%d %d", &a, &b);
        inclui_adj(&vertices[a],b);
        inclui_adj(&vertices[b],a);
    }



    printf("Lista de Adjacencia:\n");
    for (int i = 1; i <= qtd_vertice; i++)
    {
        printf("%d: ", i);
        registro *aux = vertices[i].adj->inicio;
        if (vertices[i].adj != NULL)
        {
            while (aux != NULL)
            {
                printf("%d ", aux->valor);
                aux = aux->prox;
            }   
        }
        printf("\n");
    }
    for (int i = 1; i <= qtd_vertice; i++)
    {
        if (vertices[i].visitado == 0)
        {
            dfs(vertices, i, 0);
        }
    }
    
    
}

void dfs(vertice *v, int raiz, int pai){
    v[raiz].visitado = 1;

    if (v[raiz].adj != NULL)
    {
        registro *aux = v[raiz].adj->inicio;
        while (aux != NULL)
        {
            if (v[aux->valor].visitado == 0)
            {
                dfs(v, aux->valor, raiz);
            }else if(aux->valor != pai){
                printf("a aresta entre os vertices %d e %d é uma backedge\n", raiz, aux->valor);
            }
            
            aux = aux->prox;
        }   
    }
}

void inclui_adj(vertice *v, int valor){
    if (v->adj == NULL)
    {
        v->adj = (lista *)calloc(1,sizeof(lista));
    }
    registro *aux = (registro *)calloc(1,sizeof(registro));
    aux->valor = valor;
    if (v->adj->inicio==NULL)
    {
        v->adj->inicio = aux;
        v->adj->fim = aux;
    }else
    {
        v->adj->fim->prox = aux;
        v->adj->fim = aux;
    }
}